#include <stdio.h>

struct Point {
  int x;
  int y;
};

struct PointWithFunction {
  int x;
  int y;
  void (*print)(struct PointWithFunction *);
};

void printPoint(struct PointWithFunction *p) {
  printf("Point: (%d, %d)\n", p->x, p->y);
}

int main() {
  struct Point p1 = {10, 20};
  printf("Point p1: (%d, %d)\n", p1.x, p1.y);

  // Modifying the values of the structure members
  p1.x = 30;
  p1.y = 40;
  printf("Modified Point p1: (%d, %d)\n", p1.x, p1.y);

  struct PointWithFunction p2 = {50, 60, printPoint};
  // Calling the function pointer to print the point
  p2.print(&p2);

  return 0;
}