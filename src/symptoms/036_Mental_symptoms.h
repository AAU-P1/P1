#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../triage_level.h"
#ifndef PROJECT1_MENTAL_SYMPTOMS_H
#define PROJECT1_MENTAL_SYMPTOMS_H



enum Violent_behaviour {VB_lack_of_impulse, VB_cooperative, VB_none};
enum Suicidal {S_ongoing_suicide_attempt, S_suicidal_thoughts, S_wants_help, S_none};
enum Anxiety {ANX_restless_or_tension, ANX_cooperative, ANX_none};
enum Delirium {DE_hallucinations_and_consciousness_influence, DE_hallucinations_aware_of_data, DE_none};


struct Mental {
    enum Violent_behaviour violentBehaviour;
    enum Suicidal suicidal;
    enum Anxiety anxiety;
    enum Delirium delirium;
    bool need_urgent_help;
    bool known_diagnosis;
};

enum Triage_Level get_symptoms_mental_triage(struct Mental mental);



#endif


