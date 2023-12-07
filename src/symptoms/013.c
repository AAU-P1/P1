#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of electrical and lightning injuries
enum Electrical_Lightning_Injury_Category {
  ELI_Unconscious,
  ELI_Pain_Assessment,
  ELI_Pain_Assessment_Options,
  ELI_FLACC_Score,
  ELI_NIPS_Score,
  ELI_Morphine_Administration,
  ELI_Voltage_Level,
  ELI_EKG_Assessment
};

// Enum to represent different pain assessment options
enum Electrical_Lightning_Injury_Pain_Assessment {
  ELI_PA_NRS_VAS_4_10,
  ELI_PA_NRS_VAS_0_3,
  ELI_PA_None
};

// Enum to represent different FLACC scores for pain assessment in children
enum Electrical_Lightning_Injury_FLACC_Score {
  ELI_FLACC_8_10,
  ELI_FLACC_4_7,
  ELI_FLACC_0_3
};

// Enum to represent different NIPS scores for pain assessment in infants
enum Electrical_Lightning_Injury_NIPS_Score {
  ELI_NIPS_4_6,
  ELI_NIPS_1_3,
  ELI_NIPS_0
};

// Enum to represent different voltage levels
enum Electrical_Lightning_Injury_Voltage_Level {
  ELI_High_Voltage,
  ELI_Medium_Voltage,
  ELI_Low_Voltage
};

// Enum to represent different EKG assessment results
enum Electrical_Lightning_Injury_EKG_Assessment {
  ELI_EKG_Abnormal,
  ELI_EKG_Normal
};

// Struct to represent an electrical and lightning injury
struct Electrical_Lightning_Injury {
  enum Electrical_Lightning_Injury_Category category;
  bool unconscious;
  enum Electrical_Lightning_Injury_Pain_Assessment pain_assessment;
  enum Electrical_Lightning_Injury_FLACC_Score flacc_score;
  enum Electrical_Lightning_Injury_NIPS_Score nips_score;
  bool morphine_administration;
  enum Electrical_Lightning_Injury_Voltage_Level voltage_level;
  enum Electrical_Lightning_Injury_EKG_Assessment ekg_assessment;
};

// Function to determine triage level based on injury symptoms
enum Triage_Level get_symptoms_electrical_lightning_triage(
    struct Electrical_Lightning_Injury injury);

// Example usage in the main function
int main() {
  struct Electrical_Lightning_Injury example_injury = {
      .category = ELI_Unconscious,
      .unconscious = true,
      .pain_assessment = ELI_PA_NRS_VAS_4_10,
      .flacc_score = ELI_FLACC_8_10,
      .morphine_administration = true,
      .voltage_level = ELI_High_Voltage,
      .ekg_assessment = ELI_EKG_Abnormal};

  enum Triage_Level triage_level =
      get_symptoms_electrical_lightning_triage(example_injury);

  // Handle triage_level as needed

  return 0;
}

// Function implementation
enum Triage_Level get_symptoms_electrical_lightning_triage(
    struct Electrical_Lightning_Injury injury) {
  enum Triage_Level triage_level = Blue;

  switch (injury.category) {
  case ELI_Unconscious:
    triage_level = Red;
    break;
  case ELI_Pain_Assessment:
    triage_level =
        (injury.pain_assessment == ELI_PA_NRS_VAS_4_10) ? Orange : triage_level;
    break;
  case ELI_FLACC_Score:
    triage_level =
        (injury.flacc_score == ELI_FLACC_8_10) ? Yellow : triage_level;
    break;
  case ELI_NIPS_Score:
    triage_level = (injury.nips_score == ELI_NIPS_4_6) ? Yellow : triage_level;
    break;
  case ELI_Morphine_Administration:
    triage_level = (injury.morphine_administration) ? triage_level : Yellow;
    break;
  case ELI_Voltage_Level:
    triage_level =
        (injury.voltage_level == ELI_High_Voltage) ? Red : triage_level;
    break;
  case ELI_EKG_Assessment:
    triage_level =
        (injury.ekg_assessment == ELI_EKG_Abnormal) ? Red : triage_level;
    break;
  }

  return triage_level;
}
