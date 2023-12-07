#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of confusion and agitation symptoms
enum Confusion_Agitation_Category {
  CAC_Meningitis_Suspicion,
  CAC_Duration,
  CAC_Poisoning_Suspicion,
  CAC_Behavior,
  CAC_Head_Trauma,
  CAC_Blood_Sugar,
  CAC_None
};

// Enum to represent different durations of confusion
enum Confusion_Agitation_Duration {
  CAD_Acute_Onset,
  CAD_Non_Acute_Onset,
  CAD_None
};

// Struct to represent confusion and agitation symptoms
struct Confusion_Agitation_Symptoms {
  enum Confusion_Agitation_Category category;
  bool meningitis_suspicion;
  enum Confusion_Agitation_Duration duration;
  bool poisoning_suspicion;
  bool self_harm_or_violent_behavior;
  bool recent_head_trauma;
  bool abnormal_blood_sugar;
};

// Function to determine triage level based on symptoms
enum Triage_Level get_symptoms_confusion_agitation_triage(
    struct Confusion_Agitation_Symptoms symptoms);

// Function implementation
enum Triage_Level get_symptoms_confusion_agitation_triage(
    struct Confusion_Agitation_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case CAC_Meningitis_Suspicion:
    triage_level = (symptoms.meningitis_suspicion) ? Red : triage_level;
    break;
  case CAC_Duration:
    triage_level = (symptoms.duration == CAD_Acute_Onset) ? Red : triage_level;
    break;
  case CAC_Poisoning_Suspicion:
    triage_level = (symptoms.poisoning_suspicion) ? Red : triage_level;
    break;
  case CAC_Behavior:
    triage_level =
        (symptoms.self_harm_or_violent_behavior) ? Red : triage_level;
    break;
  case CAC_Head_Trauma:
    triage_level = (symptoms.recent_head_trauma) ? Red : triage_level;
    break;
  case CAC_Blood_Sugar:
    triage_level = (symptoms.abnormal_blood_sugar) ? Red : triage_level;
    break;
  case CAC_None:
    triage_level = Blue;
    break;
  }

  return triage_level;
}
