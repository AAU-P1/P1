#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of foreign body symptoms
enum Foreign_Body_Category {
  FBC_Airway_Blockage_Suspected,
  FBC_Difficulty_Swallowing,
  FBC_Type_Of_Foreign_Body,
  FBC_Location_Ear_Nose_Throat,
  FBC_None
};

// Enum to represent different types of foreign bodies
enum Foreign_Body_Type {
  FBT_Stridor,
  FBT_Impaired_General_Condition,
  FBT_Unaffected,
  FBT_None
};

// Enum to represent different locations for foreign bodies in Ear/Nose/Throat
enum Foreign_Body_Location { FBL_Ear_Nose_Throat, FBL_Yes, FBL_None };

// Struct to represent foreign body symptoms
struct Foreign_Body_Symptoms {
  enum Foreign_Body_Category category;
  enum Foreign_Body_Type airway_blockage_suspected;
  enum Foreign_Body_Type difficulty_swallowing;
  enum Foreign_Body_Type type_of_foreign_body;
  enum Foreign_Body_Location location_ear_nose_throat;
};

// Function to determine triage level based on symptoms
enum Triage_Level
get_symptoms_foreign_body_triage(struct Foreign_Body_Symptoms symptoms);

// Function implementation
enum Triage_Level
get_symptoms_foreign_body_triage(struct Foreign_Body_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case FBC_Airway_Blockage_Suspected:
    triage_level =
        (symptoms.airway_blockage_suspected == FBT_Stridor) ? Red
        : (symptoms.airway_blockage_suspected == FBT_Impaired_General_Condition)
            ? Orange
        : (symptoms.airway_blockage_suspected == FBT_Unaffected) ? Green
                                                                 : triage_level;
    break;
  case FBC_Difficulty_Swallowing:
    triage_level =
        (symptoms.difficulty_swallowing == FBT_Impaired_General_Condition)
            ? Orange
        : (symptoms.difficulty_swallowing == FBT_Unaffected) ? Green
                                                             : triage_level;
    break;
  case FBC_Type_Of_Foreign_Body:
    triage_level = (symptoms.type_of_foreign_body == FBT_Unaffected)
                       ? Green
                       : triage_level;
    break;
  case FBC_Location_Ear_Nose_Throat:
    triage_level =
        (symptoms.location_ear_nose_throat == FBL_Yes) ? Yellow : triage_level;
    break;
  case FBC_None:
    triage_level = Blue;
    break;
  }

  return triage_level;
}
