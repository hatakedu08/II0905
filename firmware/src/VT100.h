/******************************************************
 * 
 * Les fonctions du fichier VT100 permettent de proposer
 * quelques fonctionnalités graphique dans une console selon
 * le protocole VT100
 * 
 * prerequise : desactivation ENABLE_CONSOLE dans miwi_config.h de la MLA
 *              
 * 
 * file: VT100   
 * 
 * @author: M. COLAS
 * @version : 1.0 
 *****************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef VT100_H
#define	VT100_H

#include <xc.h>  
#include <stdint.h>
#include <stdbool.h>




/*********************************************
 *           Fonctions UART(2)             
 *********************************************/
void uartInitialize(void);
uint8_t uartRead(void);
void uartWrite(uint8_t c);
void _uartPrint(char * str);
void uartHexaPrint(uint8_t * val,uint8_t n);





/*********************************************
 *           Commandes VT100             
 *********************************************/
void vT100EraseEndOfLine(void);
void erase(void);
void scroll(void);
void SavRes(void);
void Res(void);
void def(int,int);
void cursor(int row,int column);
void color(void);
void LockKeyboard(bool s);


#define uartPrint(x) _uartPrint((char*)x)
#define uartIsChar()	PIR3bits.RC2IF

#endif	/* VT100_H */

