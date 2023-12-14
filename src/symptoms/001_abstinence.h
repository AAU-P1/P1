#ifndef SYM_ABSTINENCE
#define SYM_ABSTINENCE
#include "../triage_level.h"
#include <stdbool.h>

// ################################## MODEL ##################################

typedef enum {
  AC_ONGOING,
  AC_NOW_DISCONTINUED,
  AC_BY_PREVIOUS_CONTACT,
  AC_NONE
} AbstinenceCramps;

typedef enum {
  AR_YES_W_CONF_OR_HALUC,
  AR_YES,
  AR_EASY_OR_NONE
} AbstinenceRestless;

typedef struct {
  AbstinenceCramps cramps;
  AbstinenceRestless restless;
} Abstinence;

TriageLevel getSymptomAbstinenceTriage(Abstinence abstinence);

// ################################ CONTROLLER ################################

Abstinence *inputSymptomAbstinence();
#endif
