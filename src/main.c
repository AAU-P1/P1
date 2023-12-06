#include "patient_queue.h"
#include "symptoms.h"
#include "vitals.h"
#include <ncurses.h>
#include <stdio.h>
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
    triage_new_patient();
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

int input_int(char *message) {
  bool found = false;
  while (found == false) {
    printf("%s\n", message);
    int number;
    int res = scanf("%d", &number);
    clearInputBuffer();
    if (res != 1) {
      printf("Invalid input. Try again!\n");
    } else {
      found = true;
      return number;
    }
  }
}

void input_patient() {

  struct Patient patient;

  bool name_found = false;
  while (!name_found) {
    printf("Input patient name\n");
    int res = scanf("%s", &patient.name);
    clearInputBuffer();
    if (res != 1) {
      printf("Invalid input. Try again!\n");
    } else {
      name_found = true;
    }
  }

  patient.age = input_int("Input patient age");

  bool gender_found = false;
  while (!gender_found) {
    char choice;
    printf("Input patient gender, (M)ale or (F)emale\n");
    choice = getchar();
    clearInputBuffer();

    switch (choice) {
    case 'M':
    case 'm':
      patient.gender = Male;
      gender_found = true;
      break;
    case 'F':
    case 'f':
      patient.gender = Female;
      gender_found = true;
      break;
    default:
      printf("We only recognize two genders ;). Try again sissy!\n");
    }
  }

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

  bool oxygen_saturation_found = false;
  while (!oxygen_saturation_found) {
    printf("Input patient Oxygen Saturation\n");
    int res = scanf("%d", &patient->vitals->oxygen_saturation);
    clearInputBuffer();
    if (res != 1) {
      printf("Invalid input. Try again!\n");
    } else {
      oxygen_saturation_found = true;
    }
  }

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

  bool oxygen_saturation_found = false;
  while (!oxygen_saturation_found) {
    printf("Input patient Oxygen Saturation\n");
    int res = scanf("%d", &patient->vitals->oxygen_saturation);
    clearInputBuffer();
    if (res != 1) {
      printf("Invalid input. Try again!\n");
    } else {
      oxygen_saturation_found = true;
    }
  }
}

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}
