#include "026_skin_and_mucous_membrane_symptoms.h"

enum Triage_Level get_symptoms_Skin_and_mucous_membrane_triage(
    struct Skin_and_mucous_membrane skin_and_mucous_membrane) {
  enum Triage_Level triage_level = Blue;

  bool red = skin_and_mucous_membrane.SAMM_suspected_meningitis == true;

  bool orange =
      skin_and_mucous_membrane.infection_or_inflammation ==
          SAMMSIOI_fast_progressing_miscoloring_warmth_and_swelling_or_affected_condition ||
      skin_and_mucous_membrane
              .SAMM_can_skin_loosen_by_simple_friction_and_leave_open_liquid_wounds ==
          true ||
      skin_and_mucous_membrane.rash_debut == SAMMSRD_over_hours ||
      skin_and_mucous_membrane.urticaria == SAMMSU_universal;

  bool yellow = skin_and_mucous_membrane.infection_or_inflammation ==
                    SAMMSIOI_suspected_deep_wound_infection_or_lymphangitis ||
                skin_and_mucous_membrane.rash_debut == SAMMSRD_over_days ||
                skin_and_mucous_membrane.urticaria == SAMMSU_outspread ||
                skin_and_mucous_membrane.absces_amount_and_location ==
                    SAMMSAAAL_multiple_and_near_joints;

  bool green = skin_and_mucous_membrane.urticaria == SAMMSU_local;

  bool blue = skin_and_mucous_membrane.infection_or_inflammation ==
                  SAMMSIOI_shallow_wound_infection_or_swelling_joints ||
              skin_and_mucous_membrane.absces_amount_and_location ==
                  SAMMSAAAL_single_absces;

  if (red) {
    triage_level = Red;
  } else if (orange) {
    triage_level = Orange;
  } else if (yellow) {
    triage_level = Yellow;
  } else if (green) {
    triage_level = Green;
  } else if (blue) {
    triage_level = Blue;
  }

  return triage_level;
}
