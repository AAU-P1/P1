#include "file.h"
#include "patient.h"
#include <stdio.h>
#include <stdlib.h>

void loadPatientQueueFromFile(PatientQueue *patientQueue) {
  FILE *file;

  file = fopen("STATE", "r");

  if (file == NULL) {
    return;
  }

  char line[128];

  while (fgets(line, sizeof(line), file)) {
    /* note that fgets don't strip the terminating \n, checking its
       presence would allow to handle lines longer that sizeof(line) */
    Patient *patient = (Patient *)malloc(sizeof(Patient));

    sscanf(line, "%99[^,],%d,%d,%d,%d\n", patient->name, &patient->age,
           &patient->id, &patient->triageLevel, &patient->gender);

    addPatientToQueue(patientQueue, patient, patient->id);
    if (patient->id >= patientQueue->currentId) {
      patientQueue->currentId = patient->id + 1;
    }
  }

  fclose(file);
}
void savePatientQueueToFile(PatientQueue *patientQueue) {
  FILE *file;

  // Open a file in writing mode
  file = fopen("STATE", "w");

  savePatientListToFile(patientQueue->redHead, file);
  savePatientListToFile(patientQueue->orangeHead, file);
  savePatientListToFile(patientQueue->yellowHead, file);
  savePatientListToFile(patientQueue->greenHead, file);
  savePatientListToFile(patientQueue->blueHead, file);

  fclose(file);
}

void savePatientListToFile(PatientNode *list, FILE *file) {

  PatientNode *cur;

  if (list == NULL) {
    return;
  }
  cur = list;

  do {
    Patient *patient = (Patient *)cur->data;
    savePatientToFile(patient, file);
    cur = cur->next;
  } while (cur != NULL);
}

void savePatientToFile(Patient *patient, FILE *file) {

  fprintf(file, "%s,%d,%d,%d,%d\n", patient->name, patient->age, patient->id,
          patient->triageLevel, patient->gender);
}
