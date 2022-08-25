#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct status_events {
    int event;
    int module;
    int new_status;
    char change_date[11];
    char change_time[9];
} status_events;

int delete_from_events(FILE *db, int id);
status_events *select_from_events(FILE *db, int id);
int update_events(FILE *db, int id, status_events *entity);
int insert_into_events(FILE *db, status_events *entity);
void print_event(status_events temp);
void print_all_events(FILE *db, int amount);
int input_event(status_events *event);