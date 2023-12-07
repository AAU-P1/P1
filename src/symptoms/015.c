#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of burns and frostbite
enum Burn_Frostbite_Category { BFC_Localization_Art, BFC_Severity, BFC_None };

// Enum to represent different severities of burns
enum Burn_Frostbite_Severity {
  BFS_Life_Threatening,
  BFS_Emergency,
  BFS_Urgent,
  BFS_Minor,
  BFS_None
};

// Struct to represent burns and frostbite symptoms
struct Burn_Frostbite_Symptoms {
  enum Burn_Frostbite_Category category;
  bool threatened_airway;
  bool chemical_burn;
  enum Burn_Frostbite_Severity severity;
  int percentage_burned;
};

// Function to determine triage level based on symptoms
enum Triage_Level
get_symptoms_burn_frostbite_triage(struct Burn_Frostbite_Symptoms symptoms);

// Function implementation
enum Triage_Level
get_symptoms_burn_frostbite_triage(struct Burn_Frostbite_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case BFC_Localization_Art:
    triage_level = (symptoms.threatened_airway || symptoms.chemical_burn)
                       ? Red
                       : triage_level;
    break;
  case BFC_Severity:
    triage_level =
        (symptoms.severity == BFS_Life_Threatening) ? Red
        : (symptoms.severity == BFS_Emergency)      ? Orange
        : (symptoms.severity == BFS_Urgent)         ? Yellow
        : (symptoms.severity == BFS_Minor && symptoms.percentage_burned > 3)
            ? Green
            : triage_level;
    break;
  case BFC_None:
    triage_level = Blue;
    break;
  }

  return triage_level;
}
