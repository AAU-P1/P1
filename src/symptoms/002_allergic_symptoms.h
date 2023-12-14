#ifndef SYM_ALLERGIC
#define SYM_ALLERGIC
#include "../triage_level.h"
#include <stdbool.h>

// ################################## MODEL ##################################

typedef enum { AS_YES_STRIDOR, AS_YES_MUSH, AS_NONE } AllergicSwelling;
typedef enum { ASB_SEVERE_RD, ASB_RD, ASB_NONE } AllergicShortBreath;
typedef enum {
  AU_UNIVERSAL,
  AU_PRONOUNCED,
  AU_LOCAL,
  AU_NONE
} AllergicUrticaria;

typedef struct {
  AllergicSwelling swelling;
  AllergicShortBreath shortBreath;
  bool prevAnaphylShock;
  bool itchyThroat;
  AllergicUrticaria urticaria;
} Allergic;

TriageLevel getSymptomAllergicTriage(Allergic allergic);

// ############################ CONTROLLER/VIEW #############################

Allergic *inputSymptomAllergic();
#endif
