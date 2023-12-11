#ifndef SYM_ABSTINENCE
#define SYM_ABSTINENCE
#include "../triage_level.h"
#include <stdbool.h>

// ################################## MODEL ##################################

enum Abstinence_cramps {
  AC_ongoing,
  AC_now_discontinued,
  AC_by_previous_contact,
  AC_none
};
enum Abstinence_restless { AC_yes_w_conf_or_haluc, AC_yes, AC_easy_or_none };

struct Abstinence {
  enum Abstinence_cramps cramps;
  enum Abstinence_restless restless;
};

enum Triage_Level get_symptoms_abstinence_triage(struct Abstinence abstinence);

// ################################ CONTROLLER ################################

struct Abstinence *input_abstinence_symptom();
#endif
