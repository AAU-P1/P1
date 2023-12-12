#ifndef FILE_H
#define FILE_H
#include "patient.h"
#include <stdio.h>

void load_patient_queue_from_file(struct patient_queue *pq);
void save_patient_queue_to_file(struct patient_queue *pq);

void save_patient_list_to_file(struct patient_node *sl, FILE *file);
void save_patient_to_file(struct Patient *p, FILE *file);
#endif
