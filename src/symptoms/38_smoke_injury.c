#include "38_smoke_injury.h"

enum Triage_Level get_symptoms_smoke_triage(struct Smoke smoke) {
    enum Triage_Level triage_level = Green;

    bool red = smoke.fluegas == FP_soot_in_mouth_affected_cond;

    bool orange = smoke.fluegas == FP_soot_in_mouth_unaffected_cond ||
            smoke.coPoisoning == COP_Headache_or_previous_unconscious ||
            smoke.chemicalInhalation == OCI_affected_cond;

    bool yellow = smoke.chemicalInhalation == OCI_unaffected_cond;

    bool green = smoke.fluegas == FP_no_soot_in_airways_but_cough ||
            smoke.coPoisoning == COP_CO_HB_less_that_25proc;


    if(red){
        triage_level = Red;
    }else if(orange){
        triage_level = Orange;
    }else if(yellow){
        triage_level = Yellow;
    }else if(green){
        triage_level= Green;
    }else{
        triage_level = Blue;
    }
    return triage_level;
}