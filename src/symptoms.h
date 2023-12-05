struct symptom_node {
  void *data;
  struct symptom_node *next;
};

enum Triage_Level { Red, Orange, Yellow, Green, Blue };

enum Triage_Level get_symptoms_triage(struct symptom_node);
