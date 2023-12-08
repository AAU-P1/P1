#include "34_Neurological_outcome_symptoms.h"

enum Triage_Level get_symptoms_neurological_triage(struct Neurological Neurological) {
    enum Triage_Level triage_level = Green;

    bool orange = Neurological.strength_reduction == NS_Continous_symptoms ||
                  Neurological.speaking_issues == NS_Continous_symptoms||
                  Neurological.visual_failure == NS_Continous_symptoms;

    bool yellow =
            Neurological.strength_reduction == NS_Ceased_symptoms||
            Neurological.speaking_issues == NS_Ceased_symptoms||
            Neurological.visual_failure == NS_Ceased_symptoms;


    if (Neurological.Trombolysis == true) {
        triage_level = Red;
    } else if (orange) {
        triage_level = Orange;
    } else if (yellow) {
            triage_level = Yellow;
    } else {
        Yellow;
    }


    return triage_level;
}

