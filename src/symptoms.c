#include "symptoms.h"
#include "controller.h"
#include "symptoms/001_abstinence.h"
#include "symptoms/002_allergic_symptoms.h"
#include "triage_level.h"
#include <stdio.h>
#include <stdlib.h>

// ################################## MODEL ##################################

TriageLevel getSymptomListTriage(SymptomNode *head) {
  TriageLevel triageLevel = T_BLUE;

  SymptomNode *cur;

  if (head == NULL) {
    return triageLevel;
  }
  cur = head;

  do {
    TriageLevel curTriage = getSymptomTriage(cur);
    if (triageLevel > curTriage) {
      triageLevel = curTriage;
    }
    cur = cur->next;
  } while (cur != NULL);

  return triageLevel;
}

TriageLevel getSymptomTriage(SymptomNode *node) {
  if (node->symptomId == 1) {
    Abstinence *abstinence = (Abstinence *)node->data;
    return getSymptomAbstinenceTriage(*abstinence);
  } else if (node->symptomId == 2) {
    Allergic *allergic = (Allergic *)node->data;
    return getSymptomAllergicTriage(*allergic);
  }
  return T_BLUE;
}

SymptomNode *addSymptomToList(SymptomNode *head, void *symptom, int symptomId) {
  SymptomNode *newNode = (SymptomNode *)malloc(sizeof(SymptomNode));

  SymptomNode *cur;

  newNode->data = symptom;
  newNode->symptomId = symptomId;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  cur = head;

  while (cur->next != NULL) {
    cur = cur->next;
  }

  cur->next = newNode;
  return head;
}

// ################################ CONTROLLER ################################

SymptomNode *inputSymptoms(SymptomNode *head) {

  int symptomId;

  clearScreen();
  inputIntWithRange(
      "Please choose one of the following:\n(1) Abstinence or (2) Allergic)",
      &symptomId, 1, 2);
  if (symptomId == 1) {
    Abstinence *abstinence = inputSymptomAbstinence();
    head = addSymptomToList(head, abstinence, symptomId);
  } else if (symptomId == 2) {
    Allergic *allergic = inputSymptomAllergic();
    head = addSymptomToList(head, allergic, symptomId);
  }
  return head;
}
