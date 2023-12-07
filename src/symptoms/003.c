#include "../triage_level.h"
#include <stdbool.h>

enum Anorectal_bowel_surgery {
  ARBS_no_bleeding,
  ARBS_with_bleeding,
  ARBS_none
};
enum Anorectal_infection { ARI_yes, ARI_none };
enum Anorectal_foreign_body { ARFB_yes, ARFB_none };

struct Anorectal {
  enum Anorectal_bowel_surgery bowel_surgery;
  enum Anorectal_infection infection;
  enum Anorectal_foreign_body foreign_body;
};

enum Triage_Level get_symptoms_anorectal_triage(struct Anorectal anorectal);
enum Triage_Level get_symptoms_anorectal_triage(struct Anorectal anorectal) {
  enum Triage_Level triage_level = Blue;

  bool red = anorectal.bowel_surgery == ARBS_with_bleeding;

  bool orange = anorectal.bowel_surgery == ARBS_no_bleeding ||
                anorectal.infection == ARI_yes ||
                anorectal.foreign_body == ARFB_yes;

  bool yellow =
      anorectal.infection == ARI_none && anorectal.foreign_body == ARFB_none;

  bool green = anorectal.bowel_surgery == ARBS_none &&
               anorectal.infection == ARI_none &&
               anorectal.foreign_body == ARFB_none;

  if (red) {
    triage_level = Red;
  } else if (orange) {
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
