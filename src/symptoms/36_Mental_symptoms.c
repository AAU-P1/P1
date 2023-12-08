#include "36_Mental_symptoms.h"

enum Triage_Level get_symptoms_mental_triage(struct Mental mental) {
    enum Triage_Level triage_level = Green;

bool orange = mental.violentBehaviour == VB_lack_of_impulse ||
        mental.suicidal == S_ongoing_suicide_attempt ||
        mental.anxiety == ANX_restless_or_tension ||
        mental.delirium == DE_hallucinations_and_consciousness_influence ||
        mental.need_urgent_help == true;

bool yellow = mental.violentBehaviour == VB_cooperative ||
        mental.suicidal == S_suicidal_thoughts ||
        mental.anxiety == ANX_cooperative ||
        mental.delirium == DE_hallucinations_aware_of_data ||
        mental.known_diagnosis == true;


if(orange){
    triage_level = Orange;
}
else if(yellow){
    triage_level = Yellow;
}else{
    triage_level = Green;
}
return triage_level;
}