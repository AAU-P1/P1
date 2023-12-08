#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of pregnancy and maternity symptoms
enum Pregnancy_Symptom_Category {
  PSC_Bleeding,
  PSC_Contractions,
  PSC_Preeclampsia,
  PSC_Systolic_BP,
  PSC_Diastolic_BP,
  PSC_Vomiting,
  PSC_Fever,
  PSC_None
};

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent pregnancy and maternity symptoms
struct Pregnancy_Symptoms {
  enum Pregnancy_Symptom_Category category;
  enum Severity_Level severity;
};

// Function to determine triage level based on symptoms
enum Triage_Level
get_symptoms_pregnancy_triage(struct Pregnancy_Symptoms symptoms);

// Function implementation
enum Triage_Level
get_symptoms_pregnancy_triage(struct Pregnancy_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case PSC_Bleeding:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case PSC_Contractions:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case PSC_Preeclampsia:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case PSC_Systolic_BP:
    triage_level = (symptoms.severity == SL_Urgent) ? Orange : triage_level;
    break;
  case PSC_Diastolic_BP:
    triage_level = (symptoms.severity == SL_Urgent) ? Orange : triage_level;
    break;
  case PSC_Vomiting:
    triage_level =
        (symptoms.severity == SL_Less_Urgent) ? Yellow : triage_level;
    break;
  case PSC_Fever:
    triage_level =
        (symptoms.severity == SL_Less_Urgent) ? Yellow : triage_level;
    break;
  case PSC_None:
    triage_level = (symptoms.severity == SL_Not_Urgent) ? Green : triage_level;
    break;
  }

  return triage_level;
}
