#include <stdio.h>

int hourInMinute(int hour) { return hour * 60; }
int inRange(int a, int b, int item) { return (item >= a && item <= b); }

int main() {
  int S, T, X;
  scanf("%d%d%d", &S, &T, &X);

  int maxTimeHour = hourInMinute(24);

  int startTime = hourInMinute(S);
  int endTime = hourInMinute(T);

  int masudMustBeHome = hourInMinute(X) + 30;

  // example (24*60) + 30 = (24*60)+30 - 24*60 => 30 (new day)
  if (masudMustBeHome > maxTimeHour) masudMustBeHome -= maxTimeHour;

  // example 7-20
  if (startTime < endTime) {
    if (inRange(startTime, endTime, masudMustBeHome))
      printf("Yes\n");
    else
      printf("No\n");
  }
  // else example 20-7 means 20-24 or 0-7
  else {
    if (inRange(startTime, maxTimeHour, masudMustBeHome) ||
        inRange(0, endTime, masudMustBeHome))
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}