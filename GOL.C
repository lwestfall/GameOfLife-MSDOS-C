#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 40
#define DENSITY 0.35

char cells[ROWS][COLS];
char newstate[ROWS][COLS];
int width, height;

void initboard();
void drawcell(int x, int y, char alive);
char isalive(int x, int y);
void tick();

int main()
{
  initboard();
  /* todo handle keyboard interrupts */
  while (1)
  {
    tick();
  }

  closegraph();

  return 0;
}

void initboard()
{
  int gd = DETECT, gm, errorcode;
  int i, j;

  initgraph(&gd, &gm, "C:\\TC");
  errorcode = graphresult();

  if (errorcode != grOk)
  {
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    getch();
    free(cells);
    exit(1);
  }

  width = (getmaxx() + 1) / COLS;
  height = (getmaxy() + 1) / ROWS;

  srand(time(NULL));

  setfillstyle(SOLID_FILL, 0xF);
  bar(0, 0, getmaxx(), getmaxy());

  for (i = 0; i < ROWS; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      cells[i][j] = (double)rand() / RAND_MAX < DENSITY;
      if (cells[i][j] > 0)
      {
        drawcell(j, i, cells[i][j]);
      }
    }
  }
}

void tick()
{
  int i, j, alive = 0;

  for (i = 0; i < ROWS; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      alive = isalive(j, i);
      newstate[i][j] = alive;
    }
  }

  /* todo use dynamic allocation to avoid iterating again*/
  for (i = 0; i < ROWS; i++)
  {
    for (j = 0; j < COLS; j++)
    {
      if (cells[i][j] != newstate[i][j])
      {
        drawcell(j, i, newstate[i][j]);
        cells[i][j] = newstate[i][j];
      }
    }
  }
}

char isalive(int x, int y)
{
  int neighbors = 0;
  int i, j;

  for (i = y - 1; i <= y + 1; i++)
  {
    if (i < 0 || i >= ROWS)
      continue;
    for (j = x - 1; j <= x + 1; j++)
    {
      if (j < 0 || j >= COLS || (i == y && j == x))
        continue;
      if (cells[i][j] > 0)
      {
        neighbors++;
        if (neighbors > 3)
          return 0;
      }
    }
  }

  if (neighbors < 2 || neighbors > 3)
    return 0;
  if (cells[y][x] > 0)
    return 1;
  if (neighbors == 3)
    return 1;
  return 0;
}

void drawcell(int x, int y, char alive)
{
  int left = x * width;
  int top = y * height;
  int right = left + width;
  int bottom = top + height;

  if (alive > 0)
  {
    setfillstyle(SOLID_FILL, 1);
  }
  else
  {
    setfillstyle(SOLID_FILL, 0xF);
  }

  bar3d(left, top, right, bottom, 0, 0);
}
