#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent nasal symptoms
struct Nasal_Symptoms {
  bool ongoing_bleeding_circulatory_impact;
  bool ongoing_bleeding_no_circulatory_impact;
  bool suspected_nasal_fracture;
  bool foreign_body_present;
};

// Function to determine triage level based on nasal symptoms
enum Triage_Level
get_nasal_symptoms_triage(struct Nasal_Symptoms nasal_symptoms);

// Function implementation
enum Triage_Level
get_nasal_symptoms_triage(struct Nasal_Symptoms nasal_symptoms) {
  enum Triage_Level triage_level = Blue;

  if (nasal_symptoms.ongoing_bleeding_circulatory_impact) {
    triage_level = Red; // Life-threatening
  } else if (nasal_symptoms.ongoing_bleeding_no_circulatory_impact) {
    triage_level = Orange; // Urgent
  } else if (nasal_symptoms.suspected_nasal_fracture ||
             nasal_symptoms.foreign_body_present) {
    triage_level = Yellow; // Less urgent
  } else {
    triage_level = Green; // Not urgent
  }

  return triage_level;
}
