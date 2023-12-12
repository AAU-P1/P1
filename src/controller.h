#ifndef CONTROLLER_H
#define CONTROLLER_H

void input_int(char *message, int *dest);
void input_int_with_range(char *message, int *dest, int valid_low,
                          int valid_high);
void input_int_with_min(char *message, int *dest, int valid_low);
void input_double(char *message, double *dest);
void input_char(char *choice, char *message, char *valid_chars);
void input_string(char *message, char *dest);
void clear_input_buffer();
void clear_screen();

#endif
