#include "patient_queue.h"
#include "symptoms.h"
#include "triage_level.h"
#include "vitals.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearInputBuffer();
struct Patient input_patient();
void input_vitals(struct Vitals *vitals);
int main(void) {

  struct patient_queue patient_queue = {NULL, NULL, NULL, NULL, NULL};

  char choice;
  while (true) {
    printf("(T)riage new patient      (I)nput patient from file       (R)emove "
           "Patient         (D)isplay Queue        (Q)uit\n");
    choice = getchar();
    clearInputBuffer();

    switch (choice) {
    case 'T':
    case 't':
      add_patient_to_queue(&patient_queue, input_patient());
      print_queue(&patient_queue);
      break;
    case 'I':
    case 'i':
      break;
    case 'R':
    case 'r':
      break;
    case 'D':
    case 'd':
      break;
    case 'Q':
    case 'q':
      printf("Bye!\n");
      exit(1);
      break;
    default:
      printf("Invalid input try again");
    }
  }
}

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

struct Patient input_patient() {

  struct Patient patient;

  // Get patient Name
  input_string("input patient name", patient.name);

  // Get patient Age
  input_int("Input patient age", &patient.age);

  // Get patient Gender
  char choice;
  input_char(&choice, "Input patient gender, (M)ale or (F)emale", "MmFf");
  switch (choice) {
  case 'M':
  case 'm':
    patient.gender = Male;
    break;
  case 'F':
  case 'f':
    patient.gender = Female;
    break;
  }

  // Get patient Vitals
  input_char(&choice, "Would you like to input Vital Parameters? (Y)es  (N)o",
             "YyNn");
  switch (choice) {
  case 'Y':
  case 'y':
    patient.vitals = (struct Vitals *)malloc(sizeof(struct Vitals));
    input_vitals(patient.vitals);
    break;
  case 'N':
  case 'n':
    patient.vitals = NULL;
    break;
  }

  return patient;
}

void input_vitals(struct Vitals *vitals) {

  char choice;

  input_char(&choice,
             "Is the airway: (B)locked (F)ree or (I)nspiratory Stridor?",
             "BbFfIi");

  switch (choice) {
  case 'B':
  case 'b':
    vitals->airway = Blocked;
    break;
  case 'F':
  case 'f':
    vitals->airway = Free;
    break;
  case 'I':
  case 'i':
    vitals->airway = Inspiratory_stridor;
    break;
  }

  // Get patient_vitals Kol
  input_char(&choice, "Is the patient with kol? (Y)es  (N)o", "YyNn");
  switch (choice) {
  case 'Y':
  case 'y':
    vitals->with_kol = true;
    break;
  case 'N':
  case 'n':
    vitals->with_kol = false;
    break;
  }

  input_int("Input Oxygen Saturation", &vitals->oxygen_saturation);

  // Get patient_vitals Airway
  input_char(&choice, "Is the patient with oxygen? (Y)es  (N)o", "YyNn");
  switch (choice) {
  case 'Y':
  case 'y':
    vitals->with_oxygen = true;
    break;
  case 'N':
  case 'n':
    vitals->with_oxygen = false;
    break;
  }

  input_int("Input Respiration Frequency", &vitals->respiration_frequency);

  input_int("Input Pulse", &vitals->pulse);

  input_int("Input Systolic Blood Pressure", &vitals->systolic_blood_pressure);

  input_int("Input Glasgow Coma Scale Number", &vitals->glasgow_coma_scale);

  input_double("Input Temperature Celcius", &vitals->temperature_celcius);
}
void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}
