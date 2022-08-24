#include <unistd.h>
#include <stdlib.h>
typedef struct status_events {
    int event;
    int module;
    int new_status;
    char[11] change_date;
    char[9] change_time;
} status_events;

int delete_from_events(FILE *db, int id);
status_events *select_from_events(FILE *db, int id);
int update_events(FILE *db, int id, status_events *entity);
int insert_into_events(FILE *db, status_events *entity);
void print_event(temp);
void print_all_events(file, amount);
