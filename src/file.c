#include "file.h"
#include "patient.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Loads a patient queue stored in a file into a patient queue
 * @param patientQueue: output parameter to load patient queue into
 */
void loadPatientQueueFromFile(PatientQueue *patientQueue) {
  FILE *file;

  file = fopen("STATE", "r");

  if (file == NULL) {
    return;
  }

  char line[128];

  while (fgets(line, sizeof(line), file)) {
    Patient *patient = (Patient *)malloc(sizeof(Patient));
    if (patient == NULL) {
      exit(EXIT_FAILURE);
    }

    sscanf(line, "%99[^,],%d,%d,%d,%d\n", patient->name, &patient->age,
           &patient->id, &patient->triageLevel, &patient->gender);

    addPatientToQueue(patientQueue, patient, patient->id);
    if (patient->id >= patientQueue->currentId) {
      patientQueue->currentId = patient->id + 1;
    }
  }

  fclose(file);
}

/*
 * Saves a PatientQeuue struct to file
 * @param patientQueue: pointer to patient queue to be saved
 */
void savePatientQueueToFile(PatientQueue *patientQueue) {
  FILE *file;

  file = fopen("STATE", "w");

  savePatientListToFile(patientQueue->redHead, file);
  savePatientListToFile(patientQueue->orangeHead, file);
  savePatientListToFile(patientQueue->yellowHead, file);
  savePatientListToFile(patientQueue->greenHead, file);
  savePatientListToFile(patientQueue->blueHead, file);

  fclose(file);
}

/*
 * Saves a linked list of patients to file
 * @param head: pointer to head of linked list of patients
 * @param file: pointer to file to save to
 */
void savePatientListToFile(PatientNode *head, FILE *file) {

  PatientNode *cur;

  if (head == NULL) {
    return;
  }
  cur = head;

  do {
    savePatientToFile(cur->patient, file);
    cur = cur->next;
  } while (cur != NULL);
}

/*
 * Saves a patient to file
 * @param patient: pointer to the patient to be saved
 * @param file: pointer to file to save to
 */
void savePatientToFile(Patient *patient, FILE *file) {

  fprintf(file, "%s,%d,%d,%d,%d\n", patient->name, patient->age, patient->id,
          patient->triageLevel, patient->gender);
}
