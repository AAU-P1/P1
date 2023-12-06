#include "patient_queue.h"
#include <stdio.h>
#include <stdlib.h>

struct patient_node *insert_tail(struct patient_node *cl, void *el) {
  if (cl == NULL) {
    printf("list empty\n");
    struct patient_node *new_node =
        (struct patient_node *)malloc(sizeof(struct patient_node));
    new_node->data = el;
    new_node->next = new_node;
    return new_node;
  } else {
    printf("list populated\n");
    struct patient_node *new_node =
        (struct patient_node *)malloc(sizeof(struct patient_node));
    new_node->data = el;
    new_node->next = cl->next;
    cl->next = new_node;
    return cl;
  }
  return cl;
}

void add_patient_to_queue(struct patient_queue *patient_queue,
                          struct Patient patient) {
  enum Triage_Level patient_triage_level = get_triage(patient);

  switch (patient_triage_level) {
  case Red:
    patient_queue->red_head = insert_tail(patient_queue->red_head, &patient);
    break;
  case Orange:
    patient_queue->orange_head =
        insert_tail(patient_queue->orange_head, &patient);
    break;
  case Yellow:
    patient_queue->yellow_head =
        insert_tail(patient_queue->yellow_head, &patient);
    break;
  case Green:
    patient_queue->green_head =
        insert_tail(patient_queue->green_head, &patient);
    break;
  case Blue:
    patient_queue->blue_head = insert_tail(patient_queue->blue_head, &patient);
    break;
  }
}

void print_patient(struct Patient *patient) {
  printf("%s %d\n", patient->name, patient->age);
}

void print_circular_patient_list(struct patient_node *cl) {
  struct patient_node *cur, *prev;

  if (cl == NULL) {
    return;
  }
  cur = cl->next;
  do {
    prev = cur;
    print_patient(cur->data);
    cur = cur->next;
  } while (prev != cl);
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
