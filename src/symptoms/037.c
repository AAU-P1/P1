#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent back and neck symptoms
struct Back_Neck_Symptoms {
  bool trauma;
  bool spine_fracture_suspected;
  bool spine_fracture_suspected_neurological_symptoms;
  bool acute_injury_without_fracture_suspected;
  bool old_injury_without_fracture_suspected;
  int pain_severity_adults_children;
  bool yellow_triage_indicator;
  bool green_triage_indicator;
  bool normal_movement_pattern;
  bool unaffected_general_condition;
  bool nerve_impairment_acute;
  bool nerve_impairment_chronic;
};

// Function to determine triage level based on back and neck symptoms
enum Triage_Level
get_back_neck_symptoms_triage(struct Back_Neck_Symptoms back_neck_symptoms);

// Function implementation
enum Triage_Level
get_back_neck_symptoms_triage(struct Back_Neck_Symptoms back_neck_symptoms) {
  enum Triage_Level triage_level = Blue;

  if (back_neck_symptoms.trauma &&
      back_neck_symptoms.spine_fracture_suspected_neurological_symptoms) {
    triage_level = Red; // Life-threatening
  } else if (back_neck_symptoms.pain_severity_adults_children >= 4 &&
             back_neck_symptoms.yellow_triage_indicator) {
    triage_level = Orange; // Urgent
  } else if (back_neck_symptoms.pain_severity_adults_children < 4 &&
             back_neck_symptoms.green_triage_indicator) {
    triage_level = Green; // Not urgent
  }

  return triage_level;
}
