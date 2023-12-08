#include "vitals.h"
#include "gui.h"

enum Triage_Level get_vital_triage(struct Vitals vitals) {
  enum Triage_Level triage_level = Green;

  bool red = vitals.airway == Blocked || vitals.airway == Inspiratory_stridor ||
             (vitals.oxygen_saturation < 90 && vitals.with_oxygen) ||
             (vitals.oxygen_saturation < 80 && !vitals.with_oxygen) ||
             (vitals.oxygen_saturation < 85 && vitals.with_oxygen &&
              vitals.with_kol) ||
             (vitals.oxygen_saturation < 75 && !vitals.with_oxygen &&
              vitals.with_kol) ||
             vitals.respiration_frequency > 35 ||
             vitals.respiration_frequency < 8 || vitals.pulse > 140 ||
             vitals.systolic_blood_pressure < 80 ||
             vitals.glasgow_coma_scale <= 8 || vitals.temperature_celcius < 32;

  bool orange =
      (vitals.oxygen_saturation < 95 && vitals.with_oxygen) ||
      (vitals.oxygen_saturation < 90 && !vitals.with_oxygen) ||
      (vitals.oxygen_saturation < 90 && vitals.with_oxygen &&
       vitals.with_kol) ||
      (vitals.oxygen_saturation < 85 && !vitals.with_oxygen &&
       vitals.with_kol) ||
      vitals.respiration_frequency > 30 || vitals.pulse > 120 ||
      vitals.pulse < 40 || vitals.systolic_blood_pressure < 90 ||
      vitals.glasgow_coma_scale <= 13 && vitals.glasgow_coma_scale >= 9 ||
      vitals.temperature_celcius >= 32 && vitals.temperature_celcius <= 34 ||
      vitals.temperature_celcius > 40;

  bool yellow = (vitals.oxygen_saturation < 95 && !vitals.with_oxygen) ||
                (vitals.oxygen_saturation < 90 && !vitals.with_oxygen &&
                 vitals.with_kol) ||
                vitals.respiration_frequency > 25 || vitals.pulse > 110 ||
                vitals.pulse < 50 || vitals.glasgow_coma_scale == 14 ||
                vitals.temperature_celcius > 38;

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

void input_vitals(struct Vitals *vitals) {

  char choice;

  input_char(&choice,
             "Is the airway: (B)locked (F)ree or (I)nspiratory Stridor?",
             "BbFfIi");

  switch (choice) {
  case 'B':
  case 'b':
    vitals->airway = Blocked;
    break;
  case 'F':
  case 'f':
    vitals->airway = Free;
    break;
  case 'I':
  case 'i':
    vitals->airway = Inspiratory_stridor;
    break;
  }

  // Get patient_vitals Kol
  input_char(&choice, "Is the patient with kol? (Y)es  (N)o", "YyNn");
  switch (choice) {
  case 'Y':
  case 'y':
    vitals->with_kol = true;
    break;
  case 'N':
  case 'n':
    vitals->with_kol = false;
    break;
  }

  input_int("Input Oxygen Saturation", &vitals->oxygen_saturation);

  // Get patient_vitals Airway
  input_char(&choice, "Is the patient with oxygen? (Y)es  (N)o", "YyNn");
  switch (choice) {
  case 'Y':
  case 'y':
    vitals->with_oxygen = true;
    break;
  case 'N':
  case 'n':
    vitals->with_oxygen = false;
    break;
  }

  input_int("Input Respiration Frequency", &vitals->respiration_frequency);

  input_int("Input Pulse", &vitals->pulse);

  input_int("Input Systolic Blood Pressure", &vitals->systolic_blood_pressure);

  input_int("Input Glasgow Coma Scale Number", &vitals->glasgow_coma_scale);

  input_double("Input Temperature Celcius", &vitals->temperature_celcius);
}
