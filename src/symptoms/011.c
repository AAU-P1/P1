#include "../triage_level.h"
#include <stdbool.h>

enum Extremity_WO_Damage_Infection_Inflammation {
  II_Progressing_Discoloration_Swelling_Warmth,
  II_Suspected_Deep_Wound_Infection,
  II_Superficial_Wound_Infection_Swollen_Joints,
  II_None
};

enum Extremity_WO_Damage_DVT_Suspicion {
  DVT_With_Dyspnea,
  DVT_Without_Dyspnea,
  DVT_None
};

enum Extremity_WO_Damage_VP { VP_Yellow, VP_Green };

enum Extremity_WO_Damage_Pain_Assessment {
  PA_FLACC_8_10,
  PA_FLACC_4_7,
  PA_FLACC_0_3,
  PA_NIPS_4_6,
  PA_NIPS_1_3,
  PA_NRS_VAS_4_10,
  PA_NRS_VAS_0_3,
  PA_None
};

enum Extremity_WO_Damage_Movement {
  MOV_Painful,
  MOV_Natural,
};

enum Extremity_WO_Damage_General_Condition { GC_Affected, GC_Unaffected };

enum Extremity_WO_Damage_Morphine_Administration {
  MA_Yes_Yellow_Pain_Assessment,
  MA_Yes_Green_Pain_Assessment,
  MA_None
};

struct Extremity_WO_Damage {
  enum Extremity_WO_Damage_Infection_Inflammation infection_inflamation;
  bool compartment_syndrome_suspected;
  bool affected_neurovascular_conditions;
  enum Extremity_WO_Damage_DVT_Suspicion dvt_suspicion;
  enum Extremity_WO_Damage_Pain_Assessment pain_assesment;
  enum Extremity_WO_Damage_VP vp;
  enum Extremity_WO_Damage_Movement movement;
  enum Extremity_WO_Damage_General_Condition condition;
  enum Extremity_WO_Damage_Morphine_Administration morphine_admin;
};

enum Triage_Level get_symptoms_extremity_triage(struct Extremity_WO_Damage es);

enum Triage_Level get_symptoms_extremity_triage(struct Extremity_WO_Damage es) {
  enum Triage_Level triage_level = Blue;

  bool orange =
      es.infection_inflamation ==
          II_Progressing_Discoloration_Swelling_Warmth ||
      es.compartment_syndrome_suspected ||
      es.affected_neurovascular_conditions ||
      es.dvt_suspicion == DVT_With_Dyspnea ||
      ((es.pain_assesment == PA_NRS_VAS_4_10 ||
        es.pain_assesment == PA_FLACC_8_10 ||
        es.pain_assesment == PA_NIPS_4_6) &&
       (es.vp == VP_Yellow || es.movement == MOV_Painful ||
        es.condition == GC_Affected)) || es.morphine_admin ==
                                            MA_Yes_Yellow_Pain_Assessment;

  bool yellow = es.infection_inflamation == II_Suspected_Deep_Wound_Infection ||
                ((es.pain_assesment == PA_NRS_VAS_4_10 ||
                  es.pain_assesment == PA_FLACC_4_7 ||
                  es.pain_assesment == PA_NIPS_1_3) &&
                 (es.vp == VP_Green && es.movement == MOV_Natural &&
                  es.condition == GC_Affected)) &&
                    MA_Yes_Green_Pain_Assessment;

  bool green = es.dvt_suspicion == DVT_Without_Dyspnea;

  if (orange) {
    triage_level = Orange;
  } else if (yellow) {
    triage_level = Yellow;
  } else if (green) {
    triage_level = Green;
  } else {
    triage_level = Blue;
  }

  return triage_level;
}
