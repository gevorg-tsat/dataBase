#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct module {
    int id;
    char name[30];
    int level_number;
    int cell;
    int del;
} module;

module *select_from_module(FILE *db, int id);
int delete_from_modules(FILE *db, int id);
int update_module(FILE *db, int id, module *entity);
int insert_into_module(FILE *db, module *entity);
void print_module(module data);
void print_all_module(FILE *db, int amount);
int input_module(module *data);
