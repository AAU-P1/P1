#include "27_jaundice_and_or_ascites.h"

enum Triage_Level get_symptoms_jaundice_and_or_ascites_triage(struct Jaundice_and_or_ascites jaundice_and_or_ascites) {
    enum Triage_Level triage_level = Green;


    bool orange = jaundice_and_or_ascites.pain_adult_or_kids_5yr_or_older == JAOAPAOKOO_NRS_VAS_4_to_10_and_one_or_more_of_yellow_VP_painful_movementpatterns_affected_regular_condition || jaundice_and_or_ascites.pain_kids_older_than_2mth_and_younger_than_5yrs == JAOAPKOTAYT_FLACC_8_to_10 || jaundice_and_or_ascites.pain_kids_younger_than_2mth == JAOAPKYT_NIPS_4_to_6 || jaundice_and_or_ascites.morphine_within_120min_before_arrival == JAOAMWBA_yellow_pain_evaluation || jaundice_and_or_ascites.Jaundice_and_or_ascites_newly_arisen_confusion == true;

    bool yellow = jaundice_and_or_ascites.pain_adult_or_kids_5yr_or_older == JAOAPAOKOO_NRS_VAS_4_to_10_and_green_VP_free_and_natural_movementpatterns_non_affected_regular_condition || jaundice_and_or_ascites.pain_kids_older_than_2mth_and_younger_than_5yrs == JAOAPKOTAYT_FLACC_4_to_7 || jaundice_and_or_ascites.pain_kids_younger_than_2mth == JAOAPKYT_NIPS_1_to_3 || jaundice_and_or_ascites.morphine_within_120min_before_arrival == JAOAMWBA_green_pain_evaluation || jaundice_and_or_ascites.Jaundice_and_or_ascites_suspected_infection == true || jaundice_and_or_ascites.Jaundice_and_or_ascites_risk_patient == true;

    bool green = jaundice_and_or_ascites.pain_adult_or_kids_5yr_or_older == JAOAPAOKOO_NRS_VAS_0_to_3_and_green_VP_free_and_natural_movementpatterns_non_affected_regular_condition || jaundice_and_or_ascites.pain_kids_older_than_2mth_and_younger_than_5yrs == JAOAPKOTAYT_FLACC_0_to_3 || jaundice_and_or_ascites.pain_kids_younger_than_2mth == JAOAPKYT_NIPS_0;

    if (orange) {
    } else if (yellow) {
        triage_level = Yellow;
    } else if (green) {
        triage_level = Green;
    }

    return triage_level;
}
