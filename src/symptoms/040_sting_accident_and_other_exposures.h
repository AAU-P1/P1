//
// Created by amves on 07/12/2023.
//

#ifndef PROJECT1_40_STING_ACCIDENT_AND_OTHER_EXPOSURES_H
#define PROJECT1_40_STING_ACCIDENT_AND_OTHER_EXPOSURES_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../triage_level.h"

struct Sting_accident{
    bool accidental_sting;
    bool accidental_exposure_with_blood;
    bool sexual_exposure;

};

enum Triage_Level get_symptoms_Sting_accident_triage(struct Sting_accident sting_accident);

#endif //PROJECT1_40_STING_ACCIDENT_AND_OTHER_EXPOSURES_H
