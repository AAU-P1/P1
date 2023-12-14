#include "input.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ############################ CONTROLLER/VIEW #############################

/*
 * requests int from user wihin valid range
 * @param message: message to be printed to user
 * @param dest: output parameter of where to save int
 * @param low: lowest valid int
 * @param high: highest valid int
 */
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

/*
 * requests int from user with minimum value
 * @param message: message to be printed to user
 * @param dest: output parameter of where to save int
 * @param low: lowest valid int
 */
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

/*
 * request double from user
 * @param message: message to be printed to user
 * @param dest: outout parameter of where to save double
 */
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

/*
 * request char from user, that match one of given valid chars
 * @param choice: output parameter of where to save char
 * @param message: message to print to user
 * @param validChars: string consisting of valid chars
 */
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

/*
 * Clears the input buffer
 */
void clearInputBuffer() { fflush(stdin); }

/*
 * Clears the screen, depending on OS
 */
void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
