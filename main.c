#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include "snowflake.h"

int ncols, nrows;

int main(void)
{
  WINDOW *win;

  win = initscr();

  nrows = getmaxy(win);
  ncols = getmaxx(win);

  Snowflake *snowflakes[nrows];
  int counter = 0;

  curs_set(0);

  for(;;) {
    if(counter < nrows) {
      Snowflake *snowflake = malloc(sizeof(Snowflake *));
      snowflakes[counter++] = snowflake;
      draw(snowflake, rand() % (ncols + 1), rand() % 4);
    }

    refresh();

    move_c(snowflakes, counter);

    usleep(60000);
  }
  
  endwin();
  
  return 0;
}
