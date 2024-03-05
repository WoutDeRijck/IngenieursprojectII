#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <avr/io.h>
#include <util/delay.h>
#include "drawfunctions.h"
#include "dwenguino/dwenguino_lcd.h"

/* 
    @brief Checks if this number is available in this box
    @param num Number to be checked
    @param row Row of the box
    @param col Column of the box

*/
int isAvailable(int puzzle[][9], int row, int col, int num);

/*
    @brief Solves the sudoku
    @param puzzle The sudoku to be solved
    @param row The row to start
    @param col The column to start
*/
int solveSudoku(int puzzle[][9], int row, int col);

/*
    @brief Draws the sudoku
    @param puzzle Sudoku to be drawed
*/
void drawSudoku(int puzzle[][9]);

/*
    @brief Draws a 3x3 block
    @param block_row The row of the block
    @param block_column The column of the block
*/
void drawBlock(int puzzle[][9], int block_row, int block_column);

#endif