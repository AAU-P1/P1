//
// Created by Mathias Birkholm on 07/12/2023.
//
#include "18_contaminant.h.h"

enum Triage_Level get_symptoms_contaminant_triage(struct contaminant contaminant) {
    enum Triage_Level triage_level = Green;

    bool red = contaminant.sus_airway_block == stridor

    bool orange = contaminant.if_consumet == battery ||
    contaminant.sus_airway_block == affected_general_condition ||
    contaminant.sus_stuck_object == general_condition;

    bool yellow = contaminant.if_consumet == pointy_or_sharp ||
            contaminant.sus_airway_block == not_affected;

    bool green = contaminant.if_consumet == rounded_objects ||
            contaminant.sus_stuck_object == not_affected;


    if (red) {
        triage_level = Red;
    } else if (orange) {
        triage_level = Orange;
    } else if (yellow) {
        triage_level = Yellow;
    } else if (green) {
        triage_level = Green;
    }

    return triage_level;
}
