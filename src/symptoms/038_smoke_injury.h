#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../triage_level.h"

enum Fluegas_poisoning {FP_soot_in_mouth_affected_cond, FP_soot_in_mouth_unaffected_cond, FP_no_soot_in_airways_but_cough, FP_none};
enum CO_poisoning {COP_Headache_or_previous_unconscious, COP_CO_HB_less_that_25proc, COP_none };
enum Other_chemical_inhalation {OCI_affected_cond, OCI_unaffected_cond, OCI_none};


struct Smoke {
    enum Fluegas_poisoning fluegas;
    enum CO_poisoning coPoisoning;
    enum Other_chemical_inhalation chemicalInhalation;
};

enum Triage_Level get_symptoms_smoke_triage(struct Smoke smoke);


#ifndef PROJECT1_38_SMOKE_INJURY_H
#define PROJECT1_38_SMOKE_INJURY_H

#endif //PROJECT1_38_SMOKE_INJURY_H
