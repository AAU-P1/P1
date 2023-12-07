#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent symptoms
struct Symptoms {
  bool impaired_consciousness;
  bool suspicion_of_ketoacidosis;
  bool prolonged_duration;
};

// Function to determine triage level based on symptoms
enum Triage_Level get_symptoms_triage(struct Symptoms symptoms);

// Function implementation
enum Triage_Level get_symptoms_triage(struct Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  if (symptoms.impaired_consciousness) {
    triage_level = Red; // Life-threatening
  } else if (symptoms.suspicion_of_ketoacidosis) {
    triage_level = Orange; // Urgent
  } else if (symptoms.prolonged_duration) {
    triage_level = Yellow; // Less urgent
  }

  return triage_level;
}
