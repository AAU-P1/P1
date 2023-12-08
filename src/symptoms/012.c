#include "../triage_level.h"
#include <stdbool.h>

// Enum to represent different categories of extremity and wound injuries
enum Extremity_Wound_Injury_Category {
  EWI_Amputation,
  EWI_Suspected_Fracture,
  EWI_Bleeding,
  EWI_Suspected_Joint_Injury,
  EWI_Infection_After_Injury,
  EWI_Soft_Tissue_Injury
};

// Enum to represent different types of fractures
enum Extremity_Wound_Injury_Fracture_Type {
  EWI_FT_Proximal_Ankle_Wrist,
  EWI_FT_Distal_Ankle_Wrist,
  EWI_FT_Suspected_Multiple_Fractures,
  EWI_FT_Open_Fracture,
  EWI_FT_Closed_Femur,
  EWI_FT_Closed_NonFemur
};

// Enum to represent different types of bleeding
enum Extremity_Wound_Injury_Bleeding_Type {
  EWI_BT_Continuous_Bleeding,
  EWI_BT_Inadequate_Hemostasis,
  EWI_BT_Hemostasis_with_Binding
};

// Enum to represent different types of joint injuries
enum Extremity_Wound_Injury_Joint_Injury_Type {
  EWI_JIT_Luxation,
  EWI_JIT_Sprain
};

// Enum to represent different types of infections
enum Extremity_Wound_Injury_Infection_Type {
  EWI_IT_Progressing_Discoloration_Warmth,
  EWI_IT_Suspected_Deep_Infection,
  EWI_IT_Superficial_Infection
};

// Enum to represent different types of soft tissue injuries
enum Extremity_Wound_Injury_Soft_Tissue_Injury_Type {
  EWI_STIT_Compartment_Syndrome,
  EWI_STIT_Requiring_Revisions,
  EWI_STIT_Suturing_Required,
  EWI_STIT_Superficial_Foreign_Object,
  EWI_STIT_Suspected_Closed_Tendon_Lesion
};

// Struct to represent an extremity and wound injury
struct Extremity_Wound_Injury {
  enum Extremity_Wound_Injury_Category category;
  bool life_threatening;
  bool urgent;
  enum Extremity_Wound_Injury_Fracture_Type fracture_type;
  enum Extremity_Wound_Injury_Bleeding_Type bleeding_type;
  enum Extremity_Wound_Injury_Joint_Injury_Type joint_injury_type;
  enum Extremity_Wound_Injury_Infection_Type infection_type;
  enum Extremity_Wound_Injury_Soft_Tissue_Injury_Type soft_tissue_injury_type;
};

// Function to determine triage level based on injury symptoms
enum Triage_Level
get_symptoms_extremity_wound_triage(struct Extremity_Wound_Injury injury);

// Example usage in the main function
int main() {
  struct Extremity_Wound_Injury example_injury = {
      .category = EWI_Amputation,
      .life_threatening = true,
      .urgent = false,
      .fracture_type = EWI_FT_Proximal_Ankle_Wrist};

  enum Triage_Level triage_level =
      get_symptoms_extremity_wound_triage(example_injury);

  // Handle triage_level as needed

  return 0;
}

// Function implementation
enum Triage_Level
get_symptoms_extremity_wound_triage(struct Extremity_Wound_Injury injury) {
  enum Triage_Level triage_level = Blue;

  switch (injury.category) {
  case EWI_Amputation:
    triage_level = Red;
    break;
  case EWI_Suspected_Fracture:
    triage_level = Orange;
    break;
  case EWI_Bleeding:
    triage_level = Yellow;
    break;
  case EWI_Suspected_Joint_Injury:
    triage_level = Orange;
    break;
  case EWI_Infection_After_Injury:
    triage_level = Yellow;
    break;
  case EWI_Soft_Tissue_Injury:
    triage_level = Orange;
    break;
  }

  if (injury.life_threatening || injury.urgent) {
    triage_level = Red;
  }

  return triage_level;
}
