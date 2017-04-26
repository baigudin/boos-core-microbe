/** 
 * Target processor factory. 
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.processor.h" 
#include "boos.driver.interrupt.h"
  
/**
 * Initializes the driver.
 *
 * @param config a target processor configuration.
 * @return true if no errors have been occurred.
 */   
bool processorInit()
{
  int8 stage;
  int32 error;
  stage = 0;
  do{
    // Stage 1 
    stage++;
    if( !interruptInit() ) break;    
    // Stage complete
    stage = -1;
  }while(0);
  switch(stage)
  {
    default:
    case  1: interruptDeinit();
    case  0: break;
  }
  return error;
}

/**
 * Deinitializes the driver.
 */
void processorDeinit()
{
}
