#include "controller.h"
#include "file.h"
#include "patient.h"
#include "symptoms.h"
#include "symptoms/001_abstinence.h"
#include "vitals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  struct patient_queue patient_queue = {NULL, NULL, NULL, NULL, NULL, 1};

  load_patient_queue_from_file(&patient_queue);

  char choice;
  clear_screen();
  print_queue(&patient_queue);
  while (true) {
    printf("(T)riage new patient | (R)emove Patient | (D)isplay Queue "
           "| Display (P)OV Queue | (Q)uit\n");
    choice = getchar();
    clear_input_buffer();

    switch (choice) {
    case 'T':
    case 't': {
      struct Patient *patient = input_patient();
      get_triage(patient);
      add_patient_to_queue(&patient_queue, patient, patient_queue.current_id);
      patient_queue.current_id++;
      save_patient_queue_to_file(&patient_queue);
      print_queue(&patient_queue);
      break;
    }
    case 'R':
    case 'r':
      remove_patient(&patient_queue);
      save_patient_queue_to_file(&patient_queue);
      break;
    case 'D':
    case 'd':
      print_queue(&patient_queue);
      break;
    case 'P':
    case 'p':
      print_patient_pov(&patient_queue);
      break;
    case 'Q':
    case 'q':
      printf("Bye!\n");
      exit(1);
      break;
    default:
      printf("Invalid input try again\n");
    }
  }
}
