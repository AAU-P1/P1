
#include "../triage_level.h"
#include <stdbool.h>

struct BloodPressure {
  bool cerebral_impact;
  int systolic;
  int diastolic;
  bool dyspnea;
  int age;
  bool is_pregnant;
};

enum Triage_Level
get_symptoms_blood_pressure_triage(struct BloodPressure blood_pressure);
enum Triage_Level
get_symptoms_blood_pressure_triage(struct BloodPressure blood_pressure) {
  enum Triage_Level triage_level = Blue;

  bool red = blood_pressure.cerebral_impact;

  bool orange = false;
  if (blood_pressure.systolic > 240 ||
      (blood_pressure.systolic >= 220 && blood_pressure.systolic <= 240 &&
       !blood_pressure.is_pregnant && blood_pressure.age > 8) ||
      (blood_pressure.systolic > 160 && blood_pressure.systolic <= 220 &&
       !blood_pressure.is_pregnant && blood_pressure.age > 8) ||
      (blood_pressure.systolic > 140 && blood_pressure.systolic <= 160 &&
       !blood_pressure.is_pregnant && blood_pressure.age > 8) ||
      (blood_pressure.systolic > 115 && blood_pressure.systolic <= 140 &&
       !blood_pressure.is_pregnant && blood_pressure.age > 8) ||
      (blood_pressure.systolic > 110 && blood_pressure.systolic <= 115 &&
       !blood_pressure.is_pregnant && blood_pressure.age > 8) ||
      (blood_pressure.systolic > 80 && blood_pressure.systolic <= 110 &&
       !blood_pressure.is_pregnant && blood_pressure.age > 8) ||
      (blood_pressure.systolic > 160 && blood_pressure.systolic <= 220 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 8 &&
       blood_pressure.age > 5) ||
      (blood_pressure.systolic > 140 && blood_pressure.systolic <= 160 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 8 &&
       blood_pressure.age > 5) ||
      (blood_pressure.systolic > 115 && blood_pressure.systolic <= 140 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 8 &&
       blood_pressure.age > 5) ||
      (blood_pressure.systolic > 110 && blood_pressure.systolic <= 115 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 8 &&
       blood_pressure.age > 5) ||
      (blood_pressure.systolic > 80 && blood_pressure.systolic <= 110 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 8 &&
       blood_pressure.age > 5) ||
      (blood_pressure.systolic > 140 && blood_pressure.systolic <= 160 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 5 &&
       blood_pressure.age > 1) ||
      (blood_pressure.systolic > 115 && blood_pressure.systolic <= 140 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 5 &&
       blood_pressure.age > 1) ||
      (blood_pressure.systolic > 110 && blood_pressure.systolic <= 115 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 5 &&
       blood_pressure.age > 1) ||
      (blood_pressure.systolic > 80 && blood_pressure.systolic <= 110 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 5 &&
       blood_pressure.age > 1) ||
      (blood_pressure.systolic > 80 && blood_pressure.systolic <= 110 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 1) ||
      (blood_pressure.systolic > 160 && blood_pressure.systolic <= 220 &&
       blood_pressure.is_pregnant) ||
      (blood_pressure.systolic > 140 && blood_pressure.systolic <= 160 &&
       blood_pressure.is_pregnant) ||
      (blood_pressure.systolic > 115 && blood_pressure.systolic <= 140 &&
       blood_pressure.is_pregnant) ||
      (blood_pressure.systolic > 110 && blood_pressure.systolic <= 115 &&
       blood_pressure.is_pregnant) ||
      (blood_pressure.systolic > 80 && blood_pressure.systolic <= 110 &&
       blood_pressure.is_pregnant) ||
      (blood_pressure.diastolic > 130) ||
      (blood_pressure.diastolic >= 120 && blood_pressure.diastolic <= 130 &&
       !blood_pressure.is_pregnant && blood_pressure.age > 8) ||
      (blood_pressure.diastolic > 110 && blood_pressure.diastolic < 120 &&
       !blood_pressure.is_pregnant && blood_pressure.age > 8) ||
      (blood_pressure.diastolic > 90 && blood_pressure.diastolic <= 110 &&
       !blood_pressure.is_pregnant && blood_pressure.age > 8) ||
      (blood_pressure.diastolic > 110 && blood_pressure.diastolic <= 120 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 8 &&
       blood_pressure.age > 5) ||
      (blood_pressure.diastolic > 90 && blood_pressure.diastolic <= 110 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 8 &&
       blood_pressure.age > 5) ||
      (blood_pressure.diastolic > 110 && blood_pressure.diastolic <= 120 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 5 &&
       blood_pressure.age > 1) ||
      (blood_pressure.diastolic > 90 && blood_pressure.diastolic <= 110 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 5 &&
       blood_pressure.age > 1) ||
      (blood_pressure.diastolic > 80 && blood_pressure.diastolic <= 90 &&
       !blood_pressure.is_pregnant && blood_pressure.age <= 5 &&
       blood_pressure.age > 1) ||
      (blood_pressure.is_pregnant && blood_pressure.diastolic <= 110 &&
       blood_pressure.diastolic > 90)) {
    orange = true;
  }

  bool yellow =
      (blood_pressure.systolic < 220 && blood_pressure.diastolic < 120);

  bool green = !red && !orange && !yellow;

  if (red) {
    triage_level = Red;
  } else if (orange) {
    triage_level = Orange;
  } else if (yellow) {
    triage_level = Yellow;
  } else if (green) {
    triage_level = Green;
  } else {
    triage_level = Blue;
  }

  return triage_level;
}
