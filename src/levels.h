#ifndef SRC_LEVELS_H_
#define SRC_LEVELS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct level {
    int level_number;
    int cell_amount;
    int safety_flag;
} level;

level *select_from_levels(FILE *db, int level_number);
int delete_from_levels(FILE *db, int id);
int update_level(FILE *db, int id, level *entity);
int insert_into_levels(FILE *db, level *entity);

void print_level(level temp);
void print_all_levels(FILE *db, int amount);
int input_level(level *data);

#endif  // SRC_LEVELS_H_