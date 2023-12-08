#ifndef SYM_CATHETER_STOMA_OR_FEEDING_TUBE_PROBLEMS
#define SYM_CATHETER_STOMA_OR_FEEDING_TUBE_PROBLEMS
#include "../triage_level.h"
#include <stdbool.h>

enum Catheter_stoma_or_feeding_tube_problems_reinsertion_of_catheter_or_tube { CSOFTPROCOT_PEG_feeding_tube_or_top_catheter, CSOFTPROCOT_fever_infection_or_occlusion, CSOFTPROCOT_no_fever_infection_or_occlusion } ;
enum Catheter_stoma_or_feeding_tube_problems_stoma_complications { CSOFTPSTC_necrosis_or_infection, CSOFTPSTC_prolapse_or_stenosis_or_retraction } ;
struct Catheter_stoma_or_feeding_tube_problems {
    bool disposable_catheter;
    enum Catheter_stoma_or_feeding_tube_problems_reinsertion_of_catheter_or_tube reinsertion_of_catheter_or_tube;
    enum Catheter_stoma_or_feeding_tube_problems_stoma_complications stoma_complications;
};

enum Triage_Level get_symptoms_Catheter_stoma_or_feeding_tube_problems_triage(struct Catheter_stoma_or_feeding_tube_problems catheter_stoma_or_feeding_tube_problems);

#endif