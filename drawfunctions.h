#ifndef _HEADER_DRAWFUNCTIONS
#define _HEADER_DRAWFUNCTIONS

#include "dwenguino/dwenguino_lcd.h"
#include "dwenguino/dwenguino_board.h"
#include "functions.h"
#define PI 3.1416
#include <math.h>

/*
    @brief draws a line between two points
    @param x0 x-value of starting point
    @param y0 y-value of starting point
    @param x1 x-value of ending point
    @param y1 y-value of ending point
*/
void draw_line(float x0, float y0, float x1, float y1);

/*
    @brief draws a quadratic bezier curve
    @param x0 x-value of starting point
    @param y0 y-value of starting point
    @param x1 x-value of intermediate control point
    @param y1 y-value of intermediate control point
    @param x2 x-value of ending point
    @param y2 y-value of ending point
*/
void bezier(float x0, float y0, float x1, float y1, float x2, float y2);



/*
    @brief draws a quadratic bezier curve
    @param x0 x-value of starting point
    @param y0 y-value of starting point
    @param x1 x-value of first intermediate control point
    @param y1 y-value of first intermediate control point
    @param x2 x-value of second intermediate control point
    @param y2 y-value of second intermediate control point
    @param x3 x-value of ending point
    @param y3 y-value of ending point
*/
void cubic_bezier(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3);


/*
    @brief draws a circle
    @param midpoint_x x-value of midpoint
    @param midpoint_y y-value of midpoint
*/
void draw_circle(float midpoint_x, float midpoint_y, float r, float t1, float t2);

/*
    @brief draws a sudoku grid (9x9)    
*/
void draw_grid();

/*
    @brief draws number 1 on position row, column    
*/
void draw_1(int row, int column);

/*
    @brief draws number 2 on position row, column    
*/
void draw_2(int row, int column);

/*
    @brief draws number 3 on position row, column    
*/
void draw_3(int row, int column);

/*
    @brief draws number 4 on position row, column    
*/
void draw_4(int row, int column);

/*
    @brief draws number 5 on position row, column    
*/
void draw_5(int row, int column);

/*
    @brief draws number 6 on position row, column    
*/
void draw_6(int row, int column);

/*
    @brief draws number 7 on position row, column    
*/
void draw_7(int row, int column);

/*
    @brief draws number 8 on position row, column    
*/
void draw_8(int row, int column);

/*
    @brief draws number 9 on position row, column    
*/
void draw_9(int row, int column);


#endif