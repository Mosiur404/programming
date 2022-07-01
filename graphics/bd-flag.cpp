#include <graphics.h>
#include <conio.h>
int main() {
  int gd = DETECT, gm;
  char pathDriver[] = "";
  initgraph(&gd, &gm, pathDriver);
  floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);
  // large rectangle
  setcolor(GREEN);
  rectangle(150, 40, 450, 180);
  setfillstyle(1, GREEN);
  floodfill(160, 50, GREEN);
  // circle
  setcolor(RED);
  circle(300, 110, 55);
  setfillstyle(1, RED);
  floodfill(320, 120, RED);
  // stand bar
  setcolor(DARKGRAY);
  rectangle(138, 35, 150, 450);
  setfillstyle(1, DARKGRAY);
  floodfill(140, 40, DARKGRAY);

  bar(130, 450, 160, 460);
  setcolor(DARKGRAY);

  getch();
  closegraph();
  return 0;
}