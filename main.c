#include "dwenguino/dwenguino_lcd.h"
#include "dwenguino/dwenguino_board.h"
#include "drawfunctions.h"
#include "functions.h"
#include "usart.h"
#include "sudoku.h"


int main(void)
{
DDRC |= _BV(PC0);
DDRC |= _BV(PC1);
timerSetup();
backlightOn();
initLCD();
clearLCD();
USART_init();

move_to_coord(13.5, 3);
draw_grid();

int puzzle[9][9] = {
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
};

Read_Sudoku(puzzle);
if(solveSudoku(puzzle, 0, 0)){
    drawSudoku(puzzle);
}else{
    while(1){
        printStringToLCD("No Solution", 0, 0);
    }
}

return 0;
}
