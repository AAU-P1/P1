#include "010_chest_pains.h"

enum Triage_Level get_symptoms_chest_pain_triage(struct Chest_pain Chest_pain) {
  enum Triage_Level triage_level = Green;

  bool orange =
      Chest_pain.duration == minutes_hours_continuous ||
      Chest_pain.pressing_pain == yes_latest_day ||
      Chest_pain.abnomalities == new_st_t_changes_or_wide_complex_arrhythmia;

  bool yellow = Chest_pain.abnomalities == narrow_complex_arrhythmia ||
                Chest_pain.duration == minutes_passing;

  bool green = Chest_pain.duration == no_duration ||
               Chest_pain.abnomalities == no_abnomalities ||
               Chest_pain.pressing_pain == no_pressing_pain;

  if (orange) {
    triage_level = Orange;
  } else if (yellow) {
    triage_level = Yellow;
  } else if (green) {
    triage_level = Green;
  }

  return triage_level;
}
