#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of skin and mucous membrane symptoms
enum Skin_Mucous_Symptoms_Category {
  SMS_Bleeding,
  SMS_Infection_Inflammation,
  SMS_Epidermal_Detachment,
  SMS_Rash_Onset,
  SMS_Urticaria,
  SMS_Abscess,
  SMS_None
};

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent skin and mucous membrane symptoms
struct Skin_Mucous_Symptoms {
  enum Skin_Mucous_Symptoms_Category category;
  enum Severity_Level severity;
  bool red_vp;
  bool multiple_abscess;
};

// Function to determine triage level based on symptoms
enum Triage_Level
get_symptoms_skin_mucous_triage(struct Skin_Mucous_Symptoms symptoms);

// Function implementation
enum Triage_Level
get_symptoms_skin_mucous_triage(struct Skin_Mucous_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case SMS_Bleeding:
    triage_level = (symptoms.red_vp) ? Red : triage_level;
    break;
  case SMS_Infection_Inflammation:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case SMS_Epidermal_Detachment:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case SMS_Rash_Onset:
    triage_level = (symptoms.severity == SL_Urgent) ? Orange : triage_level;
    break;
  case SMS_Urticaria:
    triage_level = (symptoms.red_vp) ? Red : triage_level;
    break;
  case SMS_Abscess:
    triage_level = (symptoms.multiple_abscess) ? Red : triage_level;
    break;
  case SMS_None:
    triage_level = Blue;
    break;
  }

  return triage_level;
}
