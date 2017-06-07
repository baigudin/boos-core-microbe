/** 
 * Target processor interrupts driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.comparator.h" 
#include "boos.driver.interrupt.h" 
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
 * Comparator interrupt handlers.
 */  
typedef struct _Handler
{
  /**
   * The driver interrupt handler.
   */  
  void(*drv)();
  
  /**
   * External interrupt handler.
   */  
  void(*ext)();  
  
} Handler;

/**
 * Comparator interrupt data.
 */  
typedef struct _Interrupt
{
  /**
   * The driver interrupt resource.
   */  
  int8 res;  
  
  /**
   * The driver interrupt source.
   */  
  int8 source;
 
} Interrupt; 

/**
 * Comparator contex.
 */
typedef struct _Comparator
{
  /**
   * Resource locked flag.  
   */
  int8 lock;

  /**
   * Comparator interrupt handlers.
   */  
  Handler handler;  

  /**
   * Comparator interrupt data.
   */  
  Interrupt inter;    

} Comparator;

/**
 * Comparator resource contex.
 */
static Comparator cmp_[RES_NUMBER];

/**
 * The driver has been initialized successfully.
 */
static int8 isInitialized_;

/**
 * Tests if passed value is the resource.
 *
 * @param res an interrupt resource. 
 * @return the resource index, or -1 if the resource is wrong.
 */
static int8 getIndex(int8 res)
{
  int8 index, i;
  index = -1;
  if(isInitialized_)
  {
    do{
      if( res == 0 ) { break; }    
      if( res & RES_OWNER_MASK != RES_OWNER_MASK ) { break; }          
      i = res & RES_INDEX_MASK;  
      if( i < 0 || RES_NUMBER <= i ) { break; }
      if( cmp_[i].lock == 0 ) { break; }
      index = i;
    }while(0);
  }
  return index;
}

/**
 * Interrupt handler of comparator 0.
 */
static void handler0(void)
{
  if(cmp_[0].handler.ext != 0)
  {
    cmp_[0].handler.ext();
  }
}

/**
 * Interrupt handler of comparator 1.
 */
static void handler1(void)
{
  if(cmp_[1].handler.ext != 0)
  {  
    cmp_[1].handler.ext();  
  }
}

/**
 * Returns an comparator resource.
 *
 * @param handler an interrupt handler function. 
 * @param index   an available comparator index.
 * @return the comparator resource, or zero if error has been occurred.
 */
int8 comparatorCreate(void(*handler)(), int8 index)
{
  int8 res = 0;  
  int8 error = BOOS_OK;  
  if( 0 <= index && index < RES_NUMBER && cmp_[index].lock == 0 )
  {
    do{
      /* Set HW registers */      
      switch(index)
      {
        case 0:
        {
          REG_CPT0CN = 0x1 << 7  /* Comparator Enabled */
                     | 0x0 << 5  /* Comparator Rising Edge has not occurred */
                     | 0x0 << 4  /* Comparator Falling-Edge has not occurred */
                     | 0x3 << 2  /* Positive Hysteresis */
                     | 0x3 << 0; /* Negative Hysteresis */
          
          REG_CPT0MD = 0x1 << 7  /* Must Write 1b */
                     | 0x1 << 5  /* Comparator Rising-edge interrupt enabled */
                     | 0x1 << 4  /* Comparator Falling-edge interrupt enabled */
                     | 0x0 << 0; /* Fastest Response Time, Highest Power Consumption */
          
          REG_CPT0MX = 0xf << 4  /* Negative Input is Ground */
                     | 0xf << 0; /* Positive Input is VDD/DC+ Supply Voltage */
        }
        break;          
        case 1:
        {
          REG_CPT1CN = 0x1 << 7  /* Comparator Enabled */
                     | 0x0 << 5  /* Comparator Rising Edge has not occurred */
                     | 0x0 << 4  /* Comparator Falling-Edge has not occurred */
                     | 0x3 << 2  /* Positive Hysteresis */
                     | 0x3 << 0; /* Negative Hysteresis */
          
          REG_CPT1MD = 0x1 << 7  /* Must Write 1b */
                     | 0x1 << 5  /* Comparator Rising-edge interrupt enabled */
                     | 0x1 << 4  /* Comparator Falling-edge interrupt enabled */
                     | 0x0 << 0; /* Fastest Response Time, Highest Power Consumption */
          
          REG_CPT1MX = 0xf << 4  /* Negative Input is Ground */
                     | 0xf << 0; /* Positive Input is VDD/DC+ Supply Voltage */          
        }
        break;
      }
      cmp_[index].inter.res = interruptCreate(cmp_[index].handler.drv, cmp_[index].inter.source);
      if(cmp_[index].inter.res == 0)
      {
        break;
      }
      cmp_[index].handler.ext = handler;
      cmp_[index].lock = 1;
      res = index & RES_INDEX_MASK | RES_OWNER_ID;
    }while(0);
  }
  return res;
}

/**
 * Removes the comparator resource.
 *
 * @param res the comparator resource.
 */
void comparatorRemove(int8 res)
{
  int8 index = getIndex(res);
  if( index != -1 )
  {
    switch(index)
    {
      case 0:
      {
        REG_CPT0CN = 0x1 << 7  /* Comparator Disabled */
                   | 0x0 << 5  /* Comparator Rising Edge has not occurred */
                   | 0x0 << 4  /* Comparator Falling-Edge has not occurred */
                   | 0x0 << 2  /* Positive Hysteresis Disabled */
                   | 0x0 << 0; /* Negative Hysteresis Disabled */
      }
      break;          
      case 1:
      {
        REG_CPT1CN = 0x0 << 7  /* Comparator Disabled */
                   | 0x0 << 5  /* Comparator Rising Edge has not occurred */
                   | 0x0 << 4  /* Comparator Falling-Edge has not occurred */
                   | 0x0 << 2  /* Positive Hysteresis Disabled */
                   | 0x0 << 0; /* Negative Hysteresis Disabled */
      }
      break;
    }
    interruptRemove(cmp_[index].inter.res);
    cmp_[index].handler.ext = 0;    
    cmp_[index].inter.res = 0;
    cmp_[index].lock = 0;
  }  
}

/**
 * Selects the comparator input channels.
 *
 * @param res the comparator resource.
 * @param neg a negative input channel value.
 * @param pos a positive input channel value.
 */
void comparatorSetInput(int8 res, int8 neg, int8 pos)
{
  int8 index = getIndex(res);
  if( index != -1 )
  {
    switch(index)
    {
      case 0:
      {
        REG_CPT0MX = (neg & 0xf) << 4  /* Negative Input is Ground */
                   | (pos & 0xf) << 0; /* Positive Input is VDD/DC+ Supply Voltage */
      }
      break;          
      case 1:
      {
        REG_CPT1MX = (neg & 0xf) << 4  /* Negative Input is Ground */
                   | (pos & 0xf) << 0; /* Positive Input is VDD/DC+ Supply Voltage */
      }
      break;
    }    
  }  
}

/**
 * Locks the comparator interrupt source.
 *
 * @param res the comparator resource. 
 * @return an interrupt enable source bit value before function was called.
 */    
int8 comparatorIntDisable(int8 res)
{
  int8 is;
  int8 index = getIndex(res);
  if(index != -1)
  {
    is = interruptDisable(cmp_[index].inter.res);
  }    
  else
  {
    is = 0;
  }
  return is;
}
    
/**
 * Unlocks the comparator interrupt source.
 *
 * @param res    the comparator resource. 
 * @param status status returned by lock function.
 */
void comparatorIntEnable(int8 res, int8 status)
{
  int8 index = getIndex(res);
  if(index != -1)
  {
    interruptEnable(cmp_[index].inter.res, status);
  }    
}

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */
int8 comparatorInit(void)  
{  
  #ifdef BOOS_RESTARTING
  int8 i;
  #endif /* BOOS_RESTARTING */  
  isInitialized_ = 0;   
  #ifdef BOOS_RESTARTING
  for(i=0; i<RES_NUMBER; i++)
  {
    cmp_[i].lock = 0;
    cmp_[i].inter.res = 0;
    cmp_[i].handler.ext = 0;
    switch(i)
    {
      case 0:
      {
        cmp_[i].handler.drv = handler0;            
        cmp_[i].inter.source = 12;
      }
      break;      
      case 1:
      {
        cmp_[i].handler.drv = handler1;            
        cmp_[i].inter.source = 13;        
      }
      break;
      default: 
      {
        break;
      }
    }
    
  }
  /* Disable the comparators */
  REG_CPT0CN = 0x0;
  REG_CPT1CN = 0x0;
  #endif /* BOOS_RESTARTING */
  isInitialized_ = 1;  
  return BOOS_OK;
}
