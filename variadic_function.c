#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>

// Variadic function to print given arguments
void print_count(int count, ...) {
  va_list args;
  va_start(args, count); // list start after count

  for (int i = 0; i < count; i++)
    // va_arg casts to int and returns the next argument
    printf("%d ", va_arg(args, int));

  printf("\n");
  va_end(args);
}

// Variadic function to print given arguments
void print_count_str(int count, ...) {
  va_list args;
  va_start(args, count); // list start after count

  for (int i = 0; i < count; i++)
    // va_arg casts to char* and returns the next argument
    printf("%s ", va_arg(args, char *));

  printf("\n");
  va_end(args);
}

// different types of arguments can be passed to variadic functions
void print_count_mixed(int count, ...) {
  va_list args;
  va_start(args, count); // list start after count

  for (int i = 0; i < count; i++) {
    // va_arg casts to int and returns the next argument
    int num = va_arg(args, int);
    // va_arg casts to char* and returns the next argument
    char *str = va_arg(args, char *);
    printf("%d: %s\n", num, str);
  }

  va_end(args);
}

// Variadic function to print arguments based on format string
void print_format(const char *format, ...) {
  va_list args;
  va_start(args, format);

  // Loop until end of format string
  for (const char *p = format; *p != '\0'; p++) {
    if (*p == 'd') {
      // if current is 'd', then cast next one to int and print
      printf("%d ", va_arg(args, int));
    } else if (*p == 'f') {
      printf("%.2f ", va_arg(args, double));
    } else if (*p == 's') {
      printf("%s ", va_arg(args, char *));
    } else if (*p == 'c') {

      // char is promoted to int in variadic functions, so we read it as
      // int and print as char
      printf("%c ", va_arg(args, int));
    }
  }
  printf("\n");
  va_end(args);
}

int main() {

  print_count(5, 1, 2, 3, 4, 5);
  print_count(15, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

  print_count_str(3, "Hello", "World", "!");

  // will segmentation fault, because 1 is not a string
  // print_count_str(4, "Hello", "World", "!", 1);

  // will work because we are only reading 3 strings, the 1 is ignored in the
  // loop
  print_count_str(3, "Hello", "World11111", "!", 1);

  print_count_mixed(3, 1, "Hello", 2, "World", 3, "!");

  // print_format takes a format string where each character specifies the type
  // of the next argument: 'd' for int, 'f' for double, 's' for string, 'c' for
  print_format("d s f c", 42, "Hello", 3.14159, 'X');

  return 0;
}
