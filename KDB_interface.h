/********************************************************/
/* Author  :Dunga                                       */
/* Version :VO1.1                                       */
/* Data    :8 July 2019                                 */
/********************************************************/
/********************************************************/
/* Description                                          */
/* -----------                                          */
/* Interface file for Key Pad Driver for AVR 32         */
/********************************************************/

#ifndef KDB_INTERFACE_H
#define KDB_INTERFACE_H

/***************************************** Macros **************************************/
#define PORT     DIO_u8_PORTB
#define PIN       DIO_u8_PINA
/************************************************************************************* */
#define COL_INIT    (u8)0
#define COL_FIN     (u8)4
#define ROW_INIT    (u8)4
#define ROW_FIN     (u8)8

#define NOT_PRESSED   (u8)(0XFF)
#define PRESSED       (u8)(1)
/***************************************************************************************/

/*******************************************************************************************/
/* Description! Interface to get the ID of the pressed key, return (0XFF) incase no key    */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are       */
/*              pressed at the same time                               	                */
/* Input      ! Nothing                                                                    */
/* Output     ! Nothing                                                                    */
/*******************************************************************************************/
u8 KPD_u8GetPressedKey(void);

#endif // !KDB_INTERFACE_H
