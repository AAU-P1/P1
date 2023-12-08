#include "../symptoms/001_abstinence.h"
#include "gui.h"
#include <stdlib.h>

struct Abstinence *input_abstinence_symptom() {

  struct Abstinence *abstinence =
      (struct Abstinence *)malloc(sizeof(struct Abstinence));

  char choice;
  input_char(&choice,
             "Does the patient have abstinent cramps? (O)ngoing, "
             "Now_(D)iscontinued (B)y_Previous_Contact (N)one",
             "OoDdBbNn");

  switch (choice) {
  case 'O':
  case 'o':
    abstinence->cramps = AC_ongoing;
    break;
  case 'D':
  case 'd':
    abstinence->cramps = AC_now_discontinued;
    break;
  case 'B':
  case 'b':
    abstinence->cramps = AC_by_previous_contact;
    break;
  case 'N':
  case 'n':
    abstinence->cramps = AC_none;
    break;
  }

  input_char(&choice,
             "Is the patient restless from abstinence "
             "Yes_(W)ith_Confusion_or_Halucination, (Y)es, (E)asy_or_None ",
             "WwYyEe");

  switch (choice) {
  case 'W':
  case 'w':
    abstinence->restless = AC_yes_w_conf_or_haluc;
    break;
  case 'Y':
  case 'y':
    abstinence->restless = AC_yes;
    break;
  case 'E':
  case 'e':
    abstinence->restless = AC_easy_or_none;
    break;
  }

  return abstinence;
}
