#ifndef _HEADER_FUNCTIONS
#define _HEADER_FUNCTIONS

#include <avr/io.h>
#include <avr/interrupt.h>
#include "drawfunctions.h"
#define PI 3.1416
#include <math.h>


/*
    @brief Converts the wanted angle to the needed clockticks for the duty cycle in the signal.
    @param angle Wanted angle.
    @param ticks Pointer to needed clockticks.
*/
void convert_to_ticks(float angle, int* ticks);

/*
    @brief Move servos to (x, y)
    @param x Point x-axis
    @param y Point y-axis
*/
void move_to_coord(float x, float y);

/*
    @brief Initializes the timerinterrupt.
*/
void timerSetup();


#endif