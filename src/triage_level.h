#ifndef TRIAGE_LEVEL_H
#define TRIAGE_LEVEL_H

enum Triage_Level { Red, Orange, Yellow, Green, Blue };

enum Gender { Male, Female };

struct Patient {
  char name[100];
  int age;
  int id;
  enum Gender gender;
  struct Vitals *vitals;
  struct symptom_node *symptoms_head;
};

enum Triage_Level get_triage(struct Patient patient);
#endif
