#ifndef SYM_CONTAMINANT
#define SYM_CONTAMINANT
#include "../triage_level.h"
#include <stdbool.h>

enum Contaminant_if_consumet { CIC_Battery, CIC_Sharp_and_pointy, CIC_Rounded_object, CIC_none };
enum Contaminant_sus_struck_object { CSSO_General_condition, CSSO_Not_affected, CSSO_none };
enum Contaminant_sus_airway_blockage {CSAB_Stridor, CSAB_General_condtion, CSAB_Not_affected, CSAB_none};

struct Contaminant {
    enum Contaminant_if_consumet if_consumet;
    enum Contaminant_sus_stuck_object sus_stuck_object;
    enum Contaminant_sus_airway_blockage sus_airway_block;
};

enum Triage_Level get_symptoms_contaminant_triage(struct Contaminant contaminant);

#endif

