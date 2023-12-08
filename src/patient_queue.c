#include "patient_queue.h"
#include "triage_level.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct patient_node *insert_tail(struct patient_node *cl, void *el) {
  struct patient_node *new_node =
      (struct patient_node *)malloc(sizeof(struct patient_node));
  new_node->data = el;
  new_node->next = NULL;

  if (cl == NULL) {
    return new_node;
  }
  cl->next = new_node;
  return cl;
}

void remove_patient_from_queue(struct patient_queue *pq, int p_id) {
  pq->red_head = remove_patient_from_list(pq->red_head, p_id);
  pq->orange_head = remove_patient_from_list(pq->orange_head, p_id);
  pq->yellow_head = remove_patient_from_list(pq->yellow_head, p_id);
  pq->green_head = remove_patient_from_list(pq->green_head, p_id);
  pq->blue_head = remove_patient_from_list(pq->blue_head, p_id);
}

struct patient_node *remove_patient_from_list(struct patient_node *sl,
                                              int patient_id) {
  if (sl == NULL) {
    return sl;
  }

  struct patient_node *cur, *prev;
  cur = sl;
  prev = NULL;

  do {
    struct Patient *patient = (struct Patient *)cur->data;
    if (patient->id == patient_id) {

      if (prev == NULL) {
        struct patient_node *new_head = cur->next;
        free(cur);
        return new_head;
      } else {
        prev->next = cur->next;
        free(cur);
      }
    }
    prev = cur;
    cur = cur->next;
  } while (cur != NULL);
  return sl;
}

void add_patient_to_queue(struct patient_queue *patient_queue,
                          struct Patient patient) {

  struct Patient *new_patient =
      (struct Patient *)malloc(sizeof(struct Patient));

  // Check if memory allocation is successful
  if (new_patient == NULL) {
    printf("Error: Unable to allocate memory for patient\n");
    exit(EXIT_FAILURE);
  }

  // Copy patient data
  *new_patient = patient;

  new_patient->id = patient_queue->current_id;
  patient_queue->current_id++;

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
