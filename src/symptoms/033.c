#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent abdominal and flank symptoms
struct Abdominal_Flank_Symptoms {
  bool abdominal_trauma;
  float pain_intensity_adults;
  float pain_intensity_children;
  bool yellow_vp;
  bool green_vp;
  bool natural_movement;
  bool unaffected_general_condition;
  bool hernia_irreducible;
  bool hernia_reducible;
  bool known_aortic_aneurysm;
  bool elderly_risk;
  bool peritoneal_dialysis;
  bool vomiting_within_4_hours;
  bool ekg_abnormalities;
};

// Function to determine triage level based on abdominal and flank symptoms
enum Triage_Level get_abdominal_flank_symptoms_triage(
    struct Abdominal_Flank_Symptoms abdominal_flank_symptoms);

// Function implementation
enum Triage_Level get_abdominal_flank_symptoms_triage(
    struct Abdominal_Flank_Symptoms abdominal_flank_symptoms) {
  enum Triage_Level triage_level = Blue;

  if (abdominal_flank_symptoms.abdominal_trauma) {
    triage_level = Red; // Life-threatening
  } else if ((abdominal_flank_symptoms.pain_intensity_adults >= 4 && abdominal_flank_symptoms.yellow_vp) ||
             (abdominal_flank_symptoms.pain_intensity_adults < 4 && abdominal_flank_symptoms.green_vp) ||
             (abdominal_flank_symptoms.pain_intensity_children >= 4 && abdominal_flank_symptoms.yellow_vp) ||
