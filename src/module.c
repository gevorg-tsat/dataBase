#include "module.h"


int delete_from_modules(FILE *db, int id) {
    long int n = ftell(db)/(sizeof(module));
    long int count = 0;
    fseek(db, 0, SEEK_SET);
    for (long int i = 0; i < n;) {
        module door;
        fseek(db, i*sizeof(module), SEEK_SET);
        fread(&door, sizeof(module), 1, db);
        if ((door.id == id) {
            for (long j = i; j < n - 1; j++) {
                module door_temp;
                fseek(db, (j+1)*sizeof(module), SEEK_SET);
                fread(&door_temp, sizeof(module), 1, db);
                fseek(db, j*sizeof(module), SEEK_SET);
                fwrite(&door_temp, sizeof(module), 1, db);
            }
            count++;
            continue;
        }
        i++;
    }
    fseek(db, 0, SEEK_SET);
    ftruncate((fileno(db)), (n - count) * sizeof(module));
}
module *select_from_modules(FILE *db, int id) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(module);
    module *temp = malloc(sizeof(module));
    for (int i = 0; i < size; i++) {
        fseek(db, i * sizeof(module), SEEK_SET);
        fread(temp, sizeof(module), 1, db);
        if (temp->id == id) {
            return temp;
        }
    }
    return NULL;
}

int update_module(FILE *db, int id, module *entity) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(module);
    for (long int i = 0; i < n; i++) {
        module temp;
        fseek(db, i*sizeof(module), SEEK_SET);
        fread(&temp, sizeof(module), 1, db);
        if (temp.id == id) {
            fseek(db, i*sizeof(module), SEEK_SET);
            fwrite(entity, sizeof(module), 1, db);
            return 0;
        }
    }
    return 1;
}

int insert_into_module(FILE *db, module *entity) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(module);
    fseek(db, size*sizeof(module), SEEK_SET);
    fwrite(entity, sizeof(module), 1, db);
}

void print_module(module data) {
    printf("%d ", data.id);
    printf("%s ",data.name);
    printf("%d ", data.level_number);
    printf("%d ", data.cell);
    printf("%d", data.del);
}

void print_all_module(FILE *file, int amount) {

}

int input_module(module *data) {

}