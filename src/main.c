#include <stdio.h>
#include "module.h"
#include "levels.h"

void read_and_print(FILE *file);
void print_struct(level door_state_min);


int main() {
    FILE *file = fopen("../materials/master_levels.db", "rb");
    level *temp;
    //read_and_print(file);
    temp = select(file, 1);
    printf("%d", temp->level_number);
    return 0;
}

void read_and_print(FILE *file) {
    fseek(file, 0, SEEK_END);
    long int n = ftell(file)/(sizeof(level));
    for (long int i = 0; i < n; i++){
        level door_state_;
        fseek(file, i*sizeof(level), SEEK_SET);
        fread(&door_state_, sizeof(level), 1, file);
        print_struct(door_state_);
        if (i != n - 1)
            printf("\n");
    }
}

void print_struct(level door_state_min) {
    printf("%d ", door_state_min.level_number);
    printf("%d ", door_state_min.cell_amount);
    printf("%d", door_state_min.safety_flag);
}

// typedef struct level {
//     int level_number;
//     int cell_amount;
//     int safety_flag;
// } level;