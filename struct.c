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

// use qsort to sort an array of structures based on a member variable
// Person structure with name and age
typedef struct {
  char name[50];
  int age;
} Person;

// Comparison function for qsort to sort by age
// this function will be passed to qsort and will be called for each pair of
// elements to determine their order
int compareByAge(const void *a, const void *b) {
  Person *personA = (Person *)a;
  Person *personB = (Person *)b;
  return personA->age - personB->age; // Sort in ascending order
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

  printf("\n");

  // Array of Person structures
  Person people[3] = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};

  // printing unsorted array
  printf("Unsorted People:\n");
  for (int i = 0; i < 3; i++) {
    printf("%s: %d\n", people[i].name, people[i].age);
  }

  // Sorting the array of Person structures by age using qsort
  qsort(people, 3, sizeof(Person), compareByAge);

  // printing sorted array
  printf("\nSorted People by Age:\n");
  for (int i = 0; i < 3; i++) {
    printf("%s: %d\n", people[i].name, people[i].age);
  }

  return 0;
}