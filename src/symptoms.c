#include "symptoms.h"
#include "controller.h"
#include <stdio.h>
#include <stdlib.h>

// ################################## MODEL ##################################

enum Triage_Level get_symptoms_triage(struct symptom_node *sn) {
  enum Triage_Level triage_level = Blue;

  struct symptom_node *cur;

  if (sn == NULL) {
    return triage_level;
  }
  cur = sn;

  do {
    enum Triage_Level cur_triage = triage_from_symptom(sn);
    if (triage_level > cur_triage) {
      triage_level = cur_triage;
    }
    cur = cur->next;
  } while (cur != NULL);

  return triage_level;
}

enum Triage_Level triage_from_symptom(struct symptom_node *sn) {
  if (sn->symptom_id == 1) {
    struct Abstinence *abstinence = (struct Abstinence *)sn->data;
    return (get_symptoms_abstinence_triage(*abstinence));
  }
  return Blue;
}

struct symptom_node *add_symptom(struct symptom_node *cl, void *el,
                                 int symptom_id) {
  struct symptom_node *new_node =
      (struct symptom_node *)malloc(sizeof(struct symptom_node));
  new_node->data = el;
  new_node->symptom_id = symptom_id;
  new_node->next = NULL;

  if (cl == NULL) {
    return new_node;
  }
  cl->next = new_node;
  return cl;
}

// ################################ CONTROLLER ################################

struct symptom_node *input_symptoms(struct symptom_node *sn) {

  int symptom_id;

  clear_screen();
  input_int_with_range("Please choose one of the following:\n(1) or ...",
                       &symptom_id, 1, 1);
  if (symptom_id == 1) {
    struct Abstinence *abstinence = input_abstinence_symptom();
    sn = add_symptom(sn, abstinence, symptom_id);
  }
  return sn;
}
