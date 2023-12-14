#include "001_abstinence.h"
#include "../input.h"
#include <stdlib.h>

// ################################## MODEL ##################################

/*
 * return the triage level from an Abstinence struct
 * @param asbstinence: Abstinence struct
 */
TriageLevel getSymptomAbstinenceTriage(Abstinence abstinence) {
  TriageLevel triageLevel = T_GREEN;

  bool red = abstinence.cramps == AC_ONGOING;

  bool orange = abstinence.cramps == AC_NOW_DISCONTINUED ||
                abstinence.restless == AR_YES_W_CONF_OR_HALUC;

  bool yellow = abstinence.cramps == AC_BY_PREVIOUS_CONTACT ||
                abstinence.restless == AR_YES;

  bool green = abstinence.restless == AR_EASY_OR_NONE;

  if (red) {
    triageLevel = T_RED;
  } else if (orange) {
    triageLevel = T_ORANGE;
  } else if (yellow) {
    triageLevel = T_YELLOW;
  } else if (green) {
    triageLevel = T_GREEN;
  }

  return triageLevel;
}

// ############################ CONTROLLER/VIEW #############################

/*
 * returns Abstinence struct from user input
 */
Abstinence *inputSymptomAbstinence() {

  Abstinence *abstinence = (Abstinence *)malloc(sizeof(Abstinence));
  if (abstinence == NULL) {
    exit(EXIT_FAILURE);
  }

  char c;
  clearScreen();
  inputChar(&c,
            "Does the patient have abstinent cramps? (O)ngoing, "
            "Now_(D)iscontinued (B)y_Previous_Contact (N)one",
            "OoDdBbNn");

  switch (c) {
  case 'O':
  case 'o':
    abstinence->cramps = AC_ONGOING;
    break;
  case 'D':
  case 'd':
    abstinence->cramps = AC_NOW_DISCONTINUED;
    break;
  case 'B':
  case 'b':
    abstinence->cramps = AC_BY_PREVIOUS_CONTACT;
    break;
  case 'N':
  case 'n':
    abstinence->cramps = AC_NONE;
    break;
  }

  clearScreen();
  inputChar(&c,
            "Is the patient restless from abstinence "
            "Yes_(W)ith_Confusion_or_Halucination, (Y)es, (E)asy_or_None ",
            "WwYyEe");

  switch (c) {
  case 'W':
  case 'w':
    abstinence->restless = AR_YES_W_CONF_OR_HALUC;
    break;
  case 'Y':
  case 'y':
    abstinence->restless = AR_YES;
    break;
  case 'E':
  case 'e':
    abstinence->restless = AR_EASY_OR_NONE;
    break;
  }
  return abstinence;
}
