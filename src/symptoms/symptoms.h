#ifndef SYMPTOMS_H
#define SYMPTOMS_H

#include "../triage_level.h"
#include "001_abstinence.h"
#include "002_allergic_symptoms.h"

struct symptom_node {
  void *data;
  int symptom_id;
  struct symptom_node *next;
};

enum Triage_Level get_symptoms_triage(struct symptom_node *symptom_node);
enum Triage_Level triage_from_symptom(struct symptom_node *sn);
#endif
