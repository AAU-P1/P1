#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of heart palpitations symptoms
enum Heart_Palpitations_Category {
  HPC_ICD_Shocks,
  HPC_Chest_Pain,
  HPC_Shortness_of_Breath,
  HPC_Fainting,
  HPC_Poisoning_Suspected,
  HPC_EKG_Abnormality,
  HPC_None
};

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent heart palpitations symptoms
struct Heart_Palpitations_Symptoms {
  enum Heart_Palpitations_Category category;
  enum Severity_Level severity;
  bool red_vp;
};

// Function to determine triage level based on symptoms
enum Triage_Level get_symptoms_heart_palpitations_triage(
    struct Heart_Palpitations_Symptoms symptoms);

// Function implementation
enum Triage_Level get_symptoms_heart_palpitations_triage(
    struct Heart_Palpitations_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case HPC_ICD_Shocks:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case HPC_Chest_Pain:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case HPC_Shortness_of_Breath:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case HPC_Fainting:
    triage_level = (symptoms.severity == SL_Urgent) ? Orange : triage_level;
    break;
  case HPC_Poisoning_Suspected:
    triage_level = (symptoms.red_vp) ? Red : triage_level;
    break;
  case HPC_EKG_Abnormality:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case HPC_None:
    triage_level = (symptoms.severity == SL_Not_Urgent) ? Green : triage_level;
    break;
  }

  return triage_level;
}
