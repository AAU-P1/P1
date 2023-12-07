#include "../triage_level.h"
#include <stdbool.h>

enum CoughingSpittingBlood {
  CSB_None,
  CSB_Ongoing,
  CSB_Last24h_Multiple,
  CSB_Last24h_Single,
  CSB_MoreThan24h
};

enum ThroatNeckSurgeryLast14Days { TNS_Last14Days_No, TNS_Last14Days_Yes };

enum FeverCoughDyspnea { FCD_No, FCD_Yes };

struct AirwayBleeding {
  bool threatened_airway;
  enum CoughingSpittingBlood coughing_spitting_blood;
  enum ThroatNeckSurgeryLast14Days throat_neck_surgery_last_14_days;
  bool fever_cough_dyspnea;
};

enum Triage_Level
get_symptoms_airway_bleeding_triage(struct AirwayBleeding airway_bleeding);

enum Triage_Level
get_symptoms_airway_bleeding_triage(struct AirwayBleeding airway_bleeding) {
  enum Triage_Level triage_level = Blue;

  bool red = airway_bleeding.threatened_airway;

  bool orange =
      airway_bleeding.coughing_spitting_blood != CSB_None ||
      airway_bleeding.throat_neck_surgery_last_14_days == TNS_Last14Days_Yes ||
      airway_bleeding.fever_cough_dyspnea == FCD_Yes;

  bool yellow =
      airway_bleeding.throat_neck_surgery_last_14_days == TNS_Last14Days_Yes ||
      airway_bleeding.fever_cough_dyspnea == FCD_Yes;

  if (red) {
    triage_level = Red;
  } else if (orange) {
    triage_level = Orange;
  } else if (yellow) {
    triage_level = Yellow;
  } else {
    triage_level = Green;
  }
  return triage_level;
}
