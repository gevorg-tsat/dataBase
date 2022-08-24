#include "status_events.h"

int delete_from_events(FILE *db, int id) {
    fseek(db, 0, SEEK_END);
    long int n = ftell(db)/(sizeof(status_events);
    long int count = 0;
    fseek(db, 0, SEEK_SET);
    for (long int i = 0; i < n;) {
        status_events door;
        fseek(db, i*sizeof(status_events, SEEK_SET);
        fread(&door, sizeof(status_events, 1, db);
        if (door.event == id) {
            for (long j = i; j < n - 1; j++) {
                status_events door_temp;
                fseek(db, (j+1)*sizeof(status_events, SEEK_SET);
                fread(&door_temp, sizeof(status_events, 1, db);
                fseek(db, j*sizeof(status_events, SEEK_SET);
                fwrite(&door_temp, sizeof(status_events, 1, db);
            }
            count++;
        }
        else i++;
    }
    fseek(db, 0, SEEK_SET);
    ftruncate((fileno(db)), (n - count) * sizeof(status_events);
}

status_events *select_from_events(FILE *db, int id) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(status_events);
    status_events *temp = malloc(sizeof(status_events));
    for (int i = 0; i < size; i++) {
        fseek(db, i * sizeof(status_events), SEEK_SET);
        fread(&temp, sizeof(status_events), 1, db);
        if (temp->event == id) {
            return temp;
        }
    }
    return NULL;
}
int update_events(FILE *db, int id, status_events *entity) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(status_events);
    for (long int i = 0; i < n; i++) {
        status_events temp;
        fseek(db, i*sizeof(status_events), SEEK_SET);
        fread(&temp, sizeof(status_events), 1, db);
        if (temp.id == id) {
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
}
