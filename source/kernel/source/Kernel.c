/** 
 * The operating system main class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Program.h"
#include "Board.h"
#include "Cpu.h"
#include "CpuInterrupt.h"

/**
 * Initializes the operating system.
 * 
 * @return error code or else zero if no errors have been occurred.
 */
static int8 kernelInitialize(void)
{
    int8 error = SYS_OK;
    int8 stage = 1;
    switch(stage)
    {
        /* Stage 1 */            
        case 1:
            error = Cpu_initialize();
            if(error != SYS_OK)
            { 
                break; 
            }
            stage++;
            
        /* Stage 2 */
        case 2:
            error = Board_initialize();
            if(error != SYS_OK)
            {
                break; 
            }  
            stage++;
            
        /* Stage 3: call user program */            
        case 3:
            CpuInterrupt_enableAll(1);
            error = Program_start();
            CpuInterrupt_disableAll();
            if(error != SYS_OK)
            {
                break;
            }
            stage++;        
            
        /* Stage complete */            
        case 4:
            stage = 0;
            break;
            
        /* Stage error */
        default:
            error = SYS_ERROR;            
            stage = -1;
            break;
    }
    if(stage != 0 && error == SYS_OK)
    {
        error = SYS_ERROR;
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
    return kernelInitialize();
}
