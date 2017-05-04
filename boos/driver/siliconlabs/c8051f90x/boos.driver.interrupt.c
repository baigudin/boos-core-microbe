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
 * Number of possible interrupt resources.
 */
#define INTERRUPT_RESOURCES_NUMBER 7

/**
 * Number of possible interrupt resources.
 */
#define INTERRUPT_VECTORS_NUMBER 19

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
static Handler handler_[INTERRUPT_VECTORS_NUMBER];

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
  if( 0 <= source && source < INTERRUPT_VECTORS_NUMBER )
  {
    handler_[source].addr = handler;
    res = source & 0x1f;
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
  int8 source = res & 0x1f;
  if( 0 <= source && source < INTERRUPT_VECTORS_NUMBER )
  {
    handler_[source].addr = 0;
  }
}

/**
 * Disables all maskable interrupts.
 *
 * @return global interrupts enable bit value before method was called.
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
 * @param status the returned status by disable method.
 */
void interruptGlobalEnable(int8 status)
{
  if(status != 0) REG_IE_BIT_EA = 1;
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
