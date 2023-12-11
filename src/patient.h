#ifndef PATIENT_H
#define PATIENT_H
#include "triage_level.h"

// ################################## MODEL ##################################

enum Gender { Male, Female };

struct Patient {
  char name[100];
  int age;
  int id;
  enum Triage_Level triage_level;
  enum Gender gender;
  struct Vitals *vitals;
  struct symptom_node *symptoms_head;
};

void get_triage(struct Patient patient);

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
};

struct patient_node *insert_tail(struct patient_node *sl, void *el);
void add_patient_to_queue(struct patient_queue *patient_queue,
                          struct Patient patient);

void remove_patient_from_queue(struct patient_queue *pq, int p_id);

struct patient_node *remove_patient_from_list(struct patient_node *sl,
                                              int patient_id);

// ################################## VIEW ##################################

void print_patient(struct Patient *patient);
void print_circular_patient_list(struct patient_node *sl);
void print_queue(struct patient_queue *patient_queue);

// ################################ CONTROLLER ################################

struct Patient input_patient();
void remove_patient(struct patient_queue *pq);

#endif
