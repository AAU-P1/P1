#include "2_allergic_symptoms.h"

enum Triage_Level get_symptoms_allergic_symptoms(struct Allergic allergic) {
  enum Triage_Level triage_level = Green;

  bool red = allergic.swelling == AS_yes_stridor ||
             allergic.short_breath == ASB_Severe_rd;

  bool orange = allergic.swelling == AS_yes_mush ||
                allergic.short_breath == ASB_rd ||
                allergic.prev_anaphyl_shock || allergic.itchy_throat ||
                allergic.urticaria == AU_universal;

  bool yellow = allergic.urticaria == AU_pronounced;

  if (red) {
    triage_level = Red;
  } else if (orange) {
    triage_level = Orange;
  } else if (yellow) {
    triage_level = Yellow;
  } else {
    triage_level = Green;
  }

  return triage_level;
}
