#include "vitals_gui.h"
#include "gui.h"

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
