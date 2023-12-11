#ifndef PROJECT1_39_SERVICE_CONTACT_H
#define PROJECT1_39_SERVICE_CONTACT_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../triage_level.h"

struct Service{
    bool social_problems;
    bool authority_statement;
    bool vaccination;
    bool prescription;
};

enum Triage_Level get_symptoms_Service_triage(struct Service service);
#endif //PROJECT1_39_SERVICE_CONTACT_H
