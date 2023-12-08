#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of throat symptoms
enum Throat_Symptom_Category {
  TSC_Upper_Airway_Obstruction,
  TSC_Swallowing_Difficulty,
  TSC_Throat_Trauma,
  TSC_Pain_Assessment,
  TSC_None
};

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent throat symptoms
struct Throat_Symptoms {
  enum Throat_Symptom_Category category;
  enum Severity_Level severity;
  bool yellow_vp;
  bool green_vp;
  bool natural_movement;
  bool unaffected_general_condition;
};

// Function to determine triage level based on symptoms
enum Triage_Level get_symptoms_throat_triage(struct Throat_Symptoms symptoms);

// Function implementation
enum Triage_Level get_symptoms_throat_triage(struct Throat_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case TSC_Upper_Airway_Obstruction:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case TSC_Swallowing_Difficulty:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case TSC_Throat_Trauma:
    triage_level = (symptoms.severity == SL_Urgent) ? Orange : triage_level;
    break;
  case TSC_Pain_Assessment:
    triage_level = (symptoms.yellow_vp ||
                    (symptoms.green_vp && symptoms.natural_movement &&
                     symptoms.unaffected_general_condition))
                       ? Yellow
                       : triage_level;
    break;
  case TSC_None:
    triage_level = (symptoms.severity == SL_Not_Urgent) ? Green : triage_level;
    break;
  }

  return triage_level;
}
