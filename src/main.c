#include "patient_queue.h"
#include "symptoms/001_abstinence.h"
#include "symptoms/symptoms.h"
#include "triage_level.h"
#include "view/gui.h"
#include "view/patient_queue_gui.h"
#include "view/symptoms_gui.h"
#include "view/vitals_gui.h"
#include "vitals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearInputBuffer();
struct Patient input_patient();
void input_vitals(struct Vitals *vitals);
void remove_patient(struct patient_queue *pq);
void input_symptoms(struct symptom_node *sn);
struct Abstinence *input_abstinence_symptom();
int main(void) {

  struct patient_queue patient_queue = {NULL, NULL, NULL, NULL, NULL, 1};

  char choice;
  clear_screen();
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
      remove_patient(&patient_queue);
      print_queue(&patient_queue);
      break;
    case 'D':
    case 'd':
      print_queue(&patient_queue);
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

void remove_patient(struct patient_queue *pq) {
  int id;
  clear_screen();
  print_queue(pq);
  input_int("Input id of patient", &id);
  remove_patient_from_queue(pq, id);
}

struct Patient input_patient() {

  struct Patient patient;

  // Get patient Name
  clear_screen();
  input_string("input patient name", patient.name);

  // Get patient Age
  clear_screen();
  input_int("Input patient age", &patient.age);

  // Get patient Gender
  char choice;
  clear_screen();
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
  clear_screen();
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

  // Get patient Symptoms
  clear_screen();
  input_char(&choice, "Would you like to input Symptoms? (Y)es  (N)o", "YyNn");
  switch (choice) {
  case 'Y':
  case 'y':
    input_symptoms(patient.symptoms_head);
    break;
  case 'N':
  case 'n':
    patient.symptoms_head = NULL;
    break;
  }

  return patient;
}
