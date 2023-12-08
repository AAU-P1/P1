//
// Created by Mathias Birkholm on 07/12/2023.
//
#include "19_gastrointestinal_bleeding.h"

enum Triage_Level get_symptomps_gastrointestinal_triage(struct gastrointestinal gastrointestinal){
    enum Triage_Level triage_level = Green;

    bool red = gastrointestinal.vomitting_blood == ongoing;

    bool orange = gastrointestinal.vomitting_blood == freqwently;

    bool yellow = gastrointestinal.vomitting_blood == singulary;

    bool green = gastrointestinal.vomitting_blood == none ;


}