#include "symptoms.h"

enum Gender { Male, Female };

struct Patient {
  char name[100];
  int age;
  enum Gender gender;
  struct Vitals *vitals;
  struct symptom_node *symptoms_head;
};

enum Triage_Level get_triage(struct Patient patient);
