#ifndef SYM_CHEST_PAIN
#define SYM_CHEST_PAIN
#include "../triage_level.h"
#include <stdbool.h>

enum Chest_pain_pressing_pain_or_discomfort { yes_latest_day, no_pressing_pain};
enum Chest_pain_duration { minutes_hours_continuous, minutes_passing, no_duration};
enum Chest_pain_ekg_abnomalities {new_st_t_changes_or_wide_complex_arrhythmia, narrow_complex_arrhythmia, no_abnomalities};

struct Chest_pain {
    enum Chest_pain_pressing_pain_or_discomfort pressing_pain;
    enum Chest_pain_duration duration;
    enum Chest_pain_ekg_abnomalities abnomalities;
};

enum Triage_Level get_symptoms_chest_pain_triage(struct Chest_pain Chest_pain);

#endif
