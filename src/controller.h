#ifndef CONTROLLER_H
#define CONTROLLER_H

void inputIntWithRange(char *message, int *dest, int low, int high);
void inputIntWithMin(char *message, int *dest, int low);
void inputDouble(char *message, double *dest);
void inputChar(char *choice, char *message, char *validChars);
void inputString(char *message, char *dest);
void clearInputBuffer();
void clearScreen();

#endif
