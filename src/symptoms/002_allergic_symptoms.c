#include "002_allergic_symptoms.h"
#include "../controller.h"
#include <stdlib.h>

// ################################## MODEL ##################################

/*
 * return the triage level from an Allergic struct
 * @param allergic: Allergic struct
 */
TriageLevel getSymptomAllergicTriage(Allergic allergic) {
  TriageLevel triageLevel = T_GREEN;

  bool red = allergic.swelling == AS_YES_STRIDOR ||
             allergic.shortBreath == ASB_SEVERE_RD;

  bool orange = allergic.swelling == AS_YES_MUSH ||
                allergic.shortBreath == ASB_RD || allergic.prevAnaphylShock ||
                allergic.itchyThroat || allergic.urticaria == AU_UNIVERSAL;

  bool yellow = allergic.urticaria == AU_PRONOUNCED;

  if (red) {
    triageLevel = T_RED;
  } else if (orange) {
    triageLevel = T_ORANGE;
  } else if (yellow) {
    triageLevel = T_YELLOW;
  } else {
    triageLevel = T_GREEN;
  }

  return triageLevel;
}

// ################################ CONTROLLER ################################

/*
 * returns Allergic struct from user input
 */
Allergic *inputSymptomAllergic() {

  Allergic *allergic = (Allergic *)malloc(sizeof(Allergic));
  if (allergic == NULL) {
    exit(EXIT_FAILURE);
  }

  char c;
  clearScreen();
  inputChar(&c,
            "Does the patient have allergic swelling? Yes_(S)tridor, "
            "Yes_(M)ush, (N)one",
            "SsMmNn");

  switch (c) {
  case 'S':
  case 's':
    allergic->swelling = AS_YES_STRIDOR;
    break;
  case 'M':
  case 'm':
    allergic->swelling = AS_YES_MUSH;
    break;
  case 'N':
  case 'n':
    allergic->swelling = AS_NONE;
    break;
  }

  clearScreen();
  inputChar(&c,
            "Does the patient have shortness of breath? "
            "(S)evere_rest_dyspnea, (R)est_dyspnea, (N)one",
            "SsRrNn");

  switch (c) {
  case 'S':
  case 's':
    allergic->shortBreath = ASB_SEVERE_RD;
    break;
  case 'R':
  case 'r':
    allergic->shortBreath = ASB_RD;
    break;
  case 'N':
  case 'n':
    allergic->shortBreath = ASB_NONE;
    break;
  }

  clearScreen();
  inputChar(&c,
            "Does the patient have previous anaphylactic shock? (Y)es, (N)o",
            "YyNn");

  switch (c) {
  case 'Y':
  case 'y':
    allergic->prevAnaphylShock = true;
    break;
  case 'N':
  case 'n':
    allergic->prevAnaphylShock = false;
    break;
  }

  clearScreen();
  inputChar(&c, "Does the patient have an itchy throat? (Y)es, (N)o", "YyNn");

  switch (c) {
  case 'Y':
  case 'y':
    allergic->itchyThroat = true;
    break;
  case 'N':
  case 'n':
    allergic->itchyThroat = false;
    break;
  }

  clearScreen();
  inputChar(&c,
            "Does the patient have urticaria? (U)niversal, (P)ronounced, "
            "(L)ocal, (N)one)",
            "UuPpLlNn");

  switch (c) {
  case 'U':
  case 'u':
    allergic->urticaria = AU_UNIVERSAL;
    break;
  case 'P':
  case 'p':
    allergic->urticaria = AU_PRONOUNCED;
    break;
  case 'L':
  case 'l':
    allergic->urticaria = AU_LOCAL;
    break;
  case 'N':
  case 'n':
    allergic->urticaria = AU_NONE;
    break;
  }
  return allergic;
}
