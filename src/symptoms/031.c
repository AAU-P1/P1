#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent laboratory results
struct Lab_Results {
  float hemoglobin;
  float potassium;
  float lactate;
  float inr;
  float sodium;
  float calcium_ionized;
};

// Function to determine triage level based on laboratory results
enum Triage_Level get_lab_results_triage(struct Lab_Results lab_results);

// Function implementation
enum Triage_Level get_lab_results_triage(struct Lab_Results lab_results) {
  enum Triage_Level triage_level = Blue;

  if (lab_results.hemoglobin < 4.5 && lab_results.hemoglobin > 0 &&
      lab_results.lactate > 4.0) {
    triage_level = Red; // Life-threatening
  } else if (lab_results.potassium > 7.0 ||
             (lab_results.potassium > 6.5 && lab_results.potassium <= 7.0) ||
             (lab_results.potassium > 6.0 && lab_results.lactate > 4.0) ||
             lab_results.potassium < 2.5 || lab_results.potassium < 3.0) {
    triage_level = Orange; // Urgent
  } else if (lab_results.inr > 6.0 || lab_results.sodium > 155 ||
             lab_results.sodium < 120 ||
             (lab_results.calcium_ionized > 1.6 &&
              lab_results.calcium_ionized <= 1.8) ||
             (lab_results.calcium_ionized > 1.5 &&
              lab_results.calcium_ionized <= 1.6) ||
             (lab_results.calcium_ionized < 0.8 &&
              lab_results.calcium_ionized >= 0.0) ||
             (lab_results.calcium_ionized < 1.0 &&
              lab_results.calcium_ionized >= 0.8)) {
    triage_level = Yellow; // Less urgent
  }

  return triage_level;
}
