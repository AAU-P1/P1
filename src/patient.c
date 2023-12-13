#include "patient.h"
#include "controller.h"
#include "symptoms.h"
#include "triage_level.h"
#include "vitals.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ################################## MODEL ##################################

struct patient_node *insert_tail(struct patient_node *sl, void *el) {
  struct patient_node *new_node =
      (struct patient_node *)malloc(sizeof(struct patient_node));

  struct patient_node *cur;

  new_node->data = el;
  new_node->next = NULL;

  if (sl == NULL) {
    return new_node;
  }
  cur = sl;

  while (cur->next != NULL) {
    cur = cur->next;
  }

  cur->next = new_node;
  return sl;
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
        return sl;
      }
    }
    prev = cur;
    cur = cur->next;
  } while (cur != NULL);
  return sl;
}

void add_patient_to_queue(struct patient_queue *patient_queue,
                          struct Patient *patient, int id) {

  patient->id = id;

  switch (patient->triage_level) {
  case Red:
    patient_queue->red_head = insert_tail(patient_queue->red_head, patient);
    break;
  case Orange:
    patient_queue->orange_head =
        insert_tail(patient_queue->orange_head, patient);
    break;
  case Yellow:
    patient_queue->yellow_head =
        insert_tail(patient_queue->yellow_head, patient);
    break;
  case Green:
    patient_queue->green_head = insert_tail(patient_queue->green_head, patient);
    break;
  case Blue:
    patient_queue->blue_head = insert_tail(patient_queue->blue_head, patient);
    break;
  }
}

void get_triage(struct Patient *patient) {

  patient->triage_level = Blue;

  if (patient->vitals) {
    patient->triage_level = get_vital_triage(*patient->vitals);
  }

  if (patient->symptoms_head) {
    enum Triage_Level symptoms_triage =
        get_symptoms_triage(patient->symptoms_head);

    if (patient->triage_level > symptoms_triage) {
      patient->triage_level = symptoms_triage;
    }
  }
}

// ################################## VIEW ##################################

void print_patient(struct Patient *p) {
  printf("name:%s, age:%d, id:%d, gender:%d\n", p->name, p->age, p->id,
         p->gender);
}

void print_circular_patient_list(struct patient_node *sl) {
  struct patient_node *cur;

  if (sl == NULL) {
    return;
  }
  cur = sl;

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

void print_triage_level_pov(struct patient_node *sl, int id, char *message,
                            bool *pf) {
  if (*pf || sl == NULL) {
    return;
  }

  struct patient_node *cur = sl;
  int count = 0;

  do {
    struct Patient *patient = (struct Patient *)cur->data;
    if (patient->id == id) {
      *pf = true;
      break;
    }
    count++;
    cur = cur->next;
  } while (cur != NULL);

  if (count > 0) {
    printf("%s: %d\n", message, count);
  }
}

void print_queue_patient_pov(struct patient_queue *pq, int id) {
  clear_screen();
  printf("Patients in front of you:\n");
  bool patient_found = false;
  print_triage_level_pov(pq->red_head, id, "RED", &patient_found);
  print_triage_level_pov(pq->orange_head, id, "ORANGE", &patient_found);
  print_triage_level_pov(pq->yellow_head, id, "YELLOW", &patient_found);
  print_triage_level_pov(pq->green_head, id, "GREEN", &patient_found);
  print_triage_level_pov(pq->blue_head, id, "BLUE", &patient_found);
  printf("\n");
}

// ################################ CONTROLLER ################################

void input_patient_name(struct Patient *patient) {
  // Get patient Name
  clear_screen();

  while (true) {
    clear_input_buffer();
    printf("input patient name\n");
    int res = scanf("%99[^\n]", patient->name);
    if (res != 1) {
      printf("Invalid input. Try again!\n");
    } else {
      break;
    }
  }
}

struct Patient *input_patient() {

  struct Patient *patient = (struct Patient *)malloc(sizeof(struct Patient));
  patient->vitals = NULL;
  patient->symptoms_head = NULL;

  // Check if memory allocation is successful
  if (patient == NULL) {
    printf("Error: Unable to allocate memory for patient\n");
    exit(EXIT_FAILURE);
  }

  // Get patient Name
  input_patient_name(patient);

  // Get patient Age
  clear_screen();
  input_int_with_min("Input patient age", &patient->age, 0);

  // Get patient Gender
  char choice;
  clear_screen();
  input_char(&choice, "Input patient gender, (M)ale or (F)emale, (O)ther",
             "MmFfOo");
  switch (choice) {
  case 'M':
  case 'm':
    patient->gender = Male;
    break;
  case 'F':
  case 'f':
    patient->gender = Female;
    break;
  case 'O':
  case 'o':
    patient->gender = Other;
    break;
  }

  // Get patient Vitals
  clear_screen();
  input_char(&choice, "Would you like to input Vital Parameters? (Y)es  (N)o",
             "YyNn");
  switch (choice) {
  case 'Y':
  case 'y':
    patient->vitals = (struct Vitals *)malloc(sizeof(struct Vitals));
    input_vitals(patient->vitals);
    break;
  }

  get_triage(patient);

  if (patient->triage_level != Red) {

    // Get patient Symptoms
    clear_screen();
    input_char(&choice, "Would you like to input Symptoms? (Y)es  (N)o",
               "YyNn");
    switch (choice) {
    case 'Y':
    case 'y':
      patient->symptoms_head = input_symptoms(patient->symptoms_head);
      break;
    }
  }

  return patient;
}

void remove_patient(struct patient_queue *pq) {
  clear_screen();
  if (pq->red_head == NULL && pq->orange_head == NULL &&
      pq->yellow_head == NULL && pq->green_head == NULL &&
      pq->blue_head == NULL) {
    printf("There are no patients to remove. Please triage some patients!\n");
    return;
  }
  int id;
  print_queue(pq);
  input_int_with_range("Input id of patient", &id, 1, pq->current_id - 1);
  remove_patient_from_queue(pq, id);
  print_queue(pq);
}

void print_patient_pov(struct patient_queue *pq) {
  clear_screen();
  if (pq->red_head == NULL && pq->orange_head == NULL &&
      pq->yellow_head == NULL && pq->green_head == NULL &&
      pq->blue_head == NULL) {
    printf("There are no patients to print POV from. Please triage some "
           "patients!\n");
    return;
  }
  int id;
  print_queue(pq);
  input_int_with_range("Input id of patient", &id, 1, pq->current_id - 1);
  clear_screen();
  print_queue_patient_pov(pq, id);
}
