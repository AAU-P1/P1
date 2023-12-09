#ifndef PATIENT_H
#define PATIENT_H

// ################################## MODEL ##################################

enum Gender { Male, Female };

struct Patient {
  char name[100];
  int age;
  int id;
  enum Gender gender;
  struct Vitals *vitals;
  struct symptom_node *symptoms_head;
};

enum Triage_Level { Red, Orange, Yellow, Green, Blue };

enum Triage_Level get_triage(struct Patient patient);

struct patient_queue {
  struct patient_node *red_head;
  struct patient_node *orange_head;
  struct patient_node *yellow_head;
  struct patient_node *green_head;
  struct patient_node *blue_head;
  int current_id;
};

struct patient_node {
  void *data;
  struct patient_node *next;
  struct patient_node *prev;
};

struct patient_node *insert_tail(struct patient_node *cl, void *el);
void add_patient_to_queue(struct patient_queue *patient_queue,
                          struct Patient patient);

void remove_patient_from_queue(struct patient_queue *pq, int p_id);

struct patient_node *remove_patient_from_list(struct patient_node *sl,
                                              int patient_id);

// ################################## VIEW ##################################

void print_patient(struct Patient *patient);
void print_circular_patient_list(struct patient_node *cl);
void print_queue(struct patient_queue *patient_queue);

// ################################ CONTROLLER ################################

struct Patient input_patient();
void remove_patient(struct patient_queue *pq);

#endif
