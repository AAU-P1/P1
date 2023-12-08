#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of head and facial symptoms
enum Head_Facial_Symptoms_Category {
  HFS_Mental_Status,
  HFS_Pupil_Difference,
  HFS_Facial_Skeletal_Injury,
  HFS_Soft_Tissue_Lesion,
  HFS_Epistaxis,
  HFS_None
};

// Enum to represent different levels of severity
enum Severity_Level {
  SL_Life_Threatening,
  SL_Urgent,
  SL_Less_Urgent,
  SL_Not_Urgent
};

// Struct to represent head and facial symptoms
struct Head_Facial_Symptoms {
  enum Head_Facial_Symptoms_Category category;
  enum Severity_Level severity;
  bool red_vp;
};

// Function to determine triage level based on symptoms
enum Triage_Level
get_symptoms_head_facial_triage(struct Head_Facial_Symptoms symptoms);

// Function implementation
enum Triage_Level
get_symptoms_head_facial_triage(struct Head_Facial_Symptoms symptoms) {
  enum Triage_Level triage_level = Blue;

  switch (symptoms.category) {
  case HFS_Mental_Status:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case HFS_Pupil_Difference:
    triage_level = (symptoms.red_vp) ? Red : triage_level;
    break;
  case HFS_Facial_Skeletal_Injury:
    triage_level =
        (symptoms.severity == SL_Life_Threatening) ? Red : triage_level;
    break;
  case HFS_Soft_Tissue_Lesion:
    triage_level = (symptoms.severity == SL_Urgent) ? Orange : triage_level;
    break;
  case HFS_Epistaxis:
    triage_level = (symptoms.red_vp) ? Red : triage_level;
    break;
  case HFS_None:
    triage_level = (symptoms.severity == SL_Not_Urgent) ? Green : triage_level;
    break;
  }

  return triage_level;
}
