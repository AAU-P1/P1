#ifndef SYMPTOMS_H
#define SYMPTOMS_H

#include "symptoms/001_abstinence.h"
#include "symptoms/002_allergic_symptoms.h"
#include "triage_level.h"

// ################################## MODEL ##################################

struct symptom_node {
  void *data;
  int symptom_id;
  struct symptom_node *next;
};

enum Triage_Level get_symptoms_triage(struct symptom_node *symptom_node);
enum Triage_Level triage_from_symptom(struct symptom_node *sn);

// ################################ CONTROLLER ################################

struct symptom_node *input_symptoms(struct symptom_node *sn);
#endif
