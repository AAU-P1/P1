#include "019_gastrointestinal.h"

enum Triage_Level get_symptoms_gastrointestinal_symptoms(
    struct Gastrointestinal gastrointestinal) {
  enum Triage_Level triage_level = Green;

  bool red = gastrointestinal.how_often == GHOBV_ongoing;

  bool orange = gastrointestinal.how_often == ;

  bool yellow = ;

  bool green = ;
}
