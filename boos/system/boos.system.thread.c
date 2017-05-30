/** 
 * The operating system main class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#include "boos.system.thread.h"

/**
 * Causes the currently executing thread to sleep.
 *
 * @param millis a time to sleep in milliseconds.
 */  
void threadSleep(int16 millis)
{
  uint32 i, max, time;
  time = (uint16) millis;
  max = 0x167 * time;   
  for(i=0; i<max; i++){}
}