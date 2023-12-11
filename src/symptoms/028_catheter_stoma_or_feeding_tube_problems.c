#include "028_catheter_stoma_or_feeding_tube_problems.h"

enum Triage_Level get_symptoms_Catheter_stoma_or_feeding_tube_problems_triage(
    struct Catheter_stoma_or_feeding_tube_problems
        catheter_stoma_or_feeding_tube_problems) {
  enum Triage_Level triage_level = Blue;

  bool yellow =
      catheter_stoma_or_feeding_tube_problems.reinsertion_of_catheter_or_tube ==
          CSOFTPROCOT_PEG_feeding_tube_or_top_catheter ||
      catheter_stoma_or_feeding_tube_problems.stoma_complications ==
          CSOFTPSTC_necrosis_or_infection;

  bool green =
      catheter_stoma_or_feeding_tube_problems.reinsertion_of_catheter_or_tube ==
          CSOFTPROCOT_fever_infection_or_occlusion ||
      catheter_stoma_or_feeding_tube_problems.stoma_complications ==
          CSOFTPSTC_prolapse_or_stenosis_or_retraction;

  bool blue =
      catheter_stoma_or_feeding_tube_problems.reinsertion_of_catheter_or_tube ==
          CSOFTPROCOT_no_fever_infection_or_occlusion ||
      catheter_stoma_or_feeding_tube_problems.disposable_catheter == true;

  if (yellow) {
    triage_level = Yellow;
  } else if (green) {
    triage_level = Green;
  } else if (blue) {
    triage_level = Blue;
  }

  return triage_level;
}
