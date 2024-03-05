#include "functions.h"


//constants
int ticks1 = 0;     /* Clockticks for duty cycle servo 1 */
int ticks2 = 0;     /* Clockticks for duty cycle servo 2 */
float L = 12.5;     /* Length of servo arm */
int stateServo = 1; /* 1: Signal to servo 1; 2: signal to servo 2 */
int stateCycle = 0; /* 1: Time in duty cycle; 2: time out of duty cycle */


/*********************************************************************************************************************************************
Functions
*********************************************************************************************************************************************/


void convert_to_ticks(float angle,int* ticks){
  float duty_cycle = (1.6/PI*angle)+0.7;
  *ticks = 2000*duty_cycle;
}

void move_to_coord(float x, float y){
  float q2 = PI-acos((x*x+y*y-2*L*L)/(2*L*L));                  /* Inverse kinematics: converting coordinates */
  float q1 = atan2(x, -y) - atan2(L*sin(q2), L*(1+cos(q2)));    /* to the right angles (q1, q2) for (servo1, servo2) */
  convert_to_ticks(q1, &ticks1);
  convert_to_ticks(q2, &ticks2);
}


/*********************************************************************************************************************************************
Timer interrupt
*********************************************************************************************************************************************/

ISR(TIMER1_COMPA_vect){
  if(stateServo == 1){                  /* Servo 1 */
    if(stateCycle){                       
      OCR1A = 40000-ticks1;             /* Time out of duty cycle */            
      PORTC &= ~_BV(PC0);
      stateCycle = 0;
      stateServo = 2;
    }else{                        
      OCR1A = ticks1;                   /* Time in duty cycle */
      PORTC |= _BV(PC0);
      stateCycle = 1;
    }
  }
  if(stateServo == 2){                  /* Servo 2 */
    if(stateCycle){                        
      OCR1A = 40000-ticks2;             
      PORTC &= ~_BV(PC1);
      stateCycle = 0;
      stateServo = 1;
    }else{                       
      OCR1A = ticks2;            
      PORTC |= _BV(PC1);
      stateCycle = 1;
    }
  }  
}

void timerSetup(){

  SREG |= (1 << SREG_I);
  TIMSK1 |= 0x02;                       
  OCR1A   = 0x01;                       
  TCCR1B |= 0x02;                     /* Prescaler 8, dus 2 MHz */           
  TCCR1B &= 0xFA;
  TCCR1A &= 0xFC;                       
  TCCR1B &= 0xEF;
  TCCR1B |= 0x08;
}