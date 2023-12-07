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
  bool ongoing_seizures;
  bool clustered_seizures_last_24_hours;
  bool first_time_seizure;
  bool suspicion_of_withdrawal;
  bool recent_head_trauma;
  bool acute_neurological_deficits;
};

// Function to determine triage level based on symptoms
enum Triage_Level get_symptoms_triage(struct Symptoms symptoms);

// Function implementation
enum Triage_Level get_symptoms_triage(struct Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  if (symptoms.ongoing_seizures) {
    triage_level = Red; // Life-threatening
  } else if (symptoms.clustered_seizures_last_24_hours) {
    triage_level = Orange; // Urgent
  } else if (symptoms.first_time_seizure || symptoms.suspicion_of_withdrawal) {
    triage_level = Yellow; // Less urgent
  } else if (symptoms.recent_head_trauma ||
             symptoms.acute_neurological_deficits) {
    triage_level = Yellow; // Less urgent
  }

  return triage_level;
}
