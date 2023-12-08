//
// Created by Mathias Birkholm on 07/12/2023.
//

#ifndef SYM_GASTROINTESTINAL
#define SYM_GASTROINTESTINAL

#include "../triage_level.h"
#include <stdbool.h>

enum Gastrointestinal_how_often_blood_vomit {GHOBV_ongoing, GHOBV_frequent, GHOBV_individual, GHOBV_none};
enum Gastrointestinal_bleeding_pr_rectum {GBPR_ongoing, GBPR_frequent, GBPR_individual, GBPR_none};
enum Gastrointestinal_risk_patient {GRP_antikoagulation, GRP_former_Esophageal_varices, GRP_yes, GRP_none};
enum Gastrointestinal_malena {GM_ongoing, GM_frequent, GM_individual, GM_none};

struct Gastrointestinal{
    enum Gastrointestinal_how_often_blood_vomit how_often;
    enum Gastrointestinal_bleeding_pr_rectum bleeding_pr_rectum;
    enum Gastrointestinal_risk_patient risk_patient;
    enum Gastrointestinal_malena malena;
    bool Person_over_12;
    int vital_sings;
};

enum Triage_Level get_symptoms_gastrointestinal_triage(struct Gastrointestinal gastrointestinal);

#endif
