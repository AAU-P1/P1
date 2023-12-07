#include "../triage_level.h"
#include <stdbool.h>

enum BiteTraumaCriteria { BTC_met, BTC_none };
enum BiteSwelling { BS_yes, BS_none };
enum BiteBleeding { BB_leakage, BB_hemostasis, BB_none };
enum BiteSkinChanges {
  BSC_universal_uriticaria,
  BSC_local_infection,
  BSC_local_reaction,
  BSC_none
};
enum BiteWounds { BW_deep_lesion, BW_superficial_lesion, BW_none };
enum BiteToxinReaction { BTR_yes, BTR_none };
enum BiteInsectSting { BIS_anaphylactic_shock, BIS_mouth_or_throat, BIS_none };

struct Bite {
  enum BiteTraumaCriteria trauma_criteria;
  enum BiteSwelling swelling;
  enum BiteBleeding bleeding;
  enum BiteSkinChanges skin_changes;
  enum BiteWounds wounds;
  enum BiteToxinReaction toxin_reaction;
  enum BiteInsectSting insect_sting;
};

enum Triage_Level get_symptoms_bite_triage(struct Bite bite);
enum Triage_Level get_symptoms_bite_triage(struct Bite bite) {
  enum Triage_Level triage_level = Blue;

  bool red = bite.trauma_criteria == BTC_met;

  bool orange = bite.swelling == BS_yes || bite.bleeding == BB_leakage ||
                bite.skin_changes == BSC_universal_uriticaria ||
                bite.wounds == BW_deep_lesion ||
                bite.toxin_reaction == BTR_yes ||
                bite.insect_sting == BIS_anaphylactic_shock ||
                bite.insect_sting == BIS_mouth_or_throat;

  bool yellow =
      bite.bleeding == BB_hemostasis ||
      bite.skin_changes == BSC_local_infection ||
      bite.skin_changes == BSC_local_reaction ||
      bite.wounds == BW_superficial_lesion ||
      (bite.insect_sting == BIS_none && bite.toxin_reaction == BTR_none);

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
