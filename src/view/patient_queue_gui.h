#ifndef PATIENT_QUEUE
#define PATIENT_QUEUE
#include "../patient_queue.h"
void print_patient(struct Patient *patient);
void print_circular_patient_list(struct patient_node *cl);
void print_queue(struct patient_queue *patient_queue);
#endif
