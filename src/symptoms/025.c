#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of headache symptoms
enum Headache_Category {
  HC_Meningitis,
  HC_Severe_Sudden_Onset,
  HC_Loss_Of_Consciousness,
  HC_Visual_Disturbances,
  HC_Pain_Assessment,
  HC_Systolic_Blood_Pressure,
  HC_Head_Trauma,
  HC_None
};

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent headache symptoms
struct Headache_Symptoms {
  enum Headache_Category category;
  enum Severity_Level severity;
  bool red_vp;
  int systolic_blood_pressure;
  bool head_trauma;
};

// Function to determine triage level based on symptoms
enum Triage_Level
get_symptoms_headache_triage(struct Headache_Symptoms symptoms);

// Function implementation
enum Triage_Level
get_symptoms_headache_triage(struct Headache_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case HC_Meningitis:
    triage_level = (symptoms.red_vp) ? Red : triage_level;
    break;
  case HC_Severe_Sudden_Onset:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case HC_Loss_Of_Consciousness:
    triage_level = (symptoms.red_vp) ? Red : triage_level;
    break;
  case HC_Visual_Disturbances:
    triage_level = (symptoms.red_vp) ? Red : triage_level;
    break;
  case HC_Pain_Assessment:
    triage_level = (symptoms.severity == SL_Urgent) ? Orange : triage_level;
    break;
  case HC_Systolic_Blood_Pressure:
    // Assuming systolic blood pressure levels provided for different age groups
    if (symptoms.systolic_blood_pressure > 240) {
      triage_level = Red;
    } else if (symptoms.systolic_blood_pressure > 140) {
      triage_level = Orange;
    } else if (symptoms.systolic_blood_pressure > 115) {
      triage_level = Yellow;
    } else if (symptoms.systolic_blood_pressure > 110) {
      triage_level = Green;
    } else if (symptoms.systolic_blood_pressure > 80) {
      triage_level = Blue;
    }
    break;
  case HC_Head_Trauma:
    triage_level = (symptoms.head_trauma) ? Orange : triage_level;
    break;
  case HC_None:
    triage_level = Blue;
    break;
  }

  return triage_level;
}
