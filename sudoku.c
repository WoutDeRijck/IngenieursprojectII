#include "sudoku.h"


/********************************************************************************************
*    Title: isAvailable
*    Author: syb0rg
*    Date: 2013
*    Availability: https://codereview.stackexchange.com/questions/37430/sudoku-solver-in-c
********************************************************************************************/
int isAvailable(int puzzle[][9], int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    int i;

    for(i=0; i<9; ++i){
        if (puzzle[row][i] == num) return 0;    /* Check if this row has num */
        if (puzzle[i][col] == num) return 0;    /* Check if this column has num*/
        if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num) return 0;    /* Check if this block has num */
    }
    return 1;
}

/********************************************************************************************
*    Title: solveSudoku
*    Author: syb0rg
*    Date: 2013
*    Availability: https://codereview.stackexchange.com/questions/37430/sudoku-solver-in-c
********************************************************************************************/
int solveSudoku(int puzzle[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(puzzle[row][col]){
            if((col+1)<9) return solveSudoku(puzzle, row, col+1);       /* Solve next box */
            else if((row+1)<9) return solveSudoku(puzzle, row+1, 0);    /* Start new row */
            else return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(isAvailable(puzzle, row, col, i+1))                  /* Check every number */
                {
                    puzzle[row][col] = i+1;
                    if((col+1)<9)
                    {
                        if(solveSudoku(puzzle, row, col +1)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(solveSudoku(puzzle, row+1, 0)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1; /***********************************************************@wout moet dit niet 0 zijn?******************************************************/ 
}

void drawBlock(int puzzle[][9], int block_row, int block_column){ 
    for(int i = 0 + 3*block_row; i<3 + 3*block_row; i++){
      for(int j = 0 + 3*block_column; j<3 + 3*block_column; j++){

          switch (puzzle[i][j]){    /* Check what number to draw */
            case 1:
              draw_1(i%3, j%3);
              break;
            case 2:
              draw_2(i%3, j%3);
              break;
            case 3:
              draw_3(i%3, j%3);
              break;
            case 4:
              draw_4(i%3, j%3);
              break;
            case 5:
              draw_5(i%3, j%3);
              break;
            case 6:
              draw_6(i%3, j%3);
              break;
            case 7:
              draw_7(i%3, j%3);
              break;
            case 8:
              draw_8(i%3, j%3);
              break;
            case 9:
              draw_9(i%3, j%3);
              break;
          }
      }
    }
}

void drawSudoku(int puzzle[][9]){
  DDRE = ~_BV(PE5); /*set central button as input*/
  PORTE = _BV(PE7); /*pull the value of PE7 to logical high state*/
  backlightOn();

  int block_row = -1;
  int block_column = 2;
  int button_pressed = 0;
  int start_drawing = 0;

  while(1){
    _delay_ms(50);

    if (!(PINE & _BV(PE7))){ 
      while(!button_pressed){
        start_drawing = 1;

        if(block_column == 2){
          block_row += 1;
          block_column = 0;
        }
        else{
          block_column += 1;
        }

        if(block_row >= 3){
          clearLCD();
          printStringToLCD("Solved!",0, 0);
          _delay_ms(5000);
          clearLCD();
          printStringToLCD("exiting..", 0, 0);
          _delay_ms(1000);
          clearLCD();
          return;
        }
        button_pressed = 1;
      }
    }

    if(start_drawing){
      drawBlock(puzzle, block_row, block_column);
      move_to_coord(0,3);
      start_drawing = 0;
    }

    button_pressed = 0;
    clearLCD();
    printStringToLCD("press button to", 0, 0);
    printStringToLCD("solve next block", 1, 0);

  }
}
