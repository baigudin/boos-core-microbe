/** 
 * Target processor interrupts driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.interrupt.h" 
#include "boos.driver.registers.h"

/**
 * Number of possible resources.
 */
#define RESOURCES_NUMBER 7

/**
 * Number of possible interrupt resources.
 */
#define VECTORS_NUMBER 19

/**
 * Interrupt resource source mask.
 */
#define RES_SOURCE_MASK 0x1f

/**
 * Context of interrupted program by interrupt.
 */
typedef struct _Context{
  int8 rn[8];
  int8 ac;
  int8 b;
  int8 psw;
} Context;

/**
 * Interrupted handler data.
 */
typedef struct _Handler{
  void(*addr)();
} Handler;

/**
 * Context of interrupted program by interrupt.
 */
static Context context_;

/**
 * Interrupted handler data.
 */
static Handler handler_[VECTORS_NUMBER];

/**
 * Tests if value passed is the resource.
 *
 * @param res an interrupt resource. 
 * @return true if the value if resource.
 */
static int8 isAlloced(int8 res)
{
  int8 ret, vec;
  ret = 0;
  do{
    if( res == 0 ) { break; }    
    vec = res & RES_SOURCE_MASK;  
    if( vec < 0 || VECTORS_NUMBER <= vec ) { break; }
    if( handler_[vec].addr == 0 ) { break; }
    ret = 1;    
  }while(0);
  return ret;
}

/**
 * Returns an interrupt resource.
 *
 * @param handler an interrupt handler function.
 * @param source an available interrupt source number.
 * @return the interrupt resource, or zero if error has been occurred.
 */
int8 interruptCreate(void(*handler)(), int8 source)
{
  int8 res = 0;
  if( 0 <= source && source < VECTORS_NUMBER )
  {
    handler_[source].addr = handler;
    res = source & RES_SOURCE_MASK | 0x80;
  }
  return res;
}

/**
 * Removes the interrupt resource.
 *
 * @param res the interrupt resource, or zero if error has been occurred.
 */
void interruptRemove(int8 res)
{
  int8 vec;
  if( isAlloced(res) )
  {
    interruptDisable(res);
    vec = res & RES_SOURCE_MASK;    
    handler_[vec].addr = 0;
  }
}

/**
 * Locks the interrupt source.
 *
 * @param res the interrupt resource. 
 * @return an interrupt enable source bit value before function was called.
 */    
int8 interruptDisable(int8 res)
{
  int8 ret, vec;
  uint8 val;
  if( isAlloced(res) )
  {
    vec = res & RES_SOURCE_MASK;
    if(0 <= vec && vec < 7)
    {
      val = 0x01 << vec;
      ret = REG_IE & val ? 1 : 0;
      REG_IE &= ~val;
    }
    else if(7 <= vec && vec < 15)
    {
      val = 0x01 << (vec - 7);   
      ret = REG_EIE1 & val ? 1 : 0;
      REG_EIE1 &= ~val;
    }    
    else if(15 <= vec && vec < VECTORS_NUMBER)
    {
      val = 0x01 << (vec - 7);   
      ret = REG_EIE2 & val ? 1 : 0;
      REG_EIE2 &= ~val;      
    }
  }    
  return ret;
}
    
/**
 * Unlocks this interrupt source.
 *
 * @param res    the interrupt resource. 
 * @param status status returned by lock function.
 */
void interruptEnable(int8 res, int8 status)
{
  int8 vec;
  uint8 val;
  if( status != 0 && isAlloced(res) )
  {
    vec = res & RES_SOURCE_MASK;
    if(0 <= vec && vec < 7)
    {
      val = 0x01 << vec;
      REG_IE |= val;
    }
    else if(7 <= vec && vec < 15)
    {
      val = 0x01 << (vec - 7);      
      REG_EIE1 |= val;      
    }    
    else if(15 <= vec && vec < VECTORS_NUMBER)
    {
      val = 0x01 << (vec - 15);      
      REG_EIE2 |= val;            
    }
  }   
}

/**
 * Disables all maskable interrupts.
 *
 * @return global interrupts enable bit value before function was called.
 */
int8 interruptGlobalDisable(void)
{
  int8 reg = REG_IE & 0x80;
  REG_IE_BIT_EA = 0;
  return reg == 0 ? 0 : 1;
}

/**
 * Enables all maskable interrupts.
 *
 * The true passed argument directly turns all maskable interrupts on, 
 * and the false does nothing, the interrupts stay in the current state.     
 *
 * @param status the returned status by disable function.
 */
void interruptGlobalEnable(int8 status)
{
  if(status != 0) { REG_IE_BIT_EA = 1; }
}

/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 interruptInit(void)  
{
  #ifdef BOOS_RESTARTING
  /* Disable all interrupts */
  REG_IE = 0;
  REG_EIE1 = 0;
  REG_EIE2 = 0;
  /* Set default interrupt priority levels */
  REG_IP = 0;
  REG_EIP1 = 0;
  REG_EIP2 = 0;
  #endif /* BOOS_RESTARTING */
  return BOOS_OK;
}
