#ifndef PATIENT_QUEUE_H
#define PATIENT_QUEUE_H

#include "triage_level.h"

struct patient_queue {
  struct patient_node *red_head;
  struct patient_node *orange_head;
  struct patient_node *yellow_head;
  struct patient_node *green_head;
  struct patient_node *blue_head;
};

struct patient_node {
  void *data;
  struct patient_node *next;
};

enum Gender { Male, Female };

struct Patient {
  char name[100];
  int age;
  int id;
  enum Gender gender;
  struct Vitals *vitals;
  struct symptom_node *symptoms_head;
};

enum Triage_Level get_triage(struct Patient patient);

void add_patient_to_queue(struct patient_queue *patient_queue,
                          struct Patient patient);

struct patient_node *insert_tail(struct patient_node *cl, void *el);
void print_patient(struct Patient *patient);
void print_circular_patient_list(struct patient_node *cl);
void print_queue(struct patient_queue *patient_queue);

#endif
