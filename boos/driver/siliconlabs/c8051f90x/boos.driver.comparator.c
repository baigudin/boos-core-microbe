/** 
 * Target processor interrupts driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.driver.comparator.h" 
#include "boos.driver.registers.h"
#include "boos.driver.constants.h"

/**
 * Number of possible resources.
 */
#define RES_NUMBER (2)

/**
 * The resource owner ID.
 */
#define RES_OWNER_ID (0x80)

/**
 * The resource owner mask.
 */
#define RES_OWNER_MASK (0x80)

/**
 * The resource index mask.
 */
#define RES_INDEX_MASK (0x01)

/**
 * Comparator contex.
 */
typedef struct _Comparator
{
  /**
   * Comparator interrupt resource.
   */
  int8 intRes;

} Comparator;

/**
 * Comparator resource contex.
 */
static Comparator comparator_[RES_NUMBER];

/**
 * Locked flag of each resource.  
 */
static int8 lock_[RES_NUMBER];

/**
 * The driver has been initialized successfully.
 */
static int8 isInitialized_;

/**
 * Tests if passed value is the resource.
 *
 * @param res an interrupt resource. 
 * @return true if the value if resource.
 */
static int8 isAlloced(int8 res)
{
  int8 ret, index;
  ret = 0;
  if(isInitialized_)
  {
    do{
      if( res == 0 ) { break; }    
      if( res & RES_OWNER_MASK != RES_OWNER_MASK ) { break; }          
      index = res & RES_INDEX_MASK;  
      if( index < 0 || RES_NUMBER <= index ) { break; }
      if( lock_[index] == 0 ) { break; }
      ret = 1;    
    }while(0);
  }
  return ret;
}

/**
 * Returns an comparator resource.
 *
 * @param index available comparator index.
 * @return the comparator resource, or zero if error has been occurred.
 */
int8 comparatorCreate(int8 index)
{
  int8 res;
  res = 0;
  if( 0 <= index && index < RES_NUMBER )
  {
    do{
      if(lock_[index] == 1)
      { 
        break; 
      }
      /* Alloc the resource */      
      lock_[index] = 1;      
      res = index & RES_INDEX_MASK | RES_OWNER_ID;
    }while(0);
  }
  return res;
}

/**
 * Removes the comparator resource.
 *
 * @param res the comparator resource.
 */
void comparatorRemove(int8 res)
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
int8 comparatorInit(void)  
{  
  #ifdef BOOS_RESTARTING
  int8 i;
  #endif /* BOOS_RESTARTING */  
  isInitialized_ = 0;   
  #ifdef BOOS_RESTARTING
  for(i=0; i<RES_NUMBER; i++)
  {
    lock_[i] = 0;
    comparator_[i].intRes = 0;
  }
  /* Disable the comparators */
  REG_CPT0CN = 0x0;
  REG_CPT1CN = 0x0;
  #endif /* BOOS_RESTARTING */
  isInitialized_ = 1;  
  return BOOS_OK;
}
