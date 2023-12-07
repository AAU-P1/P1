#include <stdio.h>
#include <stdlib.h>
#include "../triage_level.h"
#ifndef PROJECT1_35_NOSE_SYMPTOMS_H
#define PROJECT1_35_NOSE_SYMPTOMS_H


enum nose_bleed {NB_ongoing_bleeding_circular_affected, NB_ongoing_bleeding_circular_unaffected, NB_none};

struct Nose_symptom {
    enum nose_bleed nose_bleed;
};

enum Triage_Level get_symptoms_nose_triage(struct Nose_symptom nose_symptom);



#endif
