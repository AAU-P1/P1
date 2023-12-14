#ifndef VITALS_H
#define VITALS_H
#include "triage_level.h"
#include <stdbool.h>

// ################################## MODEL ##################################

typedef enum { V_BLOCKED, V_FREE, V_INSPIRATORY_STRIDOR } Airway;

typedef struct {
  Airway airway;
  int oxygenSaturation;
  bool withOxygen;
  int respirationFrequency;
  int pulse;
  int systolicBloodPressure;
  int glasgowComaScale;
  double temperatureCelcius;
  bool withKol;
} Vitals;

TriageLevel getVitalTriage(Vitals vitals);

// ################################ CONTROLLER ################################

void inputVitals(Vitals *vitals);

#endif
