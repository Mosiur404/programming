#include <graphics.h>
#include <conio.h>
int main() {
  int gd = DETECT, gm;
  char test[] = "";
  initgraph(&gd, &gm, test);
  floodfill(getmaxx() / 2, getmaxy() / 2, WHITE);
  setbkcolor(WHITE);
  setcolor(BLUE);
  // setlinestyle(SOLID_LINE, 0xFFFF, 5);
  // //   circle(getmaxx() / 2, getmaxy() / 2, getwindowheight() / 2 - 50);

  // settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
  // char text[] = "THIS IS OUTTEXTXY";
  // outtextxy(100, 60, text);
  // //   setcolor(BLUE);
  // //   arc(250, 250, 155, 300, 200);
  // setfillstyle(1, MAGENTA);
  // rectangle(20, 20, getmaxx() - 20, getmaxy() - 20);

  // bar(100, 100, 200, getmaxy());
  int r = 50, x = getmaxx() / 2, y = getmaxy() / 2, color = 1;
  for (int i = 2; i <= 3; i++) {
    setcolor(i);
    circle(x, y, 70 + (i * 20));
    setfillstyle(SOLID_FILL, i);
    floodfill(x + 70 + (i * 20) - 10, y + 70 + (i * 20) - 2, i);
  }

  getch();
  return 0;
}
