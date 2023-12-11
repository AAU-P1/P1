#include "037_Back_and_neck.h"
enum Triage_Level
get_symptoms_back_and_neck_triage(struct Back_and_neck back_and_neck) {
  enum Triage_Level triage_level = Green;

  bool red = back_and_neck.trauma == TR_suspected_fracture_with_paralysis;

  bool orange =
      back_and_neck.trauma == TR_arrival_on_spine_board ||
      back_and_neck.painscaleAboveOrEqual5Yr ==
          PASC5_NRS_VAS_4_TO_10_and_yellow_VP_and_affected_cond ||
      back_and_neck.painscaleAbove2MthUnder5Yr == PASC2_5_FLACC_8_10 ||
      back_and_neck.painscaleUnderOrEqual2Mth == PASC2_NIPS_4_6 ||
      back_and_neck.morfikawithin120Min == MORFI_yes_and_yellow_pain_scale ||
      back_and_neck.nerveInfluence ==
          NI_decreased_feel_in_abdomen_or_urinary_retention;

  bool yellow =
      back_and_neck.trauma == TR_suspected_fracture_without_neuro_symptoms ||
      back_and_neck.painscaleAboveOrEqual5Yr ==
          PASC5_NRS_VAS_4_TO_10_and_green_VP_and_unaffected_cond ||
      back_and_neck.painscaleAbove2MthUnder5Yr == PASC2_5_FLACC_4_7 ||
      back_and_neck.painscaleUnderOrEqual2Mth == PASC2_NIPS_1_3 ||
      back_and_neck.morfikawithin120Min == MORFI_yes_and_green_pain_scale ||
      back_and_neck.nerveInfluence == NI_non_urgent;

  bool green = back_and_neck.trauma == TR_urgent_injury_no_fracture ||
               back_and_neck.painscaleAboveOrEqual5Yr ==
                   PASC5_NRS_VAS_0_3_and_green_VP_and_unaffected_cond ||
               back_and_neck.painscaleAbove2MthUnder5Yr == PASC2_5_FLACC_0_3 ||
               back_and_neck.painscaleUnderOrEqual2Mth == PASC2_NIPS_0 ||
               back_and_neck.nerveInfluence == NI_chronic;

  if (red) {
    triage_level = Red;
  } else if (orange) {
    triage_level = Orange;
  } else if (yellow) {
    triage_level = Yellow;
  } else if (green) {
    triage_level = Green;
  } else {
    triage_level = Blue;
  }
  return triage_level;
}
