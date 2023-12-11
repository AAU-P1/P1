#ifndef PROJECT1_34_NEUROLOGICAL_OUTCOME_SYMPTOMS_H
#define PROJECT1_34_NEUROLOGICAL_OUTCOME_SYMPTOMS_H
#include "../triage_level.h"
#include <stdbool.h>

enum neurological_symptom {NS_Continous_symptoms, NS_Ceased_symptoms};


struct Neurological {
    enum neurological_symptom strength_reduction;
    enum neurological_symptom speaking_issues;
    enum neurological_symptom visual_failure;
    bool Trombolysis;
};

enum Triage_Level get_symptoms_neurological_triage(struct Neurological Neurological);

#endif //PROJECT1_34_NEUROLOGICAL_OUTCOME_SYMPTOMS_H
