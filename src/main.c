#include "patient_queue.h"
#include "symptoms.h"
#include "vitals.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearInputBuffer();
void input_patient();
void input_vitals(struct Patient *patient);

int main(void) {

  // Make Anton and triage him
  struct Vitals anton_vitals;
  anton_vitals.airway = Free;
  anton_vitals.oxygen_saturation = 100;
  anton_vitals.with_oxygen = false;
  anton_vitals.with_kol = false;
  anton_vitals.respiration_frequency = 10;
  anton_vitals.pulse = 60;
  anton_vitals.systolic_blood_pressure = 100;
  anton_vitals.glasgow_coma_scale = 10;
  anton_vitals.temperature_celcius = 37;

  struct Patient patient;
  strcpy(patient.name, "Anton");
  patient.age = 21;
  patient.gender = Female;
  patient.vitals = &anton_vitals;
  patient.symptoms_head = NULL;

  printf("triage_level anton: %d\n", get_triage(patient));

  char choice;

  printf("(T)riage new patient      (I)nput patient from file       (R)emove "
         "Patient         (D)isplay Queue\n");
  choice = getchar();
  clearInputBuffer();

  switch (choice) {
  case 'T':
  case 't':
    input_patient();
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
  default:
    printf("Invalid input try again");
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

void input_char(char *choice, char *message, char *valid_chars,
                int len_valid_chars) {
  while (true) {
    printf("%s\n", message);
    char c = getchar();
    clearInputBuffer();
    for (int i = 0; i < len_valid_chars; ++i) {
      if (c == valid_chars[i]) {
        choice = &c;
        return;
      }
    }
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

void input_patient() {

  struct Patient patient;

  // Get patient Name
  input_string("input patient name", patient.name);

  // Get patient Age
  input_int("Input patient age", &patient.age);

  // Get patient Gender
  char choice;
  int len_valid_chars = 2;
  char *valid_chars = (char *)malloc(len_valid_chars * sizeof(char));
  input_char(&choice, "Input patient gender, (M)ale or (F)emale", valid_chars,
             len_valid_chars);
  switch (choice) {
  case 'M':
  case 'm':
    patient.gender = Male;
    break;
  case 'F':
  case 'f':
    patient.gender = Female;
    break;
  default:
    printf("We only recognize two genders ;). Try again sissy!\n");
  }

  // Get patient Vitals
  input_vitals(&patient);
}

void input_vitals(struct Patient *patient) {
  bool airway_found = false;
  while (!airway_found) {
    char choice;
    printf("Is the airway: (B)locked (F)ree or (I)nspiratory Stridor?\n");
    choice = getchar();
    clearInputBuffer();

    switch (choice) {
    case 'B':
    case 'b':
      patient->vitals->airway = Blocked;
      airway_found = true;
      break;
    case 'F':
    case 'f':
      patient->vitals->airway = Free;
      airway_found = true;
      break;
    case 'I':
    case 'i':
      patient->vitals->airway = Inspiratory_stridor;
      airway_found = true;
      break;
    default:
      printf("Invalid input. Try again!");
    }
  }

  patient->vitals->oxygen_saturation =
      input_int("Input patient Oxygen Saturation");

  bool with_oxygen_found = false;
  while (!with_oxygen_found) {
    printf("Is the patient with oxygen? (Y)es  (N)o\n");
    char choice;
    choice = getchar();
    clearInputBuffer();
    switch (choice) {
    case 'Y':
    case 'y':
      patient->vitals->with_oxygen = true;
      with_oxygen_found = true;
      break;
    case 'N':
    case 'n':
      patient->vitals->with_oxygen = false;
      with_oxygen_found = true;
      break;
    default:
      printf("Invalid input. Try again!");
    }
  }

  void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
  }
