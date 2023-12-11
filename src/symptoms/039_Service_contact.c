#include "039_Service_contact.h"

enum Triage_Level get_symptoms_mental_triage(struct Service service) {
  enum Triage_Level triage_level = Green;

  bool blue = service.social_problems == true ||
              service.authority_statement == true ||
              service.vaccination == true || service.prescription == true;

  if (blue) {
    triage_level = Blue;
  }
  return triage_level;
}
