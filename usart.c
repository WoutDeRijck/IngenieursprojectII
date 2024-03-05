#include "usart.h"


void USART_init(){
  UBRR1H = (unsigned char)(103>>8);     /* Set baud rate */
  UBRR1L = (unsigned char) 103;     
  UCSR1B = (1<<RXEN1)|(1<<TXEN1);       /* Enable receiver and transmitter */ 
  UCSR1C = (1<<USBS1)|(3<<UCSZ10);      /* Set frame format: 8data, 2stop bit */ 
}

unsigned char USART_receive(){
  while(!(UCSR1A & (1<<RXC1)));         /* Wait for data to be received */
  return UDR1;                          /* Get and return received data from buffer */
}

void USART_transmit(unsigned char data){
  while(!(UCSR1A & (1<<UDRE1)));        /* Wait for empty transmit buffer */
  UDR1 = data;                          /* Put data into buffer */
}

int Read_Sudoku(int matrix[][9]){
  unsigned char data;
  for(int i = 0; i<9; i++){
      for(int j = 0; j<9; j++){
          data = USART_receive();       /* Wait for data to be received */
          if(data){
              matrix[i][j] = (int) data;
          }
          USART_transmit(data);         /* Send control signal so next byte can be send */
      }
  }
  return 1;
}