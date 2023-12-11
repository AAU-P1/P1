#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../triage_level.h"
#ifndef PROJECT1_37_BACK_AND_NECK_H
#define PROJECT1_37_BACK_AND_NECK_H

enum Trauma {TR_suspected_fracture_with_paralysis, TR_arrival_on_spine_board, TR_suspected_fracture_without_neuro_symptoms, TR_urgent_injury_no_fracture, TR_older_injury_no_fracture};
enum Painscale_above_or_equal_5yr {PASC5_NRS_VAS_4_TO_10_and_yellow_VP_and_affected_cond, PASC5_NRS_VAS_4_TO_10_and_green_VP_and_unaffected_cond, PASC5_NRS_VAS_0_3_and_green_VP_and_unaffected_cond,PASC5_none};
enum Painscale_above_2mth_under_5yr {PASC2_5_FLACC_8_10, PASC2_5_FLACC_4_7, PASC2_5_FLACC_0_3,PASC2_5_none};
enum Painscale_under_or_equal_2mth {PASC2_NIPS_4_6, PASC2_NIPS_1_3, PASC2_NIPS_0,PASC2_none};
enum Morfika_within_120min{MORFI_yes_and_yellow_pain_scale, MORFI_yes_and_green_pain_scale, MORFI_none};
enum Nerve_influence{NI_decreased_feel_in_abdomen_or_urinary_retention, NI_non_urgent, NI_chronic};


struct Back_and_neck {
    enum Trauma trauma;
    enum Painscale_above_or_equal_5yr painscaleAboveOrEqual5Yr;
    enum Painscale_above_2mth_under_5yr painscaleAbove2MthUnder5Yr;
    enum Painscale_under_or_equal_2mth painscaleUnderOrEqual2Mth;
    enum Morfika_within_120min morfikawithin120Min;
    enum Nerve_influence nerveInfluence;
};

enum Triage_Level get_symptoms_back_and_neck_triage(struct Back_and_neck back_and_neck);


#endif //PROJECT1_37_BACK_AND_NECK_H
