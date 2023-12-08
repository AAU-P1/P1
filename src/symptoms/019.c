#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of gastrointestinal bleeding symptoms
enum GI_Bleeding_Category {
  GIBC_Vomiting_Fresh_Blood,
  GIBC_Vital_Signs,
  GIBC_Rectal_Bleeding,
  GIBC_Coffee_Grounds_Vomiting,
  GIBC_High_Risk_Patient,
  GIBC_None
};

// Enum to represent different levels of gastrointestinal bleeding severity
enum GI_Bleeding_Severity {
  GIBS_Ongoing,
  GIBS_Frequent,
  GIBS_Sporadic,
  GIBS_None
};

// Struct to represent gastrointestinal bleeding symptoms
struct GI_Bleeding_Symptoms {
  enum GI_Bleeding_Category category;
  enum GI_Bleeding_Severity vomiting_fresh_blood;
  enum GI_Bleeding_Severity rectal_bleeding;
  enum GI_Bleeding_Severity coffee_grounds_vomiting;
  bool high_risk_patient;
};

// Function to determine triage level based on symptoms
enum Triage_Level
get_symptoms_gi_bleeding_triage(struct GI_Bleeding_Symptoms symptoms);

// Function implementation
enum Triage_Level
get_symptoms_gi_bleeding_triage(struct GI_Bleeding_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case GIBC_Vomiting_Fresh_Blood:
    triage_level = (symptoms.vomiting_fresh_blood == GIBS_Ongoing)    ? Red
                   : (symptoms.vomiting_fresh_blood == GIBS_Frequent) ? Orange
                   : (symptoms.vomiting_fresh_blood == GIBS_Sporadic)
                       ? Yellow
                       : triage_level;
    break;
  case GIBC_Vital_Signs:
    triage_level = (symptoms.vital_signs == GIBS_Ongoing)    ? Red
                   : (symptoms.vital_signs == GIBS_Frequent) ? Orange
                   : (symptoms.vital_signs == GIBS_Sporadic) ? Yellow
                                                             : triage_level;
    break;
  case GIBC_Rectal_Bleeding:
    triage_level = (symptoms.rectal_bleeding == GIBS_Ongoing)    ? Red
                   : (symptoms.rectal_bleeding == GIBS_Frequent) ? Orange
                   : (symptoms.rectal_bleeding == GIBS_Sporadic) ? Yellow
                                                                 : triage_level;
    break;
  case GIBC_Coffee_Grounds_Vomiting:
    triage_level =
        (symptoms.coffee_grounds_vomiting == GIBS_Ongoing)    ? Red
        : (symptoms.coffee_grounds_vomiting == GIBS_Frequent) ? Orange
        : (symptoms.coffee_grounds_vomiting == GIBS_Sporadic) ? Yellow
                                                              : triage_level;
    break;
  case GIBC_High_Risk_Patient:
    triage_level = (symptoms.high_risk_patient) ? Orange : triage_level;
    break;
  case GIBC_None:
    triage_level = Blue;
    break;
  }

  return triage_level;
}
