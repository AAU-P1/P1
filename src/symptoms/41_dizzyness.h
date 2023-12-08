#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../triage_level.h"
#ifndef PROJECT1_41_DIZZYNESS_H
#define PROJECT1_41_DIZZYNESS_H


enum Urgent_neurological_outcomes {UNC_thrombolysis_criteria_met, UNC_language_or_vision_disturbance_24h, UNC_ceased_strength_language_or_vision_disturbance_24h, UNC_none};
enum Duration {DUR_less_than_24h, DUR_more_than_24h, DUR_none};
enum Fainting {FA_multiple_times, FA_one_fainting_within_24h};
enum Pain_scale_above_or_equal_5yr {PAS5_NRS_VAS_4_TO_10_and_yellow_VP_and_affected_cond, PAS5_NRS_VAS_4_TO_10_and_green_VP_and_unaffected_cond, PAS5_NRS_VAS_0_3_and_green_VP_and_unaffected_cond,PAS5_none};
enum Pain_scale_above_2mth_under_5yr {PAS2_5_FLACC_8_10, PAS2_5_FLACC_4_7, PAS2_5_FLACC_0_3,PAS2_5_none};
enum Pain_scale_under_or_equal_2mth {PAS2_NIPS_4_6, PAS2_NIPS_1_3, PAS2_NIPS_0,PAS2_none};
enum Morfika_within_120_min{MORF_yes_and_yellow_pain_scale, MORF_yes_and_green_pain_scale};


struct Dizzy {
    enum Urgent_neurological_outcomes urgentNeurologicalOutcomes;
    enum Duration duration;
    bool suspected_poisoning;
    enum Fainting fainting;
    enum Pain_scale_above_or_equal_5yr painScaleAboveOrEqual5Yr;
    enum Pain_scale_above_2mth_under_5yr painScaleAbove2MthUnder5Yr;
    enum Pain_scale_under_or_equal_2mth painScaleUnderOrEqual2Mth;
    enum Morfika_within_120_min morfika;
};

enum Triage_Level get_symptoms_dizzyness_triage(struct Dizzy dizzy);



#endif //PROJECT1_41_DIZZYNESS_H
