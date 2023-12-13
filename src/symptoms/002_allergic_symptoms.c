#include "002_allergic_symptoms.h"
#include "../controller.h"
#include <stdlib.h>

// ################################## MODEL ##################################

/*
 * return the triage level from an Allergic struct
 * @param allergic: Allergic struct
 */
enum Triage_Level get_symptoms_allergic(struct Allergic allergic) {
  enum Triage_Level triage_level = Green;

  bool red = allergic.swelling == AS_yes_stridor ||
             allergic.short_breath == ASB_Severe_rd;

  bool orange = allergic.swelling == AS_yes_mush ||
                allergic.short_breath == ASB_rd ||
                allergic.prev_anaphyl_shock || allergic.itchy_throat ||
                allergic.urticaria == AU_universal;

  bool yellow = allergic.urticaria == AU_pronounced;

  if (red) {
    triage_level = Red;
  } else if (orange) {
    triage_level = Orange;
  } else if (yellow) {
    triage_level = Yellow;
  } else {
    triage_level = Green;
  }

  return triage_level;
}

// ################################ CONTROLLER ################################

/*
 * returns Allergic struct from user input
 */
struct Allergic *input_allergic_symptom() {

  struct Allergic *allergic =
      (struct Allergic *)malloc(sizeof(struct Allergic));

  char choice;
  clear_screen();
  input_char(&choice,
             "Does the patient have allergic swelling? Yes_(S)tridor, "
             "Yes_(M)ush, (N)one",
             "SsMmNn");

  switch (choice) {
  case 'S':
  case 's':
    allergic->swelling = AS_yes_stridor;
    break;
  case 'M':
  case 'm':
    allergic->swelling = AS_yes_mush;
    break;
  case 'N':
  case 'n':
    allergic->swelling = AS_none;
    break;
  }

  clear_screen();
  input_char(&choice,
             "Does the patient have shortness of breath? "
             "(S)evere_rest_dyspnea, (R)est_dyspnea, (N)one",
             "SsRrNn");

  switch (choice) {
  case 'S':
  case 's':
    allergic->short_breath = ASB_Severe_rd;
    break;
  case 'R':
  case 'r':
    allergic->short_breath = ASB_rd;
    break;
  case 'N':
  case 'n':
    allergic->short_breath = ASB_none;
    break;
  }

  clear_screen();
  input_char(&choice,
             "Does the patient have previous anaphylactic shock? (Y)es, (N)o",
             "YyNn");

  switch (choice) {
  case 'Y':
  case 'y':
    allergic->prev_anaphyl_shock = true;
    break;
  case 'N':
  case 'n':
    allergic->prev_anaphyl_shock = false;
    break;
  }

  clear_screen();
  input_char(&choice, "Does the patient have an itchy throat? (Y)es, (N)o",
             "YyNn");

  switch (choice) {
  case 'Y':
  case 'y':
    allergic->itchy_throat = true;
    break;
  case 'N':
  case 'n':
    allergic->itchy_throat = false;
    break;
  }

  clear_screen();
  input_char(&choice,
             "Does the patient have urticaria? (U)niversal, (P)ronounced, "
             "(L)ocal, (N)one)",
             "UuPpLlNn");

  switch (choice) {
  case 'U':
  case 'u':
    allergic->urticaria = AU_universal;
    break;
  case 'P':
  case 'p':
    allergic->urticaria = AU_pronounced;
    break;
  case 'L':
  case 'l':
    allergic->urticaria = AU_local;
    break;
  case 'N':
  case 'n':
    allergic->urticaria = AU_none;
    break;
  }
  return allergic;
}
