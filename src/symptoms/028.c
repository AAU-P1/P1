#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of symptoms
enum Symptom_Category {
  SC_Catheter_Reinsertion,
  SC_Stoma_Complications,
  SC_Intermittent_Catheterization,
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
  bool peg_or_top_catheter;
  bool stoma_necrosis_or_infection;
  bool intermittent_catheterization;
};

// Function to determine triage level based on symptoms
enum Triage_Level get_symptoms_triage(struct Symptoms symptoms);

// Function implementation
enum Triage_Level get_symptoms_triage(struct Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case SC_Catheter_Reinsertion:
    triage_level = (symptoms.peg_or_top_catheter) ? Orange : triage_level;
    break;
  case SC_Stoma_Complications:
    triage_level =
        (symptoms.stoma_necrosis_or_infection) ? Orange : triage_level;
    break;
  case SC_Intermittent_Catheterization:
    triage_level =
        (symptoms.intermittent_catheterization) ? Yellow : triage_level;
    break;
  case SC_None:
    triage_level = Blue;
    break;
  }

  return triage_level;
}
