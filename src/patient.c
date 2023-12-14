#include "patient.h"
#include "controller.h"
#include "symptoms.h"
#include "triage_level.h"
#include "vitals.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ################################## MODEL ##################################

PatientNode *addPatientToList(PatientNode *head, void *patient) {
  PatientNode *newNode = (PatientNode *)malloc(sizeof(PatientNode));
  if (newNode == NULL) {
    exit(EXIT_FAILURE);
  }

  PatientNode *cur;

  newNode->data = patient;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }
  cur = head;

  while (cur->next != NULL) {
    cur = cur->next;
  }

  cur->next = newNode;
  return head;
}

void removePatientFromQueue(PatientQueue *patientQueue, int id) {
  patientQueue->redHead = removePatientFromList(patientQueue->redHead, id);
  patientQueue->orangeHead =
      removePatientFromList(patientQueue->orangeHead, id);
  patientQueue->yellowHead =
      removePatientFromList(patientQueue->yellowHead, id);
  patientQueue->greenHead = removePatientFromList(patientQueue->greenHead, id);
  patientQueue->blueHead = removePatientFromList(patientQueue->blueHead, id);
}

PatientNode *removePatientFromList(PatientNode *head, int id) {
  if (head == NULL) {
    return head;
  }

  PatientNode *cur, *prev;
  cur = head;
  prev = NULL;

  do {
    Patient *patient = (Patient *)cur->data;
    if (patient->id == id) {

      if (prev == NULL) {
        PatientNode *newHead = cur->next;
        free(cur);
        return newHead;
      } else {
        prev->next = cur->next;
        free(cur);
        return head;
      }
    }
    prev = cur;
    cur = cur->next;
  } while (cur != NULL);
  return head;
}

void addPatientToQueue(PatientQueue *patientQueue, Patient *patient, int id) {

  patient->id = id;

  switch (patient->triageLevel) {
  case T_RED:
    patientQueue->redHead = addPatientToList(patientQueue->redHead, patient);
    break;
  case T_ORANGE:
    patientQueue->orangeHead =
        addPatientToList(patientQueue->orangeHead, patient);
    break;
  case T_YELLOW:
    patientQueue->yellowHead =
        addPatientToList(patientQueue->yellowHead, patient);
    break;
  case T_GREEN:
    patientQueue->greenHead =
        addPatientToList(patientQueue->greenHead, patient);
    break;
  case T_BLUE:
    patientQueue->blueHead = addPatientToList(patientQueue->blueHead, patient);
    break;
  }
}

void triagePatient(Patient *patient) {

  patient->triageLevel = T_BLUE;

  if (patient->vitals) {
    patient->triageLevel = getVitalTriage(*patient->vitals);
  }

  if (patient->symptomsHead) {
    TriageLevel symptomsTriage = getSymptomListTriage(patient->symptomsHead);

    if (patient->triageLevel > symptomsTriage) {
      patient->triageLevel = symptomsTriage;
    }
  }
}

// ################################## VIEW ##################################

void printPatient(Patient *patient) {
  printf("name:%s, age:%d, id:%d ", patient->name, patient->age, patient->id);

  switch (patient->gender) {
  case GENDER_MALE:
    printf("gender:male\n");
    break;
  case GENDER_FEMALE:
    printf("gender:female\n");
    break;
  case GENDER_OTHER:
    printf("gender:other\n");
    break;
  }
}

void printPatientList(PatientNode *head) {
  PatientNode *cur;

  if (head == NULL) {
    return;
  }
  cur = head;

  do {
    printPatient(cur->data);
    cur = cur->next;
  } while (cur != NULL);
}

void printPatientQueue(PatientQueue *patientQueue) {
  clearScreen();
  printf("\nRED:\n");
  printPatientList(patientQueue->redHead);
  printf("\nORANGE:\n");
  printPatientList(patientQueue->orangeHead);
  printf("\nYELLOW:\n");
  printPatientList(patientQueue->yellowHead);
  printf("\nGREEN:\n");
  printPatientList(patientQueue->greenHead);
  printf("\nBLUE:\n");
  printPatientList(patientQueue->blueHead);
  printf("\n");
}

void printPatientListPOV(PatientNode *head, int id, char *message,
                         bool *patientFound) {
  if (*patientFound || head == NULL) {
    return;
  }

  PatientNode *cur = head;
  int n = 0;

  do {
    Patient *patient = (Patient *)cur->data;
    if (patient->id == id) {
      *patientFound = true;
      break;
    }
    n++;
    cur = cur->next;
  } while (cur != NULL);

  if (n > 0) {
    printf("%s: %d\n", message, n);
  }
}

void printPatientQueuePOV(PatientQueue *patientQueue, int id) {
  clearScreen();
  printf("Patients in front of you:\n");
  bool patientFound = false;
  printPatientListPOV(patientQueue->redHead, id, "RED", &patientFound);
  printPatientListPOV(patientQueue->orangeHead, id, "ORANGE", &patientFound);
  printPatientListPOV(patientQueue->yellowHead, id, "YELLOW", &patientFound);
  printPatientListPOV(patientQueue->greenHead, id, "GREEN", &patientFound);
  printPatientListPOV(patientQueue->blueHead, id, "BLUE", &patientFound);
  printf("\n");
}

// ################################ CONTROLLER ################################

void inputPatientName(Patient *patient) {
  // Get patient Name
  clearScreen();

  while (true) {
    clearInputBuffer();
    printf("input patient name\n");
    int res = scanf("%99[^\n]", patient->name);
    if (res != 1) {
      printf("Invalid input. Try again!\n");
    } else {
      break;
    }
  }
}

Patient *inputPatient() {

  Patient *patient = (Patient *)malloc(sizeof(Patient));
  if (patient == NULL) {
    exit(EXIT_FAILURE);
  }
  patient->vitals = NULL;
  patient->symptomsHead = NULL;

  // Check if memory allocation is successful
  if (patient == NULL) {
    printf("Error: Unable to allocate memory for patient\n");
    exit(EXIT_FAILURE);
  }

  // Get patient Name
  inputPatientName(patient);

  // Get patient Age
  clearScreen();
  inputIntWithMin("Input patient age", &patient->age, 0);

  // Get patient Gender
  char c;
  clearScreen();
  inputChar(&c, "Input patient gender, (M)ale or (F)emale, (O)ther", "MmFfOo");
  switch (c) {
  case 'M':
  case 'm':
    patient->gender = GENDER_MALE;
    break;
  case 'F':
  case 'f':
    patient->gender = GENDER_FEMALE;
    break;
  case 'O':
  case 'o':
    patient->gender = GENDER_OTHER;
    break;
  }

  // Get patient Vitals
  clearScreen();
  inputChar(&c, "Would you like to input Vital Parameters? (Y)es  (N)o",
            "YyNn");
  switch (c) {
  case 'Y':
  case 'y':
    patient->vitals = (Vitals *)malloc(sizeof(Vitals));
    if (patient->vitals == NULL) {
      exit(EXIT_FAILURE);
    }
    inputVitals(patient->vitals);
    break;
  }

  bool doneInputting = false;

  while (!doneInputting) {
    clearScreen();
    inputChar(&c, "Would you like to input a/more Symptoms? (Y)es  (N)o",
              "YyNn");
    switch (c) {
    case 'Y':
    case 'y':
      patient->symptomsHead = inputSymptom(patient->symptomsHead);
      triagePatient(patient);
      break;
    case 'N':
    case 'n':
      doneInputting = true;
      break;
    }
  }
  return patient;
}

void removePatient(PatientQueue *patientQueue) {
  clearScreen();
  if (patientQueue->redHead == NULL && patientQueue->orangeHead == NULL &&
      patientQueue->yellowHead == NULL && patientQueue->greenHead == NULL &&
      patientQueue->blueHead == NULL) {
    printf("There are no patients to remove. Please triage some patients!\n");
    return;
  }
  int id;
  printPatientQueue(patientQueue);
  inputIntWithRange("Input id of patient", &id, 1, patientQueue->currentId - 1);
  removePatientFromQueue(patientQueue, id);
  printPatientQueue(patientQueue);
}

void printPatientPOV(PatientQueue *patientQueue) {
  clearScreen();
  if (patientQueue->redHead == NULL && patientQueue->orangeHead == NULL &&
      patientQueue->yellowHead == NULL && patientQueue->greenHead == NULL &&
      patientQueue->blueHead == NULL) {
    printf("There are no patients to print POV from. Please triage some "
           "patients!\n");
    return;
  }
  int id;
  printPatientQueue(patientQueue);
  inputIntWithRange("Input id of patient", &id, 1, patientQueue->currentId - 1);
  clearScreen();
  printPatientQueuePOV(patientQueue, id);
}
