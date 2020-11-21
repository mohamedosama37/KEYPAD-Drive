/********************************************************/
/* Author  :Dunga                                       */
/* Version :VO1.1                                       */
/* Data    :8 July 2019                                 */
/********************************************************/
/********************************************************/
/* Description                                          */
/* -----------                                          */
/* Program file for Key Pad Driver for AVR 32           */
/********************************************************/
#include "STD_TYPES.h"
#include "KDB_interface.h"
#include "util/delay.h"

#define F_CPU 12000000

/***************************************************************************************/

/************* KeyPad Key Index ****************/
/*         Col_0    Col_1   Col_2   Col_3      */
/*	                                          */
/* row_0      1        2       3       A       */
/*	                                          */
/* row_1      4        5       6       B       */
/*	                                          */
/* row_2	    7        8       9       C       */
/*	                                          */
/* row_3	    *       0        #       D      */
/***********************************************/

/*************************************** Constants *************************************/
/* Values of the Key Pad switches                                                      */
/* Matrix is not standard it depends on the connection between the Micro and KeyPad    */
const u8 KPD_au8SwitchVal[4][4] =
    {

        {0x01, 0x04, 0x07, '*'},
        {0x02, 0x05, 0x08, 0x00},
        {0x03, 0x06, 0x09, '#'},
        {0x0A, 0x0B, 0x0C, 0x0D}};

/***************************************************************************************/

/*******************************************************************************************/
/* Description! Interface to get the ID of the pressed key, return (0XFF) incase no key    */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are       */
/*              pressed at the same time                               	                */
/* Input      ! Nothing                                                                    */
/* Output     ! Nothing                                                                    */
/*******************************************************************************************/
u8 KPD_u8GetPressedKey(void)
{

     u8 LOC_u8Column;

     u8 LOC_u8Row;

     /* Initialize the switch status to NOT Pressed                                                                     */
     u8 LOC_u8Retrun = NOT_PRESSED;

     /* Looping on columns of the Key Pad                                                                               */
     for (LOC_u8Column = 0 + COL_INIT; LOC_u8Column < COL_FIN; LOC_u8Column++)
     {
          /* Activate the Column                                                                                           */
          PORT &= ~(1 << LOC_u8Column);

          /* Loop on the rows of the Key Pad                                                                               */
          for (LOC_u8Row = 0 + ROW_INIT; LOC_u8Row < ROW_FIN; LOC_u8Row++)
          {
               /* Check the status of the switch                                                                              */
               if (!(PIN & (1 << LOC_u8Row)))
               {
                    /* Get the value of the currently pressed switch                                                             */
                    LOC_u8Retrun = KPD_au8SwitchVal[LOC_u8Column - COL_INIT][LOC_u8Row - ROW_INIT];

                    /* Wait until the switch is released (Single Press)                                                          */
                    while (!(PIN & (1 << LOC_u8Row)));

                        /* Delay to avoid bouncing                                                                                   */
                        _delay_ms(10);
               }
          }

          /* Deactivate the Column */
          PORT |=(1<<LOC_u8Column)  ;                                                                                      
         
     }

     return LOC_u8Retrun;
}
