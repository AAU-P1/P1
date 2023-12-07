#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent neurological deficit symptoms
struct Neurological_Deficit_Symptoms {
  bool thrombolysis_criteria_met;
  bool continued_symptoms;
  bool resolved_symptoms;
};

// Function to determine triage level based on neurological deficit symptoms
enum Triage_Level get_neurological_deficit_symptoms_triage(
    struct Neurological_Deficit_Symptoms neurological_deficit_symptoms);

// Function implementation
enum Triage_Level get_neurological_deficit_symptoms_triage(
    struct Neurological_Deficit_Symptoms neurological_deficit_symptoms) {
  enum Triage_Level triage_level = Blue;

  if (neurological_deficit_symptoms.thrombolysis_criteria_met) {
    triage_level = Red; // Life-threatening
  } else if (neurological_deficit_symptoms.continued_symptoms) {
    triage_level = Orange; // Urgent
  } else if (neurological_deficit_symptoms.resolved_symptoms) {
    triage_level = Green; // Not urgent
  }

  return triage_level;
}
