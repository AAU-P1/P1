#include "18_containment.h"

enum Triage_Level get_symptoms_containment_symptoms(struct Containment containment) {
    enum Triage_Level triage_level = Green;

    bool red = containtment.air_block == CAB_stridor;

    bool orange = containtment.air_block == CAB_general_af || containment.stuck_object == CSO_general_af || containtment.if_consume == CIC_battery;

    bool yellow = containtment.air_block == CAB_not_af || containment.if_consume == CIC_pointy_or_sharp;

    bool green = containment.stuck_object == CSO_not_af || containment.if_consume == CIC_rounded;

    if (red) {
        triage_level = Red;
    } else if (orange) {
        triage_level = Orange;
    } else if (yellow) {
        triage_level = Yellow;
    } else if (green){
        triage_level = Green;
    } else {
        triage_level = Blue;
    }

    return triage_level;
}
