#include <curses.h>
#include "snowflake.h"

void move_c(Snowflake *snowflakes[], int snowflakesSize)
{
  for(int i = 0; i < snowflakesSize; i++) {

    Snowflake *current = snowflakes[i];

    int y = current->y;
    int x = current->x;

    move(y, x);

    delch();

    if(y >= nrows - 1 || x >= ncols - 1) {
      current->x = current->x0;
      current->y = -1;
    }

    current->y++;
    y = current->y;

    current->x += current->speed;
 
    x = current->x;

    move(y, x);

    insch(C);
  }
}

void draw(Snowflake *snowflake, int x, int speed)
{
  snowflake->x = x;
  snowflake->x0 = x;
  snowflake->y = 0;
  snowflake->speed = speed;
  
  move(0, x);

  insch(C);
}
