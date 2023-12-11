#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "035_Nose_symptoms.h"

enum Triage_Level get_symptoms_nose_triage(struct Nose_symptom nose_symptom) {

  enum Triage_Level triage_level = Green;

  bool red = nose_symptom.nose_bleed == NB_ongoing_bleeding_circular_affected;

  bool orange =
      nose_symptom.nose_bleed == NB_ongoing_bleeding_circular_unaffected;

  if (red) {
    triage_level = Red;
  } else if (orange) {
    triage_level = Orange;
  } else {
    triage_level = Blue;
  }

  return triage_level;
}
