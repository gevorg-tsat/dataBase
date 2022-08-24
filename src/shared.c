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
                return 1;
            }
            print_module(temp);
        }
        else
            print_all_module(file, amount);
        break;
    case 1:
        FILE *file = fopen("../materials/master_levels.db", "rb");
        if (id != -1) {
            level *temp = select_from_levels(file, id);
            if (temp == NULL){
                return 1;
            }
            print_level(temp);
        }
        else
            print_all_levels(file, amount);
        break;
    case 2:
        FILE *file = fopen("../materials/master_status_events.db", "rb");
        if (id != -1) {
            status_events *temp = select_from_events(file, id);
            if (temp == NULL){
                return 1;
            }
            print_event(temp);
        }
        else
            print_all_events(file, amount);
        break;
    default:
    break;
    }
}





