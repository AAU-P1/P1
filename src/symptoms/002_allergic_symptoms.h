#ifndef SYM_ALLERGIC
#define SYM_ALLERGIC
#include "../triage_level.h"
#include <stdbool.h>

// ################################## MODEL ##################################

enum Allergic_swelling { AS_yes_stridor, AS_yes_mush, AS_none };
enum Allergic_short_breath { ASB_Severe_rd, ASB_rd, ASB_none };
enum Allergic_urticaria { AU_universal, AU_pronounced, AU_local, AU_none };

struct Allergic {
  enum Allergic_swelling swelling;
  enum Allergic_short_breath short_breath;
  bool prev_anaphyl_shock;
  bool itchy_throat;
  enum Allergic_urticaria urticaria;
};

enum Triage_Level get_symptoms_allergic(struct Allergic allergic);

// ################################ CONTROLLER ################################

struct Allergic *input_allergic_symptom();
#endif
