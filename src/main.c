#include "patient_queue.h"
#include "symptoms.h"
#include "vitals.h"
#include <ncurses.h>
#include <stdio.h>
#include <string.h>

int main(void) {

  // Make Anton and triage him
  struct Vitals anton_vitals;
  anton_vitals.airway = Free;
  anton_vitals.oxygen_saturation = 100;
  anton_vitals.with_oxygen = false;
  anton_vitals.with_kol = false;
  anton_vitals.respiration_frequency = 10;
  anton_vitals.pulse = 60;
  anton_vitals.systolic_blood_pressure = 100;
  anton_vitals.glasgow_coma_scale = 10;
  anton_vitals.temperature_celcius = 37;

  struct Patient patient;
  strcpy(patient.name, "Anton");
  patient.age = 21;
  patient.gender = Female;
  patient.vitals = &anton_vitals;
  patient.symptoms_head = NULL;

  printf("triage_level anton: %d\n", get_triage(patient));
}
