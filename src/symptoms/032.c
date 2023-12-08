#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent male genital symptoms
struct Male_Genital_Symptoms {
  bool torsio_testis;
  bool priapismus;
  bool scrotal_hematoma;
  float pain_intensity_adults;
  float pain_intensity_children;
  bool yellow_vp;
  bool green_vp;
  bool natural_movement;
  bool unaffected_general_condition;
};

// Function to determine triage level based on male genital symptoms
enum Triage_Level get_male_genital_symptoms_triage(
    struct Male_Genital_Symptoms male_genital_symptoms);

// Function implementation
enum Triage_Level get_male_genital_symptoms_triage(
    struct Male_Genital_Symptoms male_genital_symptoms) {
  enum Triage_Level triage_level = Blue;

  if (male_genital_symptoms.torsio_testis || male_genital_symptoms.priapismus) {
    triage_level = Red; // Life-threatening
  } else if (male_genital_symptoms.scrotal_hematoma &&
             male_genital_symptoms.unaffected_general_condition) {
    triage_level = Orange; // Urgent
  } else if ((male_genital_symptoms.pain_intensity_adults >= 4 &&
              male_genital_symptoms.yellow_vp) ||
             (male_genital_symptoms.pain_intensity_adults < 4 &&
              male_genital_symptoms.green_vp) ||
             (male_genital_symptoms.pain_intensity_children >= 4 &&
              male_genital_symptoms.yellow_vp) ||
             (male_genital_symptoms.pain_intensity_children < 4 &&
              male_genital_symptoms.green_vp)) {
    triage_level = Yellow; // Less urgent
  }

  return triage_level;
}
