#include "patient_queue.h"
#include "symptoms.h"
#include "triage_level.h"
#include "vitals.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearInputBuffer();
void input_patient(struct patient_queue *patient_queue);
void input_vitals(struct Patient *patient);

int main(void) {

  struct patient_queue patient_queue;

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
    input_patient(&patient_queue);
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

void input_patient(struct patient_queue *patient_queue) {

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
    input_vitals(&patient);
    break;
  case 'N':
  case 'n':
    break;
  }

  add_patient_to_queue(patient_queue, patient);
  print_queue(patient_queue);
}

void input_vitals(struct Patient *patient) {

  patient->vitals = (struct Vitals *)malloc(sizeof(struct Vitals));

  char choice;

  input_char(&choice,
             "Is the airway: (B)locked (F)ree or (I)nspiratory Stridor?",
             "BbFfIi");

  switch (choice) {
  case 'B':
  case 'b':
    patient->vitals->airway = Blocked;
    break;
  case 'F':
  case 'f':
    patient->vitals->airway = Free;
    break;
  case 'I':
  case 'i':
    patient->vitals->airway = Inspiratory_stridor;
    break;
  }

  // Get patient_vitals Kol
  input_char(&choice, "Is the patient with kol? (Y)es  (N)o", "YyNn");
  switch (choice) {
  case 'Y':
  case 'y':
    patient->vitals->with_kol = true;
    break;
  case 'N':
  case 'n':
    patient->vitals->with_kol = false;
    break;
  }

  input_int("Input Oxygen Saturation", &patient->vitals->oxygen_saturation);

  // Get patient_vitals Airway
  input_char(&choice, "Is the patient with oxygen? (Y)es  (N)o", "YyNn");
  switch (choice) {
  case 'Y':
  case 'y':
    patient->vitals->with_oxygen = true;
    break;
  case 'N':
  case 'n':
    patient->vitals->with_oxygen = false;
    break;
  }

  input_int("Input Pulse", &patient->vitals->pulse);

  input_int("Input Systolic Blood Pressure",
            &patient->vitals->systolic_blood_pressure);

  input_int("Input Glasgow Coma Scale Number",
            &patient->vitals->glasgow_coma_scale);

  input_double("Input Temperature Celcius",
               &patient->vitals->temperature_celcius);
}
void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}
