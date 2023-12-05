#include "patient_queue.h"
#include "vitals.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

enum Triage_Level get_triage(struct Patient patient) {

  enum Triage_Level triage_level = Blue;

  if (patient.vitals != NULL) {
    triage_level = get_vital_triage(*patient.vitals);
  }

  if (patient.symptoms_head) {
    enum Triage_Level symptoms_triage =
        get_symptoms_triage(*patient.symptoms_head);

    if (triage_level > symptoms_triage) {
      return symptoms_triage;
    }
  }

  return triage_level;
}
