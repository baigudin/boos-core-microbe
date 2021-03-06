/** 
 * Silicon Labs C8051F9x MCUs interrupt driver.  
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "CpuInterrupt.h" 
#include "CpuRegisters.h"

/**
 * Number of possible resources.
 */
#define RES_NUMBER (19)

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
#define RES_INDEX_MASK (0x1f)

/**
 * An interrupted program context.
 */
struct Context
{
    uint8 rn7;  
    uint8 acc;  
    uint8 b;
    uint8 dph;  
    uint8 dpl;    
    uint8 psw;   
    uint8 rn6;
    uint8 rn5;
    uint8 rn4;
    uint8 rn3;
    uint8 rn2;
    uint8 rn1;
    uint8 rn0;  
};

/**
 * Interrupted handler data.
 */
struct Handler
{
    /**
     * An interrupt handler function address.
     */
    void(*addr)();
};

/**
 * Context of interrupted program by interrupt.
 */
static struct Context context_;

/**
 * Interrupted handler data.
 */
static struct Handler handler_[RES_NUMBER];

/**
 * The driver has been plugged successfully.
 */
static int8 isPlugged_;

/**
 * Tests if passed value is the resource.
 *
 * @param res - an interrupt resource. 
 * @return true if the value is a resource.
 */
static int8 isAlloced(int8 res)
{
    int8 index;
    int8 ret = 0;
    if(isPlugged_)
    {  
        if( res != 0 ) 
        {
            if( (res & RES_OWNER_MASK) == RES_OWNER_MASK ) 
            {
                index = res & RES_INDEX_MASK;
                if( index >= 0 ) 
                {
                    if( index < RES_NUMBER )
                    {
                        if( handler_[index].addr != 0 )
                        {
                            ret = 1;                            
                        }
                    }
                }
            }
        }
    }
    return ret;
}

/**
 * Handles HW interrupt.
 *
 * MISRA-C:2004 justification: the violation of Rule 8.10 and 8.11 cannot be eliminated, 
 * because the function must have the external link and is called by assembly language.
 *
 * @param index - index of HW interrupt vector
 */ 
void CpuInterrupt_handle(uint8 index)
{
    if( index < RES_NUMBER && handler_[index].addr != 0 )
    {
        handler_[index].addr();
    }
}

/**
 * Returns an interrupt resource.
 *
 * @param handler - an interrupt handler function.
 * @param source - an available interrupt source number.
 * @return the interrupt resource, or zero if error has been occurred.
 */
int8 CpuInterrupt_create(void(*handler)(), int8 source)
{
    int8 res = 0;
    if( 0 <= source && source < RES_NUMBER 
        /* TODO: RTC0CN.2 bit is not being cleared by ISR. 
           The source is locked till the ISR will do clearing of the bit */    
        && source != 8 
        /* TODO: ADC0STA.5 bit is not being cleared by ISR. 
           The source is locked till the ISR will do clearing of the bit */    
        && source != 10   
        /* TODO: PCA0CN.n bits are not being cleared by ISR. 
           The source is locked till the ISR will do clearing of the bits */    
        && source != 11
        /* TODO: VDM0CN.5 and VDM0CN.4 bits are not being cleared by ISR. 
           The source is locked till the ISR will do clearing of the bits */    
        && source != 15
        /* TODO: RTC0CN.5 bit is not being cleared by ISR. 
           The source is locked till the ISR will do clearing of the bit */    
        && source != 17
        /* TODO: SPI1CN.7-4 bits are not being cleared by ISR. 
           The source is locked till the ISR will do clearing of the bits */      
        && source != 18)
    {
        handler_[source].addr = handler;
        res = source & RES_INDEX_MASK | RES_OWNER_ID;
    }
    return res;
}

/**
 * Deletes the interrupt resource.
 *
 * @param res - the interrupt resource.
 */
void CpuInterrupt_delete(int8 res)
{
    int8 vec;
    if( isAlloced(res) )
    {
        CpuInterrupt_disable(res);
        vec = res & RES_INDEX_MASK;    
        handler_[vec].addr = 0;
    }
}

/**
 * Locks the interrupt source.
 *
 * @param res - the interrupt resource. 
 * @return an interrupt enable source bit value before function was called.
 */    
int8 CpuInterrupt_disable(int8 res)
{
    int8 ret, vec;
    uint8 val;
    if( isAlloced(res) )
    {
        vec = res & RES_INDEX_MASK;
        if(0 <= vec && vec < 7)
        {
            val = 0x01 << vec;
            ret = REG_IE & val ? 1 : 0;
            REG_IE &= ~val;
        }
        else if(7 <= vec && vec < 15)
        {
            val = 0x01 << (vec - 7);   
            ret = REG_EIE1 & val ? 1 : 0;
            REG_EIE1 &= ~val;
        }    
        else if(15 <= vec && vec < RES_NUMBER)
        {
            val = 0x01 << (vec - 7);   
            ret = REG_EIE2 & val ? 1 : 0;
            REG_EIE2 &= ~val;      
        }
        else
        {
            ret = 0;
        }
    }    
    return ret;
}
    
/**
 * Unlocks this interrupt source.
 *
 * @param res - the interrupt resource. 
 * @param status - status returned by lock function.
 */
void CpuInterrupt_enable(int8 res, int8 status)
{
    int8 vec;
    uint8 val;
    if( status != 0 && isAlloced(res) )
    {
        vec = res & RES_INDEX_MASK;
        if(0 <= vec && vec < 7)
        {
            val = 0x01 << vec;
            REG_IE |= val;
        }
        else if(7 <= vec && vec < 15)
        {
            val = 0x01 << (vec - 7);      
            REG_EIE1 |= val;      
        }    
        else if(15 <= vec && vec < RES_NUMBER)
        {
            val = 0x01 << (vec - 15);      
            REG_EIE2 |= val;            
        }
        else
        {
        }
    }   
}

/**
 * Tests if this interrupt source can be polarized.
 *
 * @param res - the interrupt resource.  
 * @return true if this source is polarizing.
 */  
int8 CpuInterrupt_isPolarized(int8 res)
{
    int8 ret;
    if( isAlloced(res) )
    {
        switch(res & RES_INDEX_MASK)
        {
            case 0:      
            case 2:        
            {
                ret = 1;        
            }
            break;
            default:
            {
                ret = 0;
            }
            break;
        }
    }
    else  
    {
        ret = 0;
    }
    return ret;
}

/**
 * Disables all maskable interrupts.
 *
 * @return global interrupts enable bit value before function was called.
 */
int8 CpuInterrupt_disableAll(void)
{
    int8 reg = REG_IE & 0x80;
    REG_IE_BIT_EA = 0;
    return reg == 0 ? 0 : 1;
}

/**
 * Enables all maskable interrupts.
 *
 * The true passed argument directly turns all maskable interrupts on, 
 * and the false does nothing, the interrupts stay in the current state.     
 *
 * @param status - the returned status by disable function.
 */
void CpuInterrupt_enableAll(int8 status)
{
    if(status != 0) 
    { 
        REG_IE_BIT_EA = 1; 
    }
}

/**
 * Plugs the driver.
 *
 * @return error code or else zero if no errors have been occurred.
 */   
int8 CpuInterrupt_plug(void)
{
    isPlugged_ = 0;  
    #ifdef BOOS_RESTARTING
    /* Disable all interrupts */
    REG_IE = 0;
    REG_EIE1 = 0;
    REG_EIE2 = 0;
    /* Set default interrupt priority levels */
    REG_IP = 0;
    REG_EIP1 = 0;
    REG_EIP2 = 0;
    #endif /* BOOS_RESTARTING */
    isPlugged_ = 1;  
    return ERROR_OK;
}
