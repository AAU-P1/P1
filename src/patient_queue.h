#ifndef PATIENT_QUEUE_H
#define PATIENT_QUEUE_H

#include "triage_level.h"

struct patient_queue {
  struct patient_node *red_head;
  struct patient_node *orange_head;
  struct patient_node *yellow_head;
  struct patient_node *green_head;
  struct patient_node *blue_head;
  int current_id;
};

struct patient_node {
  void *data;
  struct patient_node *next;
  struct patient_node *prev;
};

struct patient_node *insert_tail(struct patient_node *cl, void *el);
void add_patient_to_queue(struct patient_queue *patient_queue,
                          struct Patient patient);

void remove_patient_from_queue(struct patient_queue *pq, int p_id);

struct patient_node *remove_patient_from_list(struct patient_node *sl,
                                              int patient_id);
void print_patient(struct Patient *patient);
void print_circular_patient_list(struct patient_node *cl);
void print_queue(struct patient_queue *patient_queue);

#endif
