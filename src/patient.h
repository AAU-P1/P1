#ifndef PATIENT_H
#define PATIENT_H

#include "symptoms.h"
#include "triage_level.h"
#include "vitals.h"
#include <stdbool.h>

// ################################## MODEL ##################################

typedef enum { GENDER_MALE, GENDER_FEMALE, GENDER_OTHER } Gender;

typedef struct {
  char name[100];
  int age;
  int id;
  TriageLevel triageLevel;
  Gender gender;
  Vitals *vitals;
  SymptomNode *symptomsHead;
} Patient;

typedef struct PatientNode PatientNode;
struct PatientNode {
  Patient *patient;
  PatientNode *next;
};

typedef struct {
  PatientNode *redHead;
  PatientNode *orangeHead;
  PatientNode *yellowHead;
  PatientNode *greenHead;
  PatientNode *blueHead;
  int currentId;
} PatientQueue;

void addPatientToQueue(PatientQueue *patientQueue, Patient *patient, int id);
PatientNode *addPatientToList(PatientNode *head, Patient *patient);

void removePatientFromQueue(PatientQueue *patientQueue, int id);
PatientNode *removePatientFromList(PatientNode *head, int id);

void triagePatient(Patient *patient);

// ############################ CONTROLLER/VIEW ############################

void printPatientQueue(PatientQueue *patientQueue);
void printPatientList(PatientNode *head);
void printPatient(Patient *patient);

void printPatientQueuePOV(PatientQueue *patientQueue, int id);
void printPatientListPOV(PatientNode *head, int id, char *message,
                         bool *patientFound);

Patient *inputPatient();
void removePatient(PatientQueue *patientQueue);
void printPatientPOV(PatientQueue *patientQueue);
void inputPatientName(Patient *patient);

#endif
