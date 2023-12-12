#include "file.h"
#include "patient.h"
#include <stdio.h>
#include <stdlib.h>

void load_patient_queue_from_file(struct patient_queue *pq) {
  FILE *file;

  file = fopen("STATE", "r");

  if (file == NULL) {
    return;
  }

  char line[128];

  while (fgets(line, sizeof(line), file)) {
    /* note that fgets don't strip the terminating \n, checking its
       presence would allow to handle lines longer that sizeof(line) */
    struct Patient *p = (struct Patient *)malloc(sizeof(struct Patient));

    sscanf(line, "%99[^,],%d,%d,%d,%d\n", p->name, &p->age, &p->id,
           &p->triage_level, &p->gender);

    add_patient_to_queue(pq, p, p->id);
    if (p->id >= pq->current_id) {
      pq->current_id = p->id + 1;
    }
  }
}
void save_patient_queue_to_file(struct patient_queue *pq) {
  FILE *file;

  // Open a file in writing mode
  file = fopen("STATE", "w");

  save_patient_list_to_file(pq->red_head, file);
  save_patient_list_to_file(pq->orange_head, file);
  save_patient_list_to_file(pq->yellow_head, file);
  save_patient_list_to_file(pq->green_head, file);
  save_patient_list_to_file(pq->blue_head, file);

  fclose(file);
}

void save_patient_list_to_file(struct patient_node *sl, FILE *file) {

  struct patient_node *cur;

  if (sl == NULL) {
    return;
  }
  cur = sl;

  do {
    struct Patient *patient = (struct Patient *)cur->data;
    save_patient_to_file(patient, file);
    cur = cur->next;
  } while (cur != NULL);
}

void save_patient_to_file(struct Patient *p, FILE *file) {

  fprintf(file, "%s,%d,%d,%d,%d\n", p->name, p->age, p->id, p->triage_level,
          p->gender);
}
