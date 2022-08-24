#include "database.h"
#include "status_events.h"
#include "module.h"
#include "levels.h"



int select(int id, int table, int amount) {
    switch (table) {
    case 0:
        FILE *file = fopen("../materials/master_module.db", "rb");
        if (id != -1) {
            module *temp = select_from_module(file, id);
            if (temp == NULL){
                fclose(file);
                return 1;
            }
            print_module(temp);
            free(temp);
        }
        else
            print_all_module(file, amount);
        fclose(file);
        return 0;
        break;
    case 1:
        FILE *file = fopen("../materials/master_levels.db", "rb");
        if (id != -1) {
            level *temp = select_from_levels(file, id);
            if (temp == NULL){
                fclose(file);
                return 1;
            }
            print_level(temp);
            free(temp);
        }
        else
            print_all_levels(file, amount);
        fclose(file);
        return 0;
        break;
    case 2:
        FILE *file = fopen("../materials/master_status_events.db", "rb");
        if (id != -1) {
            status_events *temp = select_from_events(file, id);
            if (temp == NULL){
                fclose(file);
                return 1;
            }
            print_event(temp);
            free(temp);
        }
        else
            print_all_events(file, amount);
        fclose(file);
        return 0;
        break;
    default:
    break;
    }
}

int update(int table, int id) {
    switch (table) {
    case 0:
        FILE *file = fopen("../materials/master_module.db", "rb+");
        // if (id != -1) {
        //     module *temp = select_from_module(file, id);
        //     if (temp == NULL){
        //         return 1;
        //     }
        //     print_module(temp);
        // }                                 MAKE UPDATE_ALL FEATURE
        module temp;
        input_module(&temp);
        int num = update_module(file, id, &temp);
        fclose(file);
        return num;
        break;
    case 1:
        FILE *file = fopen("../materials/master_levels.db", "rb");
        // if (id != -1) {
        //     level *temp = select_from_levels(file, id);
        //     if (temp == NULL){
        //         return 1;
        //     }
        //     print_level(temp);
        // }
        level temp;
        input_level(&temp);
        int num = update_level(file, id, &temp);
        fclose(file);
        return num;
        break;
    case 2:
        FILE *file = fopen("../materials/master_status_events.db", "rb");
        // if (id != -1) {
        //     status_events *temp = select_from_events(file, id);
        //     if (temp == NULL){
        //         return 1;
        //     }
        //     print_event(temp);
        // }
        status_events temp;
        input_event(&temp);
        int num = update_events(file, id, &temp);
        fclose(file);
        return num;
        break;
    default:
    break;
    }
}

int insert(int table) {
    switch (table) {
    case 0:
        FILE *file = fopen("../materials/master_module.db", "rb+");
        module temp;
        input_module(&temp);
        int num = insert_into_module(file, &temp);
        fclose(file);
        return num;
        break;
    case 1:
        FILE *file = fopen("../materials/master_levels.db", "rb");
        level temp;
        input_level(&temp);
        int num = insert_into_levels(file, &temp);
        fclose(file);
        return num;
        break;
    case 2:
        FILE *file = fopen("../materials/master_status_events.db", "rb");
        status_events temp;
        input_event(&temp);
        int num = insert_into_events(file, &temp);
        fclose(file);
        return num;
        break;
    default:
    break;
    }
}

int delete(int table, int id) {
    switch (table) {
    case 0:
        FILE *file = fopen("../materials/master_module.db", "rb+");
        int num = delete_from_modules(file, id);
        fclose(file);
        return num;
        break;
    case 1:
        FILE *file = fopen("../materials/master_levels.db", "rb");
        int num = delete_from_levels(file, id);
        fclose(file);
        return num;
        break;
    case 2:
        FILE *file = fopen("../materials/master_status_events.db", "rb");
        int num = delete_from_events(file, id);
        fclose(file);
        return num;
        break;
    default:
    break;
    }
}




