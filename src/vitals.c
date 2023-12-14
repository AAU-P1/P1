#include "vitals.h"
#include "controller.h"
#include "triage_level.h"

// ################################## MODEL ##################################

TriageLevel getVitalTriage(Vitals vitals) {
  TriageLevel triageLevel = T_GREEN;

  bool red =
      vitals.airway == V_BLOCKED || vitals.airway == V_INSPIRATORY_STRIDOR ||
      (vitals.oxygenSaturation < 90 && vitals.withOxygen) ||
      (vitals.oxygenSaturation < 80 && !vitals.withOxygen) ||
      (vitals.oxygenSaturation < 85 && vitals.withOxygen && vitals.withKol) ||
      (vitals.oxygenSaturation < 75 && !vitals.withOxygen && vitals.withKol) ||
      vitals.respirationFrequency > 35 || vitals.respirationFrequency < 8 ||
      vitals.pulse > 140 || vitals.systolicBloodPressure < 80 ||
      vitals.glasgowComaScale <= 8 || vitals.temperatureCelcius < 32;

  bool orange =
      (vitals.oxygenSaturation < 95 && vitals.withOxygen) ||
      (vitals.oxygenSaturation < 90 && !vitals.withOxygen) ||
      (vitals.oxygenSaturation < 90 && vitals.withOxygen && vitals.withKol) ||
      (vitals.oxygenSaturation < 85 && !vitals.withOxygen && vitals.withKol) ||
      vitals.respirationFrequency > 30 || vitals.pulse > 120 ||
      vitals.pulse < 40 || vitals.systolicBloodPressure < 90 ||
      vitals.glasgowComaScale <= 13 && vitals.glasgowComaScale >= 9 ||
      vitals.temperatureCelcius >= 32 && vitals.temperatureCelcius <= 34 ||
      vitals.temperatureCelcius > 40;

  bool yellow =
      (vitals.oxygenSaturation < 95 && !vitals.withOxygen) ||
      (vitals.oxygenSaturation < 90 && !vitals.withOxygen && vitals.withKol) ||
      vitals.respirationFrequency > 25 || vitals.pulse > 110 ||
      vitals.pulse < 50 || vitals.glasgowComaScale == 14 ||
      vitals.temperatureCelcius > 38;

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

void inputVitals(Vitals *vitals) {
  char c;
  clearScreen();
  inputChar(&c, "Is the airway: (B)locked (F)ree or (I)nspiratory Stridor?",
            "BbFfIi");

  switch (c) {
  case 'B':
  case 'b':
    vitals->airway = V_BLOCKED;
    break;
  case 'F':
  case 'f':
    vitals->airway = V_FREE;
    break;
  case 'I':
  case 'i':
    vitals->airway = V_INSPIRATORY_STRIDOR;
    break;
  }

  // Get patient_vitals Kol
  clearScreen();
  inputChar(&c, "Is the patient with kol? (Y)es  (N)o", "YyNn");
  switch (c) {
  case 'Y':
  case 'y':
    vitals->withKol = true;
    break;
  case 'N':
  case 'n':
    vitals->withKol = false;
    break;
  }

  clearScreen();
  inputIntWithRange("Input Oxygen Saturation", &vitals->oxygenSaturation, 0,
                    100);

  // Get patient_vitals Airway
  clearScreen();
  inputChar(&c, "Is the patient with oxygen? (Y)es  (N)o", "YyNn");
  switch (c) {
  case 'Y':
  case 'y':
    vitals->withOxygen = true;
    break;
  case 'N':
  case 'n':
    vitals->withOxygen = false;
    break;
  }

  clearScreen();
  inputIntWithMin("Input Respiration Frequency", &vitals->respirationFrequency,
                  0);

  clearScreen();
  inputIntWithMin("Input Pulse", &vitals->pulse, 0);

  clearScreen();
  inputIntWithMin("Input Systolic Blood Pressure",
                  &vitals->systolicBloodPressure, 0);

  clearScreen();
  inputIntWithRange("Input Glasgow Coma Scale Number",
                    &vitals->glasgowComaScale, 3, 15);

  clearScreen();
  inputDouble("Input Temperature Celcius", &vitals->temperatureCelcius);
}
