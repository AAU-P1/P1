#include "../triage_level.h"
#include <stdbool.h>
#include "032_men_genital_organ_symptons.h"

enum Triage_Level get_symptoms_men_genital_organs_triage(
        struct Men_genital_organs men_genital_organs) {
    enum Triage_Level triage_level = Green;

    bool orange =
            men_genital_organs.suspected_torsio_testis == true ||
            men_genital_organs.suspected_priapimus == true ||
            men_genital_organs.suspected_scrotal_hematoma == true ||
            men_genital_organs.pain_adult_or_kids_5yr_or_older ==
            MGOPAOKOO_NRS_VAS_4_to_10_and_one_or_more_of_yellow_VP_painful_movementpatterns_affected_regular_condition ||
            men_genital_organs.pain_kids_older_than_2mth_and_younger_than_5yrs ==
            MGOPKOTAYT_FLACC_8_to_10 ||
            men_genital_organs.pain_kids_younger_than_2mth ==
            MGOPKYT_NIPS_4_to_6 ||
            men_genital_organs.morphine_within_120min_before_arrival ==
            MGOMWBA_yellow_pain_evaluation ||
            men_genital_organs.Men_genital_organs_newly_arisen_confusionon ==
            true;

    bool yellow =
            men_genital_organs.pain_adult_or_kids_5yr_or_older ==
            MGOPAOKOO_NRS_VAS_4_to_10_and_green_VP_free_and_natural_movementpatterns_non_affected_regular_condition ||
            men_genital_organs.pain_kids_older_than_2mth_and_younger_than_5yrs ==
            MGOPKOTAYT_FLACC_4_to_7 ||
            men_genital_organs.pain_kids_younger_than_2mth ==
            MGOPKYT_NIPS_1_to_3 ||
            men_genital_organs.morphine_within_120min_before_arrival ==
            MGOMWBA_green_pain_evaluation ||
            men_genital_organs.Men_genital_organs_suspected_infection ==
            true ||
            men_genital_organs.Men_genital_organs_risk_patient == true;

    bool green =
            men_genital_organs.pain_adult_or_kids_5yr_or_older ==
            MGOPAOKOO_NRS_VAS_0_to_3_and_green_VP_free_and_natural_movementpatterns_non_affected_regular_condition ||
            men_genital_organs.pain_kids_older_than_2mth_and_younger_than_5yrs ==
            MGOPKOTAYT_FLACC_0_to_3 ||
            men_genital_organs.pain_kids_younger_than_2mth == MGOPKYT_NIPS_0;

    if (orange) {
    } else if (yellow) {
        triage_level = Yellow;
    } else if (green) {
        triage_level = Green;
    }

    return triage_level;
}
