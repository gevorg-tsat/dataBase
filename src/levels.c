#include "levels.h"

int delete_from_levels(FILE *db, int id) {
    long int n = ftell(db)/(sizeof(level));
    long int count = 0;
    fseek(db, 0, SEEK_SET);
    for (long int i = 0; i < n;) {
        level door;
        fseek(db, i*sizeof(level), SEEK_SET);
        fread(&door, sizeof(level), 1, db);
        if (door.level_number == id) {
            for (long j = i; j < n - 1; j++) {
                level door_temp;
                fseek(db, (j+1)*sizeof(level), SEEK_SET);
                fread(&door_temp, sizeof(level), 1, db);
                fseek(db, j*sizeof(level), SEEK_SET);
                fwrite(&door_temp, sizeof(level), 1, db);
            }
            count++;
        }
        else i++;
    }
    fseek(db, 0, SEEK_SET);
    ftruncate((fileno(db)), (n - count) * sizeof(level));
}

level *select_from_levels(FILE *db, int id) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(level);
    level *temp = malloc(sizeof(level));
    for (int i = 0; i < size; i++) {
        fseek(db, i * sizeof(level), SEEK_SET);
        fread(&temp, sizeof(level), 1, db);
        if (temp->level_number == id) {
            return temp;
        }
    }
    return NULL;
}

int update_level(FILE *db, int id, level *entity) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(level);
    for (long int i = 0; i < n; i++) {
        level temp;
        fseek(db, i*sizeof(level), SEEK_SET);
        fread(&temp, sizeof(level), 1, db);
        if (temp.id == id) {
            fseek(db, i*sizeof(level), SEEK_SET);
            fwrite(entity, sizeof(level), 1, db);
            return 0;
        }
    }
    return 1;
}

int insert_into_levels(FILE *db, level *entity) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(level);
    fseek(db, size*sizeof(level), SEEK_SET);
    fwrite(entity, sizeof(level), 1, db);
    return 0;
}
