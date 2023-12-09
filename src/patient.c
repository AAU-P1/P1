#include "patient.h"
#include "controller.h"
#include "symptoms.h"
#include "vitals.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ################################## MODEL ##################################

struct patient_node *insert_tail(struct patient_node *cl, void *el) {
  struct patient_node *new_node =
      (struct patient_node *)malloc(sizeof(struct patient_node));
  new_node->data = el;
  new_node->next = NULL;

  if (cl == NULL) {
    return new_node;
  }
  cl->next = new_node;
  return cl;
}

void remove_patient_from_queue(struct patient_queue *pq, int p_id) {
  pq->red_head = remove_patient_from_list(pq->red_head, p_id);
  pq->orange_head = remove_patient_from_list(pq->orange_head, p_id);
  pq->yellow_head = remove_patient_from_list(pq->yellow_head, p_id);
  pq->green_head = remove_patient_from_list(pq->green_head, p_id);
  pq->blue_head = remove_patient_from_list(pq->blue_head, p_id);
}

struct patient_node *remove_patient_from_list(struct patient_node *sl,
                                              int patient_id) {
  if (sl == NULL) {
    return sl;
  }

  struct patient_node *cur, *prev;
  cur = sl;
  prev = NULL;

  do {
    struct Patient *patient = (struct Patient *)cur->data;
    if (patient->id == patient_id) {

      if (prev == NULL) {
        struct patient_node *new_head = cur->next;
        free(cur);
        return new_head;
      } else {
        prev->next = cur->next;
        free(cur);
      }
    }
    prev = cur;
    cur = cur->next;
  } while (cur != NULL);
  return sl;
}

void add_patient_to_queue(struct patient_queue *patient_queue,
                          struct Patient patient) {

  struct Patient *new_patient =
      (struct Patient *)malloc(sizeof(struct Patient));

  // Check if memory allocation is successful
  if (new_patient == NULL) {
    printf("Error: Unable to allocate memory for patient\n");
    exit(EXIT_FAILURE);
  }

  // Copy patient data
  *new_patient = patient;

  new_patient->id = patient_queue->current_id;
  patient_queue->current_id++;

  get_triage(*new_patient);

  switch (patient.triage_level) {
  case Red:
    patient_queue->red_head = insert_tail(patient_queue->red_head, new_patient);
    break;
  case Orange:
    patient_queue->orange_head =
        insert_tail(patient_queue->orange_head, new_patient);
    break;
  case Yellow:
    patient_queue->yellow_head =
        insert_tail(patient_queue->yellow_head, new_patient);
    break;
  case Green:
    patient_queue->green_head =
        insert_tail(patient_queue->green_head, new_patient);
    break;
  case Blue:
    patient_queue->blue_head =
        insert_tail(patient_queue->blue_head, new_patient);
    break;
  }
}

// ################################## VIEW ##################################

void print_patient(struct Patient *patient) {
  printf("name:%s age:%d id:%d\n", patient->name, patient->age, patient->id);
}

void print_circular_patient_list(struct patient_node *cl) {
  struct patient_node *cur;

  if (cl == NULL) {
    return;
  }
  cur = cl;

  do {
    print_patient(cur->data);
    cur = cur->next;
  } while (cur != NULL);
}

void print_queue(struct patient_queue *patient_queue) {
  clear_screen();
  printf("\nRED:\n");
  print_circular_patient_list(patient_queue->red_head);
  printf("\nORANGE:\n");
  print_circular_patient_list(patient_queue->orange_head);
  printf("\nYELLOW:\n");
  print_circular_patient_list(patient_queue->yellow_head);
  printf("\nGREEN:\n");
  print_circular_patient_list(patient_queue->green_head);
  printf("\nBLUE:\n");
  print_circular_patient_list(patient_queue->blue_head);
  printf("\n");
}

void get_triage(struct Patient patient) {

  patient.triage_level = Blue;

  if (patient.vitals) {
    patient.triage_level = get_vital_triage(*patient.vitals);
  }

  if (patient.symptoms_head) {
    enum Triage_Level symptoms_triage =
        get_symptoms_triage(patient.symptoms_head);

    if (patient.triage_level > symptoms_triage) {
      patient.triage_level = symptoms_triage;
    }
  }
}

// ################################ CONTROLLER ################################

struct Patient input_patient() {

  struct Patient patient;

  // Get patient Name
  clear_screen();
  input_string("input patient name", patient.name);

  // Get patient Age
  clear_screen();
  input_int("Input patient age", &patient.age);

  // Get patient Gender
  char choice;
  clear_screen();
  input_char(&choice, "Input patient gender, (M)ale or (F)emale", "MmFf");
  switch (choice) {
  case 'M':
  case 'm':
    patient.gender = Male;
    break;
  case 'F':
  case 'f':
    patient.gender = Female;
    break;
  }

  // Get patient Vitals
  clear_screen();
  input_char(&choice, "Would you like to input Vital Parameters? (Y)es  (N)o",
             "YyNn");
  switch (choice) {
  case 'Y':
  case 'y':
    patient.vitals = (struct Vitals *)malloc(sizeof(struct Vitals));
    input_vitals(patient.vitals);
    break;
  case 'N':
  case 'n':
    patient.vitals = NULL;
    break;
  }

  // Get patient Symptoms
  clear_screen();
  input_char(&choice, "Would you like to input Symptoms? (Y)es  (N)o", "YyNn");
  switch (choice) {
  case 'Y':
  case 'y':
    input_symptoms(patient.symptoms_head);
    break;
  case 'N':
  case 'n':
    patient.symptoms_head = NULL;
    break;
  }

  return patient;
}

void remove_patient(struct patient_queue *pq) {
  int id;
  clear_screen();
  print_queue(pq);
  input_int("Input id of patient", &id);
  remove_patient_from_queue(pq, id);
}
