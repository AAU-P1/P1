#include "controller.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void inputIntWithRange(char *message, int *dest, int low, int high) {
  while (true) {
    printf("%s\n", message);
    clearInputBuffer();
    int res = scanf("%d", dest);
    clearInputBuffer();
    if (res != 1 || *dest > high || *dest < low || *dest > 32766 ||
        *dest < -32766) {
      printf("Invalid input. Try again!\n");
    } else {
      return;
    }
  }
}

void inputIntWithMin(char *message, int *dest, int low) {
  while (true) {
    printf("%s\n", message);
    clearInputBuffer();
    int res = scanf("%d", dest);
    clearInputBuffer();
    if (res != 1 || *dest < low || *dest > 32766 || *dest < -32766) {
      printf("Invalid input. Try again!\n");
    } else {
      return;
    }
  }
}

void inputDouble(char *message, double *dest) {
  while (true) {
    printf("%s\n", message);
    clearInputBuffer();
    int res = scanf("%lf", dest);
    clearInputBuffer();
    if (res != 1) {
      printf("Invalid input. Try again!\n");
    } else {
      return;
    }
  }
}

void inputChar(char *choice, char *message, char *validChars) {
  while (true) {
    printf("%s\n", message);
    clearInputBuffer();
    char c = getchar();
    clearInputBuffer();
    int i = 0;
    while (validChars[i] != '\0') {
      if (c == validChars[i]) {
        *choice = c;
        return;
      }
      ++i;
    }
    printf("Invalid input. Try again!\n");
  }
}

void clearInputBuffer() { fflush(stdin); }

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
