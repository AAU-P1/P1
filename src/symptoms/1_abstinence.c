#include "1_abstinence.h"

enum Triage_Level get_symptoms_abstinence_triage(struct Abstinence abstinence) {
  enum Triage_Level triage_level = Green;

  bool red = abstinence.cramps == Ongoing;

  bool orange = abstinence.cramps == Now_discontinued ||
                abstinence.restless == Yes_w_conf_or_haluc;

  bool yellow =
      abstinence.cramps == By_previous_contact || abstinence.restless == Yes;

  bool green = abstinence.restless == Easy_or_none;

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
