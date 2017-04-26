/** 
 * The operating system main class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.main.h" 
#include "boos.driver.processor.h"

/**
 * The function which will be stated first.
 * 
 * @return error code or zero.
 */   
static int32 systemMain()
{
  int8 stage;
  int32 error;
  stage = 0;
  do{
    // Stage 1 
    stage++;
    if( !processorInit() ) break;    
    // Stage complete
    stage = -1;
    error = userMain();
  }while(0);
  switch(stage)
  {
    default:
    case  1: processorDeinit();
    case  0: break;
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
#ifdef BOOS_VENDOR_BOOT
int main()
{
  return systemMain() & 0x0000ffff;
}
#endif // BOOS_VENDOR_BOOT
