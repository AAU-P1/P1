#include "../triage_level.h"
#include <stdbool.h>

enum ChestPainType {
  CPT_Pressure,
  CPT_Duration,
  CPT_EKG_Abnormalities,
  CPT_None
};

enum ChestPainDuration {
  CPD_Minutes_Hours,
  CPD_Persistent,
  CPD_Transient,
  CPD_None
};

enum EKGAbnormalities {
  EKG_News_ST_T_Changes_Wide_Complex_Arrhythmia,
  EKG_Narrow_Complex_Arrhythmia,
  EKG_None
};

struct ChestPain {
  bool pressure_pain_discomfort;
  enum ChestPainDuration duration;
  enum EKGAbnormalities ekg_abnormalities;
};

enum Triage_Level get_symptoms_chest_pain_triage(struct ChestPain chest_pain);
enum Triage_Level get_symptoms_chest_pain_triage(struct ChestPain chest_pain) {
  enum Triage_Level triage_level = Blue;

  if (chest_pain.pressure_pain_discomfort) {
    triage_level = Red;
  } else if (chest_pain.duration == CPD_Minutes_Hours ||
             chest_pain.duration == CPD_Persistent ||
             chest_pain.ekg_abnormalities ==
                 EKG_News_ST_T_Changes_Wide_Complex_Arrhythmia) {
    triage_level = Orange;
  } else {
    triage_level = Green;
  }

  return triage_level;
}
