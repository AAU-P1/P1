#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent psychiatric or crisis symptoms
struct Psychiatric_Symptoms {
  bool violent_threatening_behavior;
  bool suicidal_threat;
  bool anxiety_agitation;
  bool delirium;
  bool acute_crisis_need_help;
  bool known_mental_disorder;
};

// Function to determine triage level based on psychiatric symptoms
enum Triage_Level get_psychiatric_symptoms_triage(
    struct Psychiatric_Symptoms psychiatric_symptoms);

// Function implementation
enum Triage_Level get_psychiatric_symptoms_triage(
    struct Psychiatric_Symptoms psychiatric_symptoms) {
  enum Triage_Level triage_level = Blue;

  if (psychiatric_symptoms.violent_threatening_behavior) {
    triage_level = Red; // Life-threatening
  } else if (psychiatric_symptoms.suicidal_threat) {
    triage_level = Orange; // Urgent
  } else if (psychiatric_symptoms.anxiety_agitation ||
             psychiatric_symptoms.delirium) {
    triage_level = Yellow; // Less urgent
  } else if (psychiatric_symptoms.acute_crisis_need_help ||
             psychiatric_symptoms.known_mental_disorder) {
    triage_level = Green; //
