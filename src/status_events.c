#include "status_events.h"

int delete_from_events(FILE *db, int id) {
    fseek(db, 0, SEEK_END);
    long int n = ftell(db)/(sizeof(status_events));
    long int count = 0;
    fseek(db, 0, SEEK_SET);
    for (long int i = 0; i < n;) {
        status_events door;
        fseek(db, i*sizeof(status_events), SEEK_SET);
        fread(&door, sizeof(status_events), 1, db);
        if (door.event == id) {
            for (long j = i; j < n; j++) {
                status_events door_temp;
                fseek(db, (j+1)*sizeof(status_events), SEEK_SET);
                fread(&door_temp, sizeof(status_events), 1, db);
                fseek(db, j*sizeof(status_events), SEEK_SET);
                fwrite(&door_temp, sizeof(status_events), 1, db);
            }
            count++;
        } else {
            i++;
        }
    }
    fseek(db, 0, SEEK_SET);
    ftruncate((fileno(db)), (n - count) * sizeof(status_events));
    if (count == 0)
        return 1;
    return 0;
}

status_events *select_from_events(FILE *db, int id) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(status_events);
    status_events *temp = malloc(sizeof(status_events));
    for (int i = 0; i < size; i++) {
        fseek(db, i * sizeof(status_events), SEEK_SET);
        fread(temp, sizeof(status_events), 1, db);
        if (temp->event == id) {
            return temp;
        }
    }
    free(temp);
    return NULL;
}
int update_events(FILE *db, int id, status_events *entity) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(status_events);
    for (long int i = 0; i < size; i++) {
        status_events temp;
        fseek(db, i*sizeof(status_events), SEEK_SET);
        fread(&temp, sizeof(status_events), 1, db);
        if (temp.event == id) {
            fseek(db, i*sizeof(status_events), SEEK_SET);
            fwrite(entity, sizeof(status_events), 1, db);
            return 0;
        }
    }
    return 1;
}

int insert_into_events(FILE *db, status_events *entity) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(status_events);
    fseek(db, size*sizeof(status_events), SEEK_SET);
    fwrite(entity, sizeof(status_events), 1, db);
    return 0;
}

void print_event(status_events temp) {
    printf("%d %d %d %s %s\n", temp.event, temp.module, temp.new_status, temp.change_date, temp.change_time);
}
void print_all_events(FILE *db, int amount) {
    fseek(db, 0, SEEK_END);
    status_events temp;
    long int size = ftell(db) / sizeof(status_events);
    if (amount == -1)
        amount = size;
    for (int i = 0; i < size && i < amount; i++) {
        fseek(db, i * sizeof(status_events), SEEK_SET);
        fread(&temp, sizeof(status_events), 1, db);
        print_event(temp);
    }
}
int input_event(status_events *event) {
    printf("input data about new event:\n");
    printf("event_id module_id new_status date_of_change time_of_change\n");
    if (scanf("%d %d %d", &(event->event), &(event->module), &(event->new_status)) != 3)
        return 1;
    scanf("%11s %9s", event->change_date, event->change_time);
    FILE *file = fopen("../materials/master_modules.db", "rb");
    module *temp = select_from_module(file, event -> module);
    if (temp == NULL)
        return 1;
    free(temp);
    fclose(file);
    file = fopen("../materials/master_status_events.db", "rb");
    status_events *temp1 = select_from_events(file, event -> event);
    if (temp1 != NULL) {
        free(temp1);
        return 1;
    }
    fclose(file);
    return 0;
}
