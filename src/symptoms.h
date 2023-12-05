#ifndef SYMPTOMS_H
#define SYMPTOMS_H

#include "triage_level.h"

struct symptom_node {
  void *data;
  struct symptom_node *next;
};

enum Triage_Level get_symptoms_triage(struct symptom_node);

#endif
