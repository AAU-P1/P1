#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of cast complication symptoms
enum Cast_Complication_Category {
  CCC_Obstructed_Pulse,
  CCC_Pain_Assessment,
  CCC_Sensibility_Disturbance,
  CCC_None
};

// Enum to represent different levels of cast complication severity
enum Cast_Complication_Severity { CCS_Yes, CCS_No };

// Struct to represent cast complication symptoms
struct Cast_Complication_Symptoms {
  enum Cast_Complication_Category category;
  enum Cast_Complication_Severity obstructed_pulse;
  enum Cast_Complication_Severity pain_assessment;
  enum Cast_Complication_Severity sensibility_disturbance;
};

// Function to determine triage level based on symptoms
enum Triage_Level get_symptoms_cast_complication_triage(
    struct Cast_Complication_Symptoms symptoms);

// Function implementation
enum Triage_Level get_symptoms_cast_complication_triage(
    struct Cast_Complication_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case CCC_Obstructed_Pulse:
    triage_level = (symptoms.obstructed_pulse == CCS_Yes) ? Red : triage_level;
    break;
  case CCC_Pain_Assessment:
    triage_level =
        (symptoms.pain_assessment == CCS_Yes) ? Orange : triage_level;
    break;
  case CCC_Sensibility_Disturbance:
    triage_level =
        (symptoms.sensibility_disturbance == CCS_Yes) ? Red : triage_level;
    break;
  case CCC_None:
    triage_level = Blue;
    break;
  }

  return triage_level;
}
