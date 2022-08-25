#include "module.h"


int delete_from_modules(FILE *db, int id) {
    fseek(db, 0, SEEK_END);
    long int n = ftell(db)/(sizeof(module));
    long int count = 0;
    fseek(db, 0, SEEK_SET);
    for (long int i = 0; i < n;) {
        module door;
        fseek(db, i*sizeof(module), SEEK_SET);
        fread(&door, sizeof(module), 1, db);
        if (door.id == id) {
            for (long j = i; j < n; j++) {
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
    if (count == 0)
        return 1;
    return 0;
}
module *select_from_module(FILE *db, int id) {
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
    free(temp);
    return NULL;
}

int update_module(FILE *db, int id, module *entity) {
    fseek(db, 0, SEEK_END);
    long int size = ftell(db) / sizeof(module);
    for (long int i = 0; i < size; i++) {
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
    return 0;
}

void print_module(module data) {
    printf("%d ", data.id);
    printf("%s ", data.name);
    printf("%d ", data.level_number);
    printf("%d ", data.cell);
    printf("%d\n", data.del);
}

void print_all_module(FILE *db, int amount) {
    fseek(db, 0, SEEK_END);
    module temp;
    long int size = ftell(db) / sizeof(module);
    if (amount == -1)
        amount = size;
    for (int i = 0; i < size && i < amount; i++) {
        fseek(db, i * sizeof(module), SEEK_SET);
        fread(&temp, sizeof(module), 1, db);
        print_module(temp);
    }
}

int input_module(module *data) {
    printf("input data about new module:\n");
    printf("id name level cell delete_flag \n");
    if (scanf("%d", &(data->id)) !=1)
        return 1;
    scanf("%s", data->name);
    if (scanf("%d %d %d", &(data->level_number), &(data->cell), &(data->del)) != 3)
        return 1;
    FILE *file = fopen("../materials/master_modules.db", "rb");
    module *temp = select_from_module(file, data -> id);
    if (temp != NULL) {
        free(temp);
        fclose(file);
        return 1;
    }
    fclose(file);
    file = fopen("../materials/master_levels.db", "rb");
    level *temp_lvl = select_from_levels(file, data -> level_number);
    if (temp_lvl == NULL) {
        fclose(file);
        return 1;
    }
    free(temp_lvl);
    fclose(file);
    return 0;
}
