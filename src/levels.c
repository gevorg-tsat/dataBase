#include "levels.h"

int delete_from_levels(FILE *db, int id) {
    fseek(db, 0, SEEK_END);
    long int n = ftell(db)/(sizeof(level));
    long int count = 0;
    fseek(db, 0, SEEK_SET);
    for (long int i = 0; i < n;) {
        level door;
        fseek(db, i*sizeof(level), SEEK_SET);
        fread(&door, sizeof(level), 1, db);
        if (door.level_number == id) {
            for (long j = i; j < n; j++) {
                level door_temp;
                fseek(db, (j+1)*sizeof(level), SEEK_SET);
                fread(&door_temp, sizeof(level), 1, db);
                fseek(db, j*sizeof(level), SEEK_SET);
                fwrite(&door_temp, sizeof(level), 1, db);
            }
            count++;
        } else {
            i++;
        }
    }
    fseek(db, 0, SEEK_SET);
    ftruncate((fileno(db)), (n - count) * sizeof(level));
    if (count == 0)
        return 1;
    return 0;
}

level *select_from_levels(FILE *db, int id) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(level);
    level *temp = malloc(sizeof(level));
    for (int i = 0; i < size; i++) {
        fseek(db, i * sizeof(level), SEEK_SET);
        fread(temp, sizeof(level), 1, db);
        if (temp->level_number == id) {
            return temp;
        }
    }
    free(temp);
    return NULL;
}

int update_level(FILE *db, int id, level *entity) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(level);
    for (long int i = 0; i < size; i++) {
        level temp;
        fseek(db, i*sizeof(level), SEEK_SET);
        fread(&temp, sizeof(level), 1, db);
        if (temp.level_number == id) {
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

void print_level(level temp) {
    printf("%d %d %d\n", temp.level_number, temp.cell_amount, temp.safety_flag);
}
void print_all_levels(FILE *db, int amount) {
    fseek(db, 0, SEEK_END);
    level temp;
    long int size = ftell(db) / sizeof(level);
    if (amount == -1)
        amount = size;
    for (int i = 0; i < size && i < amount; i++) {
        fseek(db, i * sizeof(level), SEEK_SET);
        fread(&temp, sizeof(level), 1, db);
        print_level(temp);
    }
}

int input_level(level *data) {
    printf("input data about new level:\n");
    printf("level amount of cells safety flag\n");
    if (scanf("%d%d%d", &(data->level_number), &(data->cell_amount), &(data->safety_flag)) != 3)
        return 1;
    FILE *file = fopen("../materials/master_levels.db", "rb");
    level *temp_lvl = select_from_levels(file, data -> level_number);
    if (temp_lvl != NULL) {
        free(temp_lvl);
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0;
}
