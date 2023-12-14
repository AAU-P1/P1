#ifndef SYMPTOMS_H
#define SYMPTOMS_H

#include "symptoms/001_abstinence.h"
#include "symptoms/002_allergic_symptoms.h"
#include "triage_level.h"

// ################################## MODEL ##################################

typedef struct SymptomNode SymptomNode;
struct SymptomNode {
  void *data;
  int symptomId;
  SymptomNode *next;
};

TriageLevel getSymptomListTriage(SymptomNode *head);
TriageLevel getSymptomTriage(SymptomNode *node);
SymptomNode *addSymptomToList(SymptomNode *head, void *symptom, int symptomId);

// ############################ CONTROLLER/VIEW ############################

SymptomNode *inputSymptom(SymptomNode *head);
#endif
