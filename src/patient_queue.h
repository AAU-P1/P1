#ifndef PATIENT_QUEUE_H
#define PATIENT_QUEUE_H

#include "triage_level.h"

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

#endif
