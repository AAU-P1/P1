#include "patient_queue.h"
#include "symptoms.h"
#include "vitals.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct patient_queue {
  struct patient_node *red_head;
  struct patient_node *orange_head;
  struct patient_node *yellow_head;
  struct patient_node *green_head;
  struct patient_node *blue_head;
};

enum Triage_Level get_triage(struct Patient patient) {

  enum Triage_Level triage_level = Blue;

  if (patient.vitals != NULL) {
    triage_level = get_vital_triage(*patient.vitals);
  }

  if (patient.symptoms_head) {
    enum Triage_Level symptoms_triage =
        get_symptoms_triage(*patient.symptoms_head);

    if (triage_level > symptoms_triage) {
      return symptoms_triage;
    }
  }

  return triage_level;
}

struct patient_node *insert_tail(struct patient_node *cl, void *el) {
  struct patient_node *new_node =
      (struct patient_node *)malloc(sizeof(struct patient_node));
  new_node->next = cl->next;
  cl->next = new_node;
  cl = new_node;
  return cl;
}

void add_patient_to_queue(struct patient_queue *patient_queue,
                          struct Patient patient) {
  enum Triage_Level patient_triage_level = get_triage(patient);

  switch (patient_triage_level) {
  case Red:
    insert_tail(patient_queue->red_head, &patient);
    break;
  case Orange:
    insert_tail(patient_queue->orange_head, &patient);
    break;
  case Yellow:
    insert_tail(patient_queue->yellow_head, &patient);
    break;
  case Green:
    insert_tail(patient_queue->green_head, &patient);
    break;
  case Blue:
    insert_tail(patient_queue->blue_head, &patient);
    break;
  }
}
