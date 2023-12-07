#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of fever and/or infection symptoms
enum Fever_Infection_Category {
  FI_Meningitis_Suspicion,
  FI_Implanted_Foreign_Object,
  FI_Pain_Assessment,
  FI_Pain_Assessment_Options,
  FI_FLACC_Score,
  FI_NIPS_Score,
  FI_Morphine_Administration,
  FI_Sepsis,
  FI_Local_Infection
};

// Enum to represent different pain assessment options
enum Fever_Infection_Pain_Assessment {
  FI_PA_NRS_VAS_4_10,
  FI_PA_NRS_VAS_0_3,
  FI_PA_None
};

// Enum to represent different FLACC scores for pain assessment in children
enum Fever_Infection_FLACC_Score { FI_FLACC_8_10, FI_FLACC_4_7, FI_FLACC_0_3 };

// Enum to represent different NIPS scores for pain assessment in infants
enum Fever_Infection_NIPS_Score { FI_NIPS_4_6, FI_NIPS_1_3, FI_NIPS_0 };

// Enum to represent different sepsis criteria
enum Fever_Infection_Sepsis_Criteria {
  FI_SC_Slurred_Consciousness,
  FI_SC_Rapid_Respiratory_Rate,
  FI_SC_Oliguria_Pulse,
  FI_SC_Lactate_Temperature
};

// Enum to represent different infection levels
enum Fever_Infection_Local_Infection_Level {
  FI_LI_Extensive,
  FI_LI_Well_Defined
};

// Struct to represent fever and/or infection symptoms
struct Fever_Infection_Symptoms {
  enum Fever_Infection_Category category;
  bool meningitis_suspicion;
  bool implanted_foreign_object;
  enum Fever_Infection_Pain_Assessment pain_assessment;
  enum Fever_Infection_FLACC_Score flacc_score;
  enum Fever_Infection_NIPS_Score nips_score;
  bool morphine_administration;
  enum Fever_Infection_Sepsis_Criteria sepsis_criteria;
  enum Fever_Infection_Local_Infection_Level local_infection_level;
};

// Function to determine triage level based on symptoms
enum Triage_Level
get_symptoms_fever_infection_triage(struct Fever_Infection_Symptoms symptoms);

// Example usage in the main function
int main() {
  struct Fever_Infection_Symptoms example_symptoms = {
      .category = FI_Meningitis_Suspicion,
      .meningitis_suspicion = true,
      .pain_assessment = FI_PA_NRS_VAS_4_10,
      .flacc_score = FI_FLACC_8_10,
      .morphine_administration = true,
      .sepsis_criteria = FI_SC_Rapid_Respiratory_Rate,
      .local_infection_level = FI_LI_Extensive};

  enum Triage_Level triage_level =
      get_symptoms_fever_infection_triage(example_symptoms);

  // Handle triage_level as needed

  return 0;
}

// Function implementation
enum Triage_Level
get_symptoms_fever_infection_triage(struct Fever_Infection_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case FI_Meningitis_Suspicion:
    triage_level = Red;
    break;
  case FI_Implanted_Foreign_Object:
    triage_level = (symptoms.implanted_foreign_object) ? triage_level : Blue;
    break;
  case FI_Pain_Assessment:
    triage_level = (symptoms.pain_assessment == FI_PA_NRS_VAS_4_10)
                       ? Orange
                       : triage_level;
    break;
  case FI_FLACC_Score:
    triage_level =
        (symptoms.flacc_score == FI_FLACC_8_10) ? Yellow : triage_level;
    break;
  case FI_NIPS_Score:
    triage_level = (symptoms.nips_score == FI_NIPS_4_6) ? Yellow : triage_level;
    break;
  case FI_Morphine_Administration:
    triage_level = (symptoms.morphine_administration) ? triage_level : Yellow;
    break;
  case FI_Sepsis:
    triage_level = (symptoms.sepsis_criteria == FI_SC_Rapid_Respiratory_Rate)
                       ? Red
                       : triage_level;
    break;
  case FI_Local_Infection:
    triage_level = (symptoms.local_infection_level == FI_LI_Extensive)
                       ? Orange
                       : triage_level;
    break;
  }

  return triage_level;
}
