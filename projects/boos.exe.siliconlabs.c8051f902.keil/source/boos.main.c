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
  int8 res;
  interruptGlobalEnable(1);
  res = interruptCreate(&handler, 1);
  interruptGlobalDisable();  
  return 0;
}