#include "001_abstinence.h"

enum Triage_Level get_symptoms_abstinence_triage(struct Abstinence abstinence) {
  enum Triage_Level triage_level = Green;

  bool red = abstinence.cramps == AC_ongoing;

  bool orange = abstinence.cramps == AC_now_discontinued ||
                abstinence.restless == AC_yes_w_conf_or_haluc;

  bool yellow = abstinence.cramps == AC_by_previous_contact ||
                abstinence.restless == AC_yes;

  bool green = abstinence.restless == AC_easy_or_none;

  if (red) {
    triage_level = Red;
  } else if (orange) {
    triage_level = Orange;
  } else if (yellow) {
    triage_level = Yellow;
  } else if (green) {
    triage_level = Green;
  }

  return triage_level;
}
