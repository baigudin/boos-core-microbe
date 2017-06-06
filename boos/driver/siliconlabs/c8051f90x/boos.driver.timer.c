/** 
 * Target processor timer driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.timer.h" 
#include "boos.driver.registers.h"
#include "boos.driver.constants.h"

/**
 * Number of possible resources.
 */
#define RES_NUMBER (2)

/**
 * The resource owner ID.
 */
#define RES_OWNER_ID (0x80)

/**
 * The resource owner mask.
 */
#define RES_OWNER_MASK (0x80)

/**
 * The resource index mask.
 */
#define RES_INDEX_MASK (0x01)

/**
 * Timer 0/1 clock in KHz.
 */  
#define TIMER_CLOCK_KHZ (TIMER_CLOCK / 1000)

/**
 * Locked flag of each resource.
 */
static int8 lock_[RES_NUMBER];

/**
 * The driver has been initialized successfully.
 */
static int8 isInitialized_;

/**
 * Tests if passed value is the resource.
 *
 * @param res an interrupt resource. 
 * @return true if the value if resource.
 */
static int8 isAlloced(int8 res)
{
  int8 ret, index;
  ret = 0;
  if(isInitialized_)
  {
    do{
      if( res == 0 ) { break; }    
      if( res & RES_OWNER_MASK != RES_OWNER_MASK ) { break; }
      index = res & RES_INDEX_MASK;  
      if( index < 0 || RES_NUMBER <= index ) { break; }
      if( lock_[index] == 0 ) { break; }
      ret = 1;    
    }while(0);
  }
  return ret;
}

/**
 * Returns an timer resource.
 *
 * @param index an available timer index.
 * @return the timer resource, or zero if error has been occurred.
 */
int8 timerCreate(int8 index)
{
  int8 res;
  uint8 mask, shift;  
  res = 0;
  if( 0 <= index && index < RES_NUMBER )
  {
    do{
      if(lock_[index] == 1){ break; }
      shift = index * 4;
      /* Zero the HW timer registers */
      mask = 0x0f << shift;
      REG_TMOD &= ~mask;
      mask = 0x33 << shift;      
      REG_TCON &= ~mask;
      /* Set 8-bit auto-reload timer mode */
      REG_TMOD |= 0x02 << shift;
      /* Alloc the timer */      
      lock_[index] = 1;      
      res = index & RES_INDEX_MASK | RES_OWNER_ID;
    }while(0);
  }
  return res;  
}

/**
 * Removes the timer resource.
 *
 * @param res the timer resource.
 */
void timerRemove(int8 res)
{
  int8 index;
  if( isAlloced(res) )
  {
    index = res & RES_INDEX_MASK;    
    lock_[index] = 0;
  }
}

/**
 * Sets the timer period.
 *
 * @param res  the timer resource.
 * @param time timer period in microseconds, zero value sets a period to maximum value.
 */      
void timerSetPeriod(int8 res, int16 us)
{
  int8 index;
  uint8 reg;
  uint32 time, value;
  if( us >= 0 && isAlloced(res) )
  {
    index = res & RES_INDEX_MASK;    
    if(us == 0)
    {
      reg = 0x00;
    }
    else
    {
      time = us;
      value = time * TIMER_CLOCK_KHZ;
      value = value / 1000;
      /* If overflow has been occurred, set max value */
      if(value >> 8 > 0)
      {
        reg = 0x00;
      }
      /* Set desired value */
      else
      {
        reg = value & 0xff;
        reg = 0 - reg;
      } 
    }
    switch(index)
    {
      case 0:
      {
        /* Set up counter */
        REG_TL0 = reg;
        /* Set period */        
        REG_TH0 = reg;        
      }
      break;
      case 1:
      {
        /* Set up counter */
        REG_TL1 = reg;
        /* Set period */        
        REG_TH1 = reg;                
      }
      break;
      default: break;
    }
  }  
}

/**
 * Starts the timer count.
 *
 * @param res the timer resource.
 */      
void timerStart(int8 res)
{
  int8 index;
  if( isAlloced(res) )
  {
    index = res & RES_INDEX_MASK;    
    REG_TCON |= 0x1 << (index * 2 + 4);
  }  
}

/**
 * Stops the timer count.
 *
 * @param res the timer resource.
 */      
void timerStop(int8 res)
{
  int8 index;
  if( isAlloced(res) )
  {
    index = res & RES_INDEX_MASK;    
    REG_TCON &= ~(0x1 << (index * 2 + 4));
  }    
}
 
/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 timerInit(void)  
{
  #ifdef BOOS_RESTARTING
  int8 i;
  #endif /* BOOS_RESTARTING */
  int8 error;
  isInitialized_ = 0;   
  #if TIMER_DIVIDER == 48
  REG_CKCON &= 0xf0;
  REG_CKCON |= 0x02;
  error = BOOS_OK;  
  #elif TIMER_DIVIDER == 12
  REG_CKCON &= 0xf0;
  REG_CKCON |= 0x00;
  error = BOOS_OK;  
  #elif TIMER_DIVIDER == 8
  REG_CKCON &= 0xf0;
  REG_CKCON |= 0x03;
  error = BOOS_OK;  
  #elif TIMER_DIVIDER == 4
  REG_CKCON &= 0xf0;
  REG_CKCON |= 0x01;
  error = BOOS_OK;
  #elif TIMER_DIVIDER == 1
  REG_CKCON &= 0xf0;
  REG_CKCON |= 0x0c;
  error = BOOS_OK;  
  #else
  error = BOOS_ERROR;
  #endif
  #ifdef BOOS_RESTARTING
  for(i=0; i<RES_NUMBER; i++)
  {
    lock_[i] = 0;
  }
  #endif /* BOOS_RESTARTING */  
  if(error == BOOS_OK)
  {
    isInitialized_ = 1;  
  }  
  return error;
}

