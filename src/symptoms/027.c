#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of symptoms
enum Symptom_Category {
  SC_Severe_Pain,
  SC_Confusion,
  SC_Infection_Suspect,
  SC_Risk_Patient,
  SC_None
};

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent symptoms
struct Symptoms {
  enum Symptom_Category category;
  enum Severity_Level severity;
  bool yellow_vp;
  bool green_vp;
  bool pain_movement_pattern;
  bool normal_movement_pattern;
  bool altered_mental_state;
  bool infection_suspect;
  bool risk_patient;
};

// Function to determine triage level based on symptoms
enum Triage_Level get_symptoms_triage(struct Symptoms symptoms);

// Function implementation
enum Triage_Level get_symptoms_triage(struct Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case SC_Severe_Pain:
    triage_level = (symptoms.yellow_vp) ? Yellow : triage_level;
    triage_level = (symptoms.green_vp) ? Green : triage_level;
    triage_level = (symptoms.pain_movement_pattern) ? Orange : triage_level;
    break;
  case SC_Confusion:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case SC_Infection_Suspect:
    triage_level = (symptoms.infection_suspect) ? Orange : triage_level;
    break;
  case SC_Risk_Patient:
    triage_level = (symptoms.risk_patient) ? Orange : triage_level;
    break;
  case SC_None:
    triage_level = Blue;
    break;
  }

  return triage_level;
}
