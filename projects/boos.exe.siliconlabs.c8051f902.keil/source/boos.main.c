/** 
 * User program entry.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.main.h"
#include "boos.driver.interrupt.h"
#include "boos.driver.timer.h"

/**
 * Interrupt handler.
 */
void handler()
{
  
}

/**
 * User program entry.
 *
 * @return error code or zero.
 */
int8 userMain()
{
  int8 iRes, tRes;
  volatile int8 exe = 1;
  volatile int8 val = 0;  
  interruptGlobalEnable(1);
  /* Create Timer 0 interrupt resource */
  iRes = interruptCreate(&handler, 1);
  interruptEnable(iRes, 1);
  /* Create Timer 0 resource */
  tRes = timerCreate(0);
  timerSetPeriod(tRes, 500);  
  timerStart(tRes);  
  /* Waiting*/
  while(exe)
  {
    val++;
  };
  timerStop(tRes);    
  /* Remove allocated resources */
  timerRemove(tRes);
  interruptDisable(iRes);  
  interruptRemove(iRes);    
  interruptGlobalDisable();  
  return 0;
}