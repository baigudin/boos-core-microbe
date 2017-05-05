/** 
 * Target processor timer driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.timer.h" 
#include "boos.driver.registers.h"

/**
 * Number of possible resources.
 */
#define RESOURCES_NUMBER 2

/**
 * Timer resource index mask.
 */
#define RES_INDEX_MASK 0x3

/**
 * Locked flag of each HW timer.  
 */
static int8 lock_[RESOURCES_NUMBER];

/**
 * Tests if value passed is the resource.
 *
 * @param res an interrupt resource. 
 * @return true if the value if resource.
 */
static int8 isAlloced(int8 res)
{
  int8 ret, index;
  ret = 0;
  do{
    if( res == 0 ) { break; }    
    index = res & RES_INDEX_MASK;  
    if( index < 0 || RESOURCES_NUMBER <= index ) { break; }
    if( lock_[index] == 0 ) { break; }
    ret = 1;    
  }while(0);
  return ret;
}

/**
 * Returns an timer resource.
 *
 * @param index an available timer index.
 * @return the timer resource, or zero if error has been occurred.
 */
int8 timerCreate(int8 index)
{
  int8 res = 0;
  if( 0 <= index && index < RESOURCES_NUMBER )
  {
    lock_[index] = 1;
    res = index & RES_INDEX_MASK | 0x80;
  }
  return res;  
}

/**
 * Removes the timer resource.
 *
 * @param res the timer resource.
 */
void timerRemove(int8 res)
{
  int8 index;
  if( isAlloced(res) )
  {
    index = res & RES_INDEX_MASK;    
    lock_[index] = 0;
  }
}
 
/**
 * Initializes the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 timerInit(void)  
{
  #ifdef BOOS_RESTARTING
  for(int8 i=0; i<RESOURCES_NUMBER; i++)
  {
    lock_[i] = 0;
  }
  #endif /* BOOS_RESTARTING */  
  return BOOS_OK;
}

