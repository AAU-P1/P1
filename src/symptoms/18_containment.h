
#ifndef SYM_CONTAINMENT
#define SYM_CONTAINTMENT
#include "../triage_level.h"
#include <stdbool.h>

enum Containment_air_block { CAB_stridor, CAB_general_af, CAB_not_af, CAB_non };
enum Containment_stuck_object { CSO_general_af, CSO_not_af, CSO_non };
enum Containment_if_consume { CIC_battery, CIC_pointy_or_sharp, CIC_rounded, CIC_none };

struct Containment {
    enum Containment_air_block air_block;
    enum Containment_stuck_object stuck_object;
    enum Containment_if_constume if_consume;
};

enum Triage_Level get_symptoms_containment_triage(struct Containment containment);
#endif
