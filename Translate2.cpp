#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  int l[2][2], v[2] = {100, 100}, i=0, j;

  printf("Enter the initial and final coordinates of the line:\n");

  while (i < 2) {
    printf("x%d and y%d: ", i, i);
    j=0;
    scanf("%d %d", &l[i][j], &l[i][j+1]);
    i++;
  }
  //line before translation
  line(l[0][0], l[0][1], l[1][0], l[1][1]);

  setcolor(BLUE);
  //line after translation
  line(l[0][0]+v[0], l[0][1]+v[1], l[1][0]+v[0], l[1][1]+v[1]);

  getch();
  closegraph();
  return 0;
}
