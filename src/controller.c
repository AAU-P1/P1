#include "controller.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void input_int(char *message, int *dest) {
  while (true) {
    printf("%s\n", message);
    int res = scanf("%d", dest);
    clearInputBuffer();
    if (res != 1) {
      printf("Invalid input. Try again!\n");
    } else {
      return;
    }
  }
}

void input_int_with_range(char *message, int *dest, int valid_low,
                          int valid_high) {
  while (true) {
    printf("%s\n", message);
    int res = scanf("%d", dest);
    clearInputBuffer();
    if (res != 1 || *dest > valid_high || *dest < valid_low) {
      printf("Invalid input. Try again!\n");
    } else {
      return;
    }
  }
}

void input_double(char *message, double *dest) {
  while (true) {
    printf("%s\n", message);
    int res = scanf("%lf", dest);
    clearInputBuffer();
    if (res != 1) {
      printf("Invalid input. Try again!\n");
    } else {
      return;
    }
  }
}

void input_char(char *choice, char *message, char *valid_chars) {
  while (true) {
    printf("%s\n", message);
    char c = getchar();
    clearInputBuffer();
    int i = 0;
    while (valid_chars[i] != '\0') {
      if (c == valid_chars[i]) {
        *choice = c;
        return;
      }
      ++i;
    }
    printf("Invalid input. Try again!\n");
  }
}

void input_string(char *message, char *dest) {
  while (true) {
    printf("%s\n", message);
    int res = scanf("%s", dest);
    if (res != 1) {
      printf("Invalid input. Try again!\n");
    } else {
      return;
    }
  }
}

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

void clear_screen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
