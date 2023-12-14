#include "symptoms.h"
#include "input.h"
#include "symptoms/001_abstinence.h"
#include "symptoms/002_allergic_symptoms.h"
#include "triage_level.h"
#include <stdio.h>
#include <stdlib.h>

// ################################## MODEL ##################################

/*
 * returns triage level from list of symptoms
 * @param head: head of linked list
 */
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

/*
 * returns triage level of specific symptom
 * @param symptom: pointer to symptom to triage
 */
TriageLevel getSymptomTriage(SymptomNode *symptom) {
  if (symptom->symptomId == 1) {
    Abstinence *abstinence = (Abstinence *)symptom->data;
    return getSymptomAbstinenceTriage(*abstinence);
  } else if (symptom->symptomId == 2) {
    Allergic *allergic = (Allergic *)symptom->data;
    return getSymptomAllergicTriage(*allergic);
  }
  return T_BLUE;
}

/*
 * adds a symptom to a linked list
 * @param head: head of linked list
 * @param symptom: symptom to add to list
 * @param symptomId: id of symptom to add
 */
SymptomNode *addSymptomToList(SymptomNode *head, void *symptom, int symptomId) {
  SymptomNode *newNode = (SymptomNode *)malloc(sizeof(SymptomNode));
  if (newNode == NULL) {
    exit(EXIT_FAILURE);
  }

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

// ############################ CONTROLLER/VIEW #############################

/*
 * gets user to input symptom and add it to linked list of symptoms
 * @param head: head of linked list
 */
SymptomNode *inputSymptom(SymptomNode *head) {

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
