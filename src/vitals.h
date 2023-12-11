#ifndef VITALS_H
#define VITALS_H
#include "triage_level.h"
#include <stdbool.h>

// ################################## MODEL ##################################

enum Airway { Blocked, Free, Inspiratory_stridor };

struct Vitals {
  enum Airway airway;
  int oxygen_saturation;
  bool with_oxygen;
  int respiration_frequency;
  int pulse;
  int systolic_blood_pressure;
  int glasgow_coma_scale;
  double temperature_celcius;
  bool with_kol;
};

enum Triage_Level get_vital_triage(struct Vitals vitals);

// ################################ CONTROLLER ################################

void input_vitals(struct Vitals *vitals);

#endif
