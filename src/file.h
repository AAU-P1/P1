#ifndef FILE_H
#define FILE_H
#include "patient.h"
#include <stdio.h>

void loadPatientQueueFromFile(PatientQueue *patientQueue);
void savePatientQueueToFile(PatientQueue *patientQueue);

void savePatientListToFile(PatientNode *list, FILE *file);
void savePatientToFile(Patient *patient, FILE *file);
#endif
