#ifndef _HEADER_USART
#define _HEADER_USART

#include <avr/io.h>
#include "functions.h"
#define PI 3.1416

/*
    @brief Initializes communication.
*/
void USART_init();

/*
    @brief Waits for and returns received data
*/
unsigned char USART_receive();

/*
    @brief Transmits data
    @param data Data to be transmitted
*/
void USART_transmit(unsigned char data);

/*
    @brief Reads sudoku from csv and returns it as 2-dimensional array
    @param matrix An initialized 2-dimensional array
*/
int Read_Sudoku(int matrix[][9]);

#endif