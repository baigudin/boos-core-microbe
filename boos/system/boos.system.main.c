/** 
 * The operating system main class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.main.h"
#include "boos.board.h"
#include "boos.driver.processor.h"
#include "boos.driver.interrupt.h"

/**
 * Initializes the operating system.
 * 
 * @return error code or else zero if no errors have been occurred.
 */
static int8 systemInit(void)
{
  int8 error = BOOS_OK;
  do{
    /* Stage 1 */
    error = processorInit();
    if(error != BOOS_OK){ break; }
    /* Stage 2 */
    error = boardInit();
    if(error != BOOS_OK){ break; }    
    /* Stage complete */
  }while(0);
  /* Call user main function */
  if(error == BOOS_OK)
  {
    interruptGlobalEnable(1);  
    error = mainStart();
    interruptGlobalDisable();    
  }
  return error;
}

/**
 * The main function.
 * 
 * The method should be called after default boot initialization, and
 * the following tasks must be:
 * 1. Stack has been set.
 * 2. CPU registers have been set.
 * 3. Run-time initialization has been completed.
 * 4. Global variables have been set.
 * 5. Global constructors have been ñalled.
 * 
 * @return error code or zero.
 */   
int16 main(void)
{
  return systemInit();
}
