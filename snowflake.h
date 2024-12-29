#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#define C '*'

extern int ncols, nrows;

typedef struct {
  int x;
  int x0;
  int y;
  int speed;
} Snowflake;

void draw(Snowflake *, int, int);

void move_c(Snowflake *[], int);

#endif
