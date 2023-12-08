#include "../triage_level.h"
#include <stdbool.h>

enum Consciousness_head_injury {
  CHI_trauma_criteria_met,
  CHI_anticoagulant_treatment,
  CHI_pupil_difference,
  CHI_none
};
enum Consciousness_meningitis_suspicion { CMS_yes, CMS_none };
enum Consciousness_sudden_onset { CSO_yes, CSO_none };
enum Consciousness_poisoning_suspicion { CPS_yes, CPS_none };
enum Consciousness_immunosuppressed { CI_yes, CI_none };
enum Consciousness_abnormal_blood_sugar { CABS_yes, CABS_none };

struct Consciousness {
  enum Consciousness_head_injury head_injury;
  enum Consciousness_meningitis_suspicion meningitis_suspicion;
  enum Consciousness_sudden_onset sudden_onset;
  enum Consciousness_poisoning_suspicion poisoning_suspicion;
  enum Consciousness_immunosuppressed immunosuppressed;
  enum Consciousness_abnormal_blood_sugar abnormal_blood_sugar;
};

enum Triage_Level
get_symptoms_consciousness_triage(struct Consciousness consciousness);
enum Triage_Level
get_symptoms_consciousness_triage(struct Consciousness consciousness) {
  enum Triage_Level triage_level = Blue;

  bool red = consciousness.head_injury == CHI_trauma_criteria_met ||
             consciousness.head_injury == CHI_anticoagulant_treatment ||
             consciousness.head_injury == CHI_pupil_difference;

  bool orange = consciousness.meningitis_suspicion == CMS_yes ||
                consciousness.sudden_onset == CSO_yes ||
                consciousness.poisoning_suspicion == CPS_yes ||
                consciousness.immunosuppressed == CI_yes ||
                consciousness.abnormal_blood_sugar == CABS_yes;

  if (red) {
    triage_level = Red;
  } else if (orange) {
    triage_level = Orange;
  } else {
    triage_level = Blue;
  }

  return triage_level;
}
