#include "041_dizzyness.h"
enum Triage_Level get_symptoms_dizzy_triage(struct Dizzy dizzy) {
  enum Triage_Level triage_level = Green;

  bool red = dizzy.urgentNeurologicalOutcomes == UNC_thrombolysis_criteria_met;

  bool orange = dizzy.urgentNeurologicalOutcomes ==
                    UNC_language_or_vision_disturbance_24h ||
                dizzy.duration == DUR_less_than_24h ||
                dizzy.suspected_poisoning == true ||
                dizzy.fainting == FA_multiple_times ||
                dizzy.painScaleAboveOrEqual5Yr ==
                    PAS5_NRS_VAS_4_TO_10_and_yellow_VP_and_affected_cond ||
                dizzy.painScaleAbove2MthUnder5Yr == PAS2_5_FLACC_8_10 ||
                dizzy.painScaleUnderOrEqual2Mth == PAS2_NIPS_4_6 ||
                dizzy.morfika == MORF_yes_and_yellow_pain_scale;

  bool yellow = dizzy.urgentNeurologicalOutcomes ==
                    UNC_ceased_strength_language_or_vision_disturbance_24h ||
                dizzy.fainting == FA_one_fainting_within_24h ||
                dizzy.painScaleAboveOrEqual5Yr ==
                    PAS5_NRS_VAS_4_TO_10_and_green_VP_and_unaffected_cond ||
                dizzy.painScaleAbove2MthUnder5Yr == PAS2_5_FLACC_4_7 ||
                dizzy.painScaleUnderOrEqual2Mth == PAS2_NIPS_1_3 ||
                dizzy.morfika == MORF_yes_and_green_pain_scale;

  bool green = dizzy.duration == DUR_more_than_24h ||
               dizzy.painScaleAboveOrEqual5Yr ==
                   PAS5_NRS_VAS_0_3_and_green_VP_and_unaffected_cond ||
               dizzy.painScaleAbove2MthUnder5Yr == PAS2_5_FLACC_0_3 ||
               dizzy.painScaleUnderOrEqual2Mth == PAS2_NIPS_0;

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
