#include "patient_queue_gui.h"
#include "gui.h"
#include "stdlib.h"
#include <stdio.h>

void print_patient(struct Patient *patient) {
  printf("name:%s age:%d id:%d\n", patient->name, patient->age, patient->id);
}

void print_circular_patient_list(struct patient_node *cl) {
  struct patient_node *cur;

  if (cl == NULL) {
    return;
  }
  cur = cl;

  do {
    print_patient(cur->data);
    cur = cur->next;
  } while (cur != NULL);
}

void print_queue(struct patient_queue *patient_queue) {
  clear_screen();
  printf("\nRED:\n");
  print_circular_patient_list(patient_queue->red_head);
  printf("\nORANGE:\n");
  print_circular_patient_list(patient_queue->orange_head);
  printf("\nYELLOW:\n");
  print_circular_patient_list(patient_queue->yellow_head);
  printf("\nGREEN:\n");
  print_circular_patient_list(patient_queue->green_head);
  printf("\nBLUE:\n");
  print_circular_patient_list(patient_queue->blue_head);
  printf("\n");
}
