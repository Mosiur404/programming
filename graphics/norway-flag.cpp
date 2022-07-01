#include <graphics.h>
#include <conio.h>
int main() {
  int gd = DETECT, gm;
  char pathDriver[] = "";
  initgraph(&gd, &gm, pathDriver);
  floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);
  // main rectangle
  setcolor(RED);
  rectangle(150, 40, 458, 250);
  setfillstyle(1, RED);
  floodfill(160, 50, RED);
  // flag bar white
  setcolor(WHITE);
  setfillstyle(1, WHITE);
  // flag bar 1
  rectangle(150 + (6 * 14), 40, 150 + (6 * 14) + (4 * 14), 250);
  floodfill(150 + (6 * 14) + 1, 40 + 1, WHITE);
  // flag bar 2
  rectangle(150, 40 + (6 * 14), 458, 40 + (6 * 14) + (4 * 14));
  floodfill(150 + 1, 40 + (6 * 14) + 1, WHITE);
  floodfill(458 - 1, 40 + (6 * 14) + 1, WHITE);
  // flag bar blue
  setcolor(BLUE);
  setfillstyle(1, BLUE);
  // flag bar 1
  rectangle(150 + (7 * 14), 40, 150 + (6 * 14) + (3 * 14), 250);
  floodfill(150 + (7 * 14) + 1, 40 + 1, BLUE);
  // flag bar 2
  rectangle(150, 40 + (7 * 14), 458, 40 + (7 * 14) + (2 * 14));
  floodfill(150 + 1, 40 + (7 * 14) + 1, BLUE);
  floodfill(458 - 1, 40 + (7 * 14) + 1, BLUE);

  setcolor(RED);
  rectangle(150, 40, 458, 250);
  // stand bar
  setcolor(DARKGRAY);
  rectangle(138, 35, 150, 458);
  setfillstyle(1, DARKGRAY);
  floodfill(140, 40, DARKGRAY);

  bar(130, 458, 160, 460);
  setcolor(DARKGRAY);

  getch();
  closegraph();
  return 0;
}