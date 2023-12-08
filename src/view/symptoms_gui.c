#include "symptoms_gui.h"
#include "gui.h"
void input_symptoms(struct symptom_node *sn) {

  int choice;

  input_int_with_range("Please choose one of the following:\n(1) or ...",
                       &choice, 1, 1);
  switch (choice) {
  case 1:
    sn->symptom_id = choice;
    sn->data = input_abstinence_symptom();
    break;
  }
}
