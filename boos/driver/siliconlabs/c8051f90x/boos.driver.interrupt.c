/** 
 * Target processor interrupts factory.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.interrupt.h" 
#include "boos.driver.registers.h"

/**
 * Returns the interrupt interface of a target processor.
 *
 * @return target processor interrupt interface.
 */
int32 interruptCreate() 
{
  return 0;      
}
  
/**
 * Initializes the driver.
 *
 * @param config a target processor configuration.
 * @return true if no errors have been occurred.
 */   
bool interruptInit()  
{
  return 1;
}

/**
 * Deinitializes the driver.
 */
void interruptDeinit()
{
}
