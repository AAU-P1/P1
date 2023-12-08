#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of poisoning symptoms
enum Poisoning_Category {
  PC_Danger_Level,
  PC_Seizures,
  PC_Intention_Behavior,
  PC_Suspected_Hidden_Injury,
  PC_None
};

// Enum to represent different danger levels of poisoning
enum Poisoning_Danger_Level {
  PDL_Very_High,
  PDL_High_Unknown_With_Impaired_General_Condition,
  PDL_Low,
  PDL_None
};

// Enum to represent different seizure conditions in poisoning
enum Poisoning_Seizures {
  PS_Ongoing,
  PS_Isolated_Case_After_Poisoning,
  PS_None
};

// Enum to represent different intentions and behaviors in poisoning
enum Poisoning_Intention_Behavior {
  PIB_Suicidal_Intent_Or_Continued_Risk,
  PIB_Accidental_Ingestion_In_Small_Doses,
  PIB_None
};

// Struct to represent poisoning symptoms
struct Poisoning_Symptoms {
  enum Poisoning_Category category;
  enum Poisoning_Danger_Level danger_level;
  enum Poisoning_Seizures seizures;
  enum Poisoning_Intention_Behavior intention_behavior;
  bool suspected_hidden_injury;
};

// Function to determine triage level based on symptoms
enum Triage_Level
get_symptoms_poisoning_triage(struct Poisoning_Symptoms symptoms);

// Function implementation
enum Triage_Level
get_symptoms_poisoning_triage(struct Poisoning_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case PC_Danger_Level:
    triage_level = (symptoms.danger_level == PDL_Very_High) ? Red
                   : (symptoms.danger_level ==
                      PDL_High_Unknown_With_Impaired_General_Condition)
                       ? Orange
                   : (symptoms.danger_level == PDL_Low) ? Yellow
                                                        : triage_level;
    break;
  case PC_Seizures:
    triage_level = (symptoms.seizures == PS_Ongoing) ? Red
                   : (symptoms.seizures == PS_Isolated_Case_After_Poisoning)
                       ? Orange
                       : triage_level;
    break;
  case PC_Intention_Behavior:
    triage_level =
        (symptoms.intention_behavior == PIB_Suicidal_Intent_Or_Continued_Risk)
            ? Red
        : (symptoms.intention_behavior ==
           PIB_Accidental_Ingestion_In_Small_Doses)
            ? Yellow
            : triage_level;
    break;
  case PC_Suspected_Hidden_Injury:
    triage_level = (symptoms.suspected_hidden_injury) ? Red : triage_level;
    break;
  case PC_None:
    triage_level = Blue;
    break;
  }

  return triage_level;
}
