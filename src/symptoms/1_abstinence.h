#ifndef SYM_ABSTINENCE
#define SYM_ABSTINENCE
#include "../triage_level.h"
#include <stdbool.h>

enum Abstinence_cramps { Ongoing, Now_discontinued, By_previous_contact, None };
enum Abstinence_restless { Yes_w_conf_or_haluc, Yes, Easy_or_none };

struct Abstinence {
  enum Abstinence_cramps cramps;
  enum Abstinence_restless restless;
};

enum Triage_Level get_symptoms_abstinence_triage(struct Abstinence abstinence);

#endif
