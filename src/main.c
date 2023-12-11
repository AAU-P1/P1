#include "controller.h"
#include "patient.h"
#include "symptoms.h"
#include "symptoms/001_abstinence.h"
#include "vitals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearInputBuffer();
struct Patient input_patient();
void input_vitals(struct Vitals *vitals);
void remove_patient(struct patient_queue *pq);
void input_symptoms(struct symptom_node *sn);
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
