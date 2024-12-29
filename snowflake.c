#include <curses.h>
#include <stdio.h>
#include "snowflake.h"

void move_c(Snowflake *snowflakes[], int snowflakesSize)
{
  int x, y, speed;
  for(int i = 0; i < snowflakesSize; i++) {

    y = snowflakes[i]->y;
    x = snowflakes[i]->x;
    speed = snowflakes[i]->speed;

    move(y, x);
    delch();

    y += 1;
    x += speed;

    if(y == nrows || x >= ncols - 1) {
      x = snowflakes[i]->x0;
      y = 0;
    }

    move(y, x);
    insch(C);

    snowflakes[i]->x = x;
    snowflakes[i]->y = y;
  }
}

void draw(Snowflake *snowflake, int x, int speed)
{
  snowflake->x = x;
  snowflake->x0 = snowflake->x;
  snowflake->y = 0;
  snowflake->speed = speed;
  
  move(0, x);

  insch(C);
}
