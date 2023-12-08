#include "40_sting_accident_and_other_exposures.h"
enum Triage_Level get_symptoms_mental_triage(struct Sting_accident sting_accident) {
    enum Triage_Level triage_level = Green;

    bool blue = sting_accident.accidental_sting ||
            sting_accident.accidental_exposure_with_blood ||
            sting_accident.sexual_exposure;

    if(blue){
        triage_level = Blue;
    }
    return triage_level;
}