#include "shared.h"


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

// 5. Get all active additional modules (last module status is 1)
// 6. Delete modules by ids
// 7. Set protected mode for module by id
// 8. Move module by id to specified memory level and cell
// 9. Set protection flag of the specified memory level

void bunt() {
    FILE *file = fopen("../materials/master_module.db", "rb+");
    fseek(file, 0, SEEK_END);
    long int n = ftell(file)/(sizeof(module));
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < n; i++) {
        fseek(file_m, i * sizeof(module), SEEK_SET);
        module temp;
        fread(&temp, sizeof(module), 1, file_m);
        if (get_status(temp) == 1) {
            set_status(temp.id, 0);
            temp.del = 1;
            fseek(file_m, i * sizeof(module), SEEK_SET);
            fwrite(&temp, sizeof(module), 1, file);
        }
    }
    set_protected_mode(0);
    move_module(0, 1, 1);
    set_protect_flag_in_levels(1);
}

void set_protected_mode(int id) {
    FILE *file = fopen("../materials/master_status_events.db", "rb+");
    status_events new_event;
    new_event.event = max_event_id() + 1;
    new_event.module = id;
    new_event.new_status = 0;
    time_t cur_seconds = time(NULL);
    struct tm *cur_time = localtime(&cur_seconds);
    strftime(new_event.date, 11, "%d.%m.%Y", cur_time);
    strftime(new_event.time, 8, "%H:%M:%S", cur_time);
    insert_into_events(file, &new_event);
    new_event.new_status = 1;
    new_event.event = max_event_id() + 1;
    cur_seconds = time(NULL);
    tm *cur_time = localtime(&cur_seconds);
    strftime(new_event.date, 11, "%d.%m.%Y", cur_time);
    strftime(new_event.time, 8, "%H:%M:%S", cur_time);
    insert_into_events(file, &new_event);
    new_event.new_status = 20;
    new_event.event = max_event_id() + 1;
    cur_seconds = time(NULL);
    tm *cur_time = localtime(&cur_seconds);
    strftime(new_event.date, 11, "%d.%m.%Y", cur_time);
    strftime(new_event.time, 8, "%H:%M:%S", cur_time);
    insert_into_events(file, &new_event);
    fclose(file);
}

void set_status(int id, int status) {
    FILE *file = fopen("../materials/master_status_events.db", "rb+");
    status_events new_event;
    new_event.event = max_event_id() + 1;
    new_event.module = id;
    new_event.new_status = status;
    time_t cur_seconds = time(NULL);
    struct tm *cur_time = localtime(&cur_seconds);
    strftime(new_event.date, 11, "%d.%m.%Y", cur_time);
    strftime(new_event.time, 8, "%H:%M:%S", cur_time);
    insert_into_events(file, &new_event);
    fclose(file);

}
int max_event_id() {
    FILE *file = fopen("../materials/master_status_events.db", "rb+");
    fseek(file, 0, SEEK_END);
    long int n = ftell(file)/(sizeof(status_events));
    fseek(file, 0, SEEK_SET);
    int max_d = -1;
    for (int i = 0; i < n; i++) {
        fseek(file_m, i * sizeof(status_events), SEEK_SET);
        status_events temp;
        fread(&temp, sizeof(status_events), 1, file_m);
        if (temp.event > max_d)
            max_d = temp.event;
    }
    fclose(file);
    return max_d;
}

int move_module(int id, int level, int cell) {
    FILE *file = fopen("../materials/master_module.db", "rb+");
    fseek(file, 0, SEEK_END);
    long int n = ftell(file)/(sizeof(module));
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < n; i++) {
        fseek(file_m, i * sizeof(module), SEEK_SET);
        module temp;
        fread(&temp, sizeof(module), 1, file_m);
        if (temp.id == id) {
            temp.cell = cell;
            temp.level_number = level;
            fseek(file_m, i * sizeof(level), SEEK_SET);
            fwrite(&temp, sizeof(level), 1, file);
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}

// int set_protect_flag(int id) {
//     FILE *file = fopen("../materials/master_module.db", "rb+");
//     fseek(file, 0, SEEK_END);
//     long int n = ftell(file)/(sizeof(module));
//     fseek(file, 0, SEEK_SET);
//     for (int = 0; i < n; i++) {
//         fseek(file_m, i * sizeof(module), SEEK_SET);
//         module temp;
//         fread(&temp, sizeof(module), 1, file_m);
//         if (temp.id == id) {
//             set_protect_mode_in_levels(temp.level_number);
//             fclose(file);
//             return 0;
//         }
//     }
//     fclose(file);
//     return 1;
// }

int set_protect_flag_in_levels(int lev) {
    FILE *file = fopen("../materials/master_level.db", "rb+");
    fseek(file, 0, SEEK_END);
    long int n = ftell(file)/(sizeof(level));
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < n; i++) {
        fseek(file, i * sizeof(level), SEEK_SET);
        level temp;
        fread(&temp, sizeof(level), 1, file);
        if (temp.level_number == level) {
            temp.safety_flag = 1;
            fseek(file_m, i * sizeof(level), SEEK_SET);
            fwrite(&temp, sizeof(level), 1, file);
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}
int delete_mod_by_id(int id) {
    FILE *file = fopen("../materials/master_module.db", "rb+");
    fseek(file, 0, SEEK_END);
    long int n = ftell(file)/(sizeof(module));
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < n; i++) {
        fseek(file_m, i * sizeof(module), SEEK_SET);
        module temp;
        fread(&temp, sizeof(module), 1, file_m);
        if (temp.id == id) {
            temp.del = 1;
            fseek(file_m, i * sizeof(module), SEEK_SET);
            fwrite(&temp, sizeof(module), 1, file);
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}



void get_all_active() {
    FILE *file_m = fopen("../materials/master_module.db", "rb+");
    fseek(file_m, 0, SEEK_END);
    long int n = ftell(file_m)/(sizeof(module));
    for (long int i = 0; i < n; i++) {
        fseek(file_m, i * sizeof(module), SEEK_SET);
        module temp;
        fread(&temp, sizeof(module), 1, file_m);
        if (get_status(temp))
            print_module(temp);
    }
    fclose(file_m);
}

int get_status(module mod) {
    FILE *file_ev = fopen("../materials/master_status_events.db", "rb");
    status_events temp;
    status_events newest = {.change_date = "00.00.0000", .change_time = "00:00:00", .new_status = 0};
    fseek(file_ev, 0, SEEK_END);
    long int m = ftell(file_ev)/(sizeof(status_events));
    fseek(file_ev, 0, SEEK_SET);
    fread(&newest, sizeof(status_events), 1, file_ev);
    for (int i = 0; i < m; i++) {
        fseek(db, i * sizeof(status_events), SEEK_SET);
        fread(&temp, sizeof(status_events), 1, db);
        if (temp.module == mod.id) {
            if (strcmp(newest.change_date, "00.00.0000") == 0) {
                newest = temp;
            }
            else {
                if (date_compare(temp, newest) >= 0) {
                    newest = temp;
                }
            }
        }
    }
    fclose(file_ev);
    return newest.new_status;
}

int date_compare(status_events first, status_events second) {
    long int date1 = 0, date2 = 0;
    date1 += ((first.change_date[6] - '0') * 10000000 + (first.change_date[7] - '0') * 1000000 + (first.change_date[8] - '0') * 100000 + (first.change_date[9] - '0') * 10000);
    date1 += ((first.change_date[3] - '0') * 1000) + (first.change_date[4] - '0') * 100) + (first.change_date[0] - '0') * 10) + (first.change_date[1] - '0') * 1);
    date2 += ((second.change_date[6] - '0') * 10000000 + (second.change_date[7] - '0') * 1000000 + (second.change_date[8] - '0') * 100000 + (second.change_date[9] - '0') * 10000);
    date2 += ((second.change_date[3] - '0') * 1000) + (second.change_date[4] - '0') * 100) + (second.change_date[0] - '0') * 10) + (second.change_date[1] - '0') * 1);
    if (date1 > date2)
        return 1;
    if (date2 > date1)
        return -1;
    long int time1 = 0, time2 = 0;
    time1 = time1 + (first.change_time[0] - '0') * 10 + (first.change_time[1] - '0') * 360 + (first.change_time[3] - '0') * 10 + (first.change_time[4] - '0') * 60 
        + (first.change_time[6] - '0') * 10 + (first.change_time[7] - '0');
    time2 = time2 + (second.change_time[0] - '0') * 10 + (second.change_time[1] - '0') * 360 + (second.change_time[3] - '0') * 10 + (second.change_time[4] - '0') * 60 
        + (second.change_time[6] - '0') * 10 + (second.change_time[7] - '0');
    if (time1 > time2)
        return 1;
    if (time2 > time1)
        return -1;
    return 0;
}