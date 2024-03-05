#include "drawfunctions.h"


float t = 0.0;

/*********************************************************************************************************************************************
Drawfunctions: General
*********************************************************************************************************************************************/

void draw_line(float x0, float y0, float x1, float y1){
  t = 0.0;
  move_to_coord((1-t)*x0 + t*x1, (1-t)*y0 + t*y1);
  for(t=0.0; t<=1.0; t += 0.00015){
    move_to_coord((1-t)*x0 + t*x1, (1-t)*y0 + t*y1);
  }
}

void bezier(float x0, float y0, float x1, float y1, float x2, float y2){
  t = 0.0;
  move_to_coord(x0*(1-t)*(1-t) + 2*(1-t)*t*x1 + t*t*x2, y0*(1-t)*(1-t) + 2*(1-t)*t*y1 + t*t*y2);
  for(t=0.0; t<=1.0; t += 0.0005){
    move_to_coord(x0*(1-t)*(1-t) + 2*(1-t)*t*x1 + t*t*x2, y0*(1-t)*(1-t) + 2*(1-t)*t*y1 + t*t*y2);
  }
}

void cubic_bezier(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3){
  t = 0.0;
  move_to_coord(x0*(1-t)*(1-t)*(1-t) + 3*(1-t)*(1-t)*t*x1 + 3*(1-t)*t*t*x2 + t*t*t*x3, y0*(1-t)*(1-t)*(1-t) + 3*(1-t)*(1-t)*t*y1 + 3*(1-t)*t*t*y2 + t*t*t*y3);
  for(t=0.0; t<=1.0; t += 0.0001){
    move_to_coord(x0*(1-t)*(1-t)*(1-t) + 3*(1-t)*(1-t)*t*x1 + 3*(1-t)*t*t*x2 + t*t*t*x3, y0*(1-t)*(1-t)*(1-t) + 3*(1-t)*(1-t)*t*y1 + 3*(1-t)*t*t*y2 + t*t*t*y3);
  }
}

void draw_circle(float midpoint_x, float midpoint_y, float r, float t1, float t2){
  move_to_coord(r * cos(t1) + midpoint_x, r * sin(t1) + midpoint_y);
  if(t1<t2){
    for(t = t1; t <= t2; t += 0.0005 ){
      move_to_coord(r * cos(t) + midpoint_x, r * sin(t) + midpoint_y);
    }
  }
  if(t1>t2){
    for(t = t1; t >= t2; t -= 0.0005 ){
      move_to_coord(r * cos(t) + midpoint_x, r * sin(t) + midpoint_y);
    }
  }
  clearLCD();
}

/*********************************************************************************************************************************************
Drawfunctions: Sudoku
*********************************************************************************************************************************************/

void draw_grid(){
  clearLCD();
  printStringToLCD("Drawing Grid", 0, 0);
  draw_line(13.5, 3, 13.5, 16.5);
  draw_line(9, 16.5, 9, 3);
  draw_line(4.5, 3, 4.5, 16.5);
  draw_line(0, 16.5, 0, 3);
  draw_line(0, 3, 13.5, 3);
  draw_line(13.5, 7.5, 0, 7.5);
  draw_line(0, 12, 13.5, 12);
  draw_line(13.5, 16.5, 0, 16.5);
  clearLCD();
}

void draw_1(int row, int column){
  float x = 13.50-(column+1)*4.50;
  float y = 16.50-(row+1)*4.50;
  clearLCD();
  printStringToLCD("Drawing Number 1", 0, 0);
  draw_circle(x+4.20, y+4.50, 2.37, 3*PI/2-0.50, PI+0.32);
  draw_line(x+1.95, y+3.75, x+1.95, y+0.75);
  clearLCD();
}

void draw_2(int row, int column){
  float x = 13.5-(column+1)*4.5;
  float y = 16.5-(row+1)*4.5;
  clearLCD();
  printStringToLCD("Drawing Number 2", 0, 0);
  draw_circle(x+2.25, y+2.85, 1.20, 0, PI);  
  cubic_bezier(x+1.05, y+2.85, x+1.05, y+1.65, x+3.45, y+1.80, x+3.45, y+0.45);
  draw_line(x+3.45, y+0.45, x+1.05, y+0.45);
  clearLCD();
}

void draw_3(int row, int column){
  float x = 13.5-(column+1)*4.5;
  float y = 16.5-(row+1)*4.5;
  clearLCD();
  printStringToLCD("Drawing Number 3", 0, 0);
  draw_circle(x+2.25, y+3.30, 0.90, 0.20, 3*PI/2);
  draw_circle(x+2.25, y+1.35, 1.05, PI/2, 2*PI-.3);
  clearLCD();
}

void draw_4(int row, int column){
  float x = 13.5-(column+1)*4.5;
  float y = 16.5-(row+1)*4.5;
  clearLCD();
  printStringToLCD("Drawing Number 4", 0, 0);
  draw_line(x+1.95, y+0.75, x+1.95, y+3.75);
  draw_line(x+1.95, y+3.75, x+ 3.30, y+1.80);
  draw_line(x+3.30, y+1.80, x+1.50, y+1.80);
  clearLCD();
}

void draw_5(int row, int column){
  float x = 13.5-(column+1)*4.5;
  float y = 16.5-(row+1)*4.5;
  clearLCD();
  printStringToLCD("Drawing number 5", 0, 0);
  draw_line(x+1.50, y+3.90, x+3.00, y+3.90);
  draw_line(x+3.00, y+3.90, x+3.30, y+2.55);
  draw_circle(x+2.50, y+1.65, 1.20, 0.85, 2*PI-0.85);
  clearLCD();
}

void draw_6(int row, int column){
  float x = 13.5-(column+1)*4.5;
  float y = 16.5-(row+1)*4.5;
  clearLCD();
  printStringToLCD("Drawing Number 6", 0, 0);
  cubic_bezier(x+1.50, y+3.90, x+4.50, y+1.50, x+2.70, y-0.60, x+1.50, y+0.90);
  cubic_bezier(x+1.50, y+0.90, x+0.60, y+2.40, x+3.00, y+2.40, x+3.15, y+1.50);
  clearLCD();
}

void draw_7(int row, int column){
  float x = 13.5-(column+1)*4.5;
  float y = 16.5-(row+1)*4.5;
  clearLCD();
  printStringToLCD("Drawing Number 7", 0, 0);
  draw_line(x+3.45, y+3.90, x+1.05, y+3.90);
  bezier(x+1.05, y+3.90, x+2.10, y+2.70, x+2.70, y+0.6);
  clearLCD();
}

void draw_8(int row, int column){
  float x = 13.5-(column+1)*4.5;
  float y = 16.5-(row+1)*4.5;
  clearLCD();
  printStringToLCD("Drawing Number 8", 0, 0);
  draw_circle(x+2.25, y+3.30, 0.90, -PI/2, 3*PI/2);
  draw_circle(x+2.25, y+1.35, 1.05, PI/2, -3*PI/2);
  clearLCD();
}

void draw_9(int row, int column){
  float x = 13.5-(column+1)*4.5;
  float y = 16.5-(row+1)*4.5;
  clearLCD();
  printStringToLCD("Drawing Number 9", 0, 0);
  cubic_bezier(x+3.00, y+0.60, x, y+3.00, x+1.80, y+5.10, x+3.00, y+3.60);
  cubic_bezier(x+3.00, y+3.60, x+3.90, y+2.10, x+1.50, y+2.10, x+1.37, y+3.00);
  clearLCD();
}
  