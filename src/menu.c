#include "controller.h"
#include "file.h"
#include "patient.h"
#include <stdio.h>
#include <stdlib.h>

void startMenu() {

  PatientQueue patientQueue = {NULL, NULL, NULL, NULL, NULL, 1};

  loadPatientQueueFromFile(&patientQueue);

  char c;
  clearScreen();
  printPatientQueue(&patientQueue);
  while (true) {
    printf("(T)riage new patient | (R)emove Patient | (D)isplay Queue "
           "| Display (P)OV Queue | (Q)uit\n");
    c = getchar();
    clearInputBuffer();

    switch (c) {
    case 'T':
    case 't': {
      Patient *patient = inputPatient();
      triagePatient(patient);
      addPatientToQueue(&patientQueue, patient, patientQueue.currentId);
      patientQueue.currentId++;
      savePatientQueueToFile(&patientQueue);
      printPatientQueue(&patientQueue);
      break;
    }
    case 'R':
    case 'r':
      removePatient(&patientQueue);
      savePatientQueueToFile(&patientQueue);
      break;
    case 'D':
    case 'd':
      printPatientQueue(&patientQueue);
      break;
    case 'P':
    case 'p':
      printPatientPOV(&patientQueue);
      break;
    case 'Q':
    case 'q':
      printf("Bye!\n");
      exit(1);
      break;
    default:
      printf("Invalid input try again\n");
    }
  }
}
