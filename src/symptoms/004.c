#include "../triage_level.h"
#include <stdbool.h>

enum Syncope_icd { SI_ongoing_shock, SI_repeated_shocks, SI_none };
enum Syncope_exercise { SE_yes, SE_none };
enum Syncope_repeated_episodes { SRE_yes, SRE_no, SRE_none };
enum Syncope_ekg_impact { SEI_st_t_changes, SEI_narrow_complex, SEI_none };

struct Syncope {
  enum Syncope_icd icd;
  enum Syncope_exercise exercise;
  enum Syncope_repeated_episodes repeated_episodes;
  enum Syncope_ekg_impact ekg_impact;
};

enum Triage_Level get_symptoms_syncope_triage(struct Syncope syncope);
enum Triage_Level get_symptoms_syncope_triage(struct Syncope syncope) {
  enum Triage_Level triage_level = Blue;

  bool red =
      syncope.icd == SI_ongoing_shock || syncope.icd == SI_repeated_shocks;

  bool orange = syncope.exercise == SE_yes ||
                syncope.repeated_episodes == SRE_yes ||
                syncope.ekg_impact == SEI_st_t_changes ||
                syncope.ekg_impact == SEI_narrow_complex;

  bool yellow =
      syncope.repeated_episodes == SRE_no && syncope.ekg_impact == SEI_none;

  if (red) {
    triage_level = Red;
  } else if (orange) {
    triage_level = Orange;
  } else if (yellow) {
    triage_level = Yellow;
  } else {
    triage_level = Blue;
  }

  return triage_level;
}
