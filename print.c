#include <stdio.h>

void print_padding(int num) {
  // left padding with spaces
  printf("|%10d|\n", 999);
  // left padding with zeros
  printf("|%010d|\n", 999);
  // right padding with spaces
  printf("|%110d|\n", 999);
  // right padding with spaces, but with a specified width
  printf("|%*d|\n", num, 999);
}

void print_table() {
  printf("-------------------------------\n");
  printf("|%10s|%10s|%10s|\n", "Name", "Age", "City");
  printf("|%10s|%10s|%10s|\n", "Alice", "30", "New York");
  printf("|%10s|%10s|%10s|\n", "Bob", "25", "Los Angeles");
  printf("|%10s|%10s|%10s|\n", "Charlie", "35", "Chicago");
  printf("-------------------------------\n");
}

void print_progress_bar(int percent) {
  int bar_with = 50;
  int filled = (percent * bar_with) / 100;

  printf("[");
  for (int i = 0; i < filled; i++) {
    printf("#");
  }
  for (int i = filled; i < bar_with; i++) {
    printf(" ");
  }
  printf("] %d%%\n", percent);
}

int main() {
  printf("Hello, World!\n");
  print_padding(10);
  print_table();
  print_progress_bar(75);
  return 0;
}