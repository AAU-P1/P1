#include "patient_queue.h"
#include <stdio.h>
#include <stdlib.h>

struct patient_node *insert_tail(struct patient_node *cl, void *el) {
  struct patient_node *new_node =
      (struct patient_node *)malloc(sizeof(struct patient_node));
  new_node->data = el;
  new_node->next = NULL;

  if (cl == NULL) {
    printf("list empty\n");
    return new_node;
  }
  printf("list populated\n");
  cl->next = new_node;
  return cl;
}

void add_patient_to_queue(struct patient_queue *patient_queue,
                          struct Patient patient) {

  struct Patient *new_patient =
      (struct Patient *)malloc(sizeof(struct Patient));

  // Check if memory allocation is successful
  if (new_patient == NULL) {
    fprintf(stderr, "Error: Unable to allocate memory for patient\n");
    exit(EXIT_FAILURE);
  }

  // Copy patient data
  *new_patient = patient;

  enum Triage_Level patient_triage_level = get_triage(*new_patient);

  switch (patient_triage_level) {
  case Red:
    patient_queue->red_head = insert_tail(patient_queue->red_head, new_patient);
    break;
  case Orange:
    patient_queue->orange_head =
        insert_tail(patient_queue->orange_head, new_patient);
    break;
  case Yellow:
    patient_queue->yellow_head =
        insert_tail(patient_queue->yellow_head, new_patient);
    break;
  case Green:
    patient_queue->green_head =
        insert_tail(patient_queue->green_head, new_patient);
    break;
  case Blue:
    patient_queue->blue_head =
        insert_tail(patient_queue->blue_head, new_patient);
    break;
  }
}

void print_patient(struct Patient *patient) {
  printf("%s %d\n", patient->name, patient->age);
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
  printf("RED:\n");
  print_circular_patient_list(patient_queue->red_head);
  printf("ORANGE:\n");
  print_circular_patient_list(patient_queue->orange_head);
  printf("YELLOW:\n");
  print_circular_patient_list(patient_queue->yellow_head);
  printf("GREEN:\n");
  print_circular_patient_list(patient_queue->green_head);
  printf("BLUE:\n");
  print_circular_patient_list(patient_queue->blue_head);
}
