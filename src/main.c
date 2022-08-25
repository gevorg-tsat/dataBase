#include <stdio.h>
#include "shared.h"

int menu();
int set_flag_process();
int move_process();
int prot_mode_process();
int delete_by_process();
int delete_process();
int update_process();
int insert_process();
int select_process();
int table_menu();
int select_menu();

int main() {
    int flag = 1;
    while (flag) {
        int men = menu();
        switch (men) {
        case 1:
            if (select_process())
                continue;
            break;
        case 2:
            if (insert_process())
                continue;
            break;
        case 3:
            if (update_process())
                continue;
            break;
        case 4:
            if (delete_process())
                continue;
            break;
        case 5:
            get_all_active();
            break;
        case 6:
            if (delete_by_process())
                continue;
            break;
        case 7:
            if (prot_mode_process())
                continue;
            break;
        case 8:
            if (move_process())
                continue;
            break;
        case 9:
            if (set_flag_process())
                continue;
            break;
        case 10:
            bunt();
            printf("DONE\n");
            break;
        case 0:
            flag = 0;
            break;
        default:
            continue;
        }
    }
    return 0;
}

int menu() {
    printf("Please choose one operation:\n");
    printf("    1. SELECT\n");
    printf("    2. INSERT\n");
    printf("    3. UPDATE\n");
    printf("    4. DELETE\n");
    printf("    5. Get all active additional modules (last module status is 1)\n");
    printf("    6. Delete modules by ids\n");
    printf("    7. Set protected mode for module by id\n");
    printf("    8. Move module by id to specified memory level and cell\n");
    printf("    9. Set protection flag of the specified memory level\n");
    printf("    10. do THE Instuctions\n");
    printf("    0. EXIT\n");
    int oper;
    if (scanf("%d", &oper) != 1 || oper > 10 || oper < 0)
        return -1;
    return oper;
}

int set_flag_process() {
    printf("Input Memory level you want to set flag\n");
    int id;
    if (scanf("%d", &id) != 1) {
        printf("Invalid value\n");
        return 1;
    }
    if (set_protect_flag_in_levels(id)) {
        printf("Failed\n");
        return 1;
    }
    printf("DONE\n");
    return 0;
}

int move_process() {
    printf("Input id of Module you want to move\n");
    int id;
    if (scanf("%d", &id) != 1) {
        printf("Invalid value\n");
        return 1;
    }
    printf("Input lvl and cell you want to move\n");
    int lvl, cell;
    if (scanf("%d %d", &lvl, &cell) != 2) {
        printf("Invalid value\n");
        return 1;
    }
    if (move_module(id, lvl, cell)) {
        printf("Failed\n");
        return 1;
    }
    printf("DONE\n");
    return 0;
}

int prot_mode_process() {
    printf("Input id of Module you want to set protection mode\n");
    int id;
    if (scanf("%d", &id) != 1) {
        printf("Invalid value\n");
        return 1;
    }
    set_protected_mode(id);
    printf("DONE\n");
    return 0;
}

int delete_by_process() {
    printf("Input id of Module you want to set delete flag\n");
    int id;
    if (scanf("%d", &id) != 1) {
        printf("Invalid value\n");
        return 1;
    }
    if (delete_mod_by_id(id)) {
        printf("Failed\n");
        return 1;
    }
    printf("DONE\n");
    return 0;
}

int delete_process() {
    int table;
    table = table_menu();
    if (table == -1) {
        printf("Invalid value\n");
        return 1;
    }
    printf("Input Primary key of Data you want to delete\n");
    int id;
    if (scanf("%d", &id) != 1) {
        printf("Invalid value\n");
        return 1;
    }
    if (delete(table, id)) {
        printf("Failed\n");
        return 1;
    }
    printf("Data deleted\n");
    return 0;
}

int update_process() {
    int table;
    table = table_menu();
    if (table == -1) {
        printf("Invalid value\n");
        return 1;
    }
    printf("Input Primary key you want to change\n");
    int id;
    if (scanf("%d", &id) != 1) {
        printf("Invalid value\n");
        return 1;
    }
    if (update(table, id)) {
        printf("Failed\n");
        return 1;
    }
    printf("Data changed\n");
    return 0;
}

int insert_process() {
    int table;
    table = table_menu();
    if (table == -1) {
        printf("Invalid value\n");
        return 1;
    }
    if (insert(table)) {
        printf("Invalid value or Failed\n");
        return 1;
    }
    printf("New Data added\n");
    return 0;
}

int select_process() {
    int table;
    table = table_menu();
    if (table == -1) {
        printf("Invalid value\n");
        return 1;
    }
    int select_type = select_menu();
    if (select_type == -1) {
        printf("Invalid value\n");
        return 1;
    }
    if (select_type == 1) {
        printf("Input Primary key\n");
        int id;
        if (scanf("%d", &id) != 1) {
            printf("Invalid value\n");
            return 1;
        }
        if (selectf(id, table, -1)) {
            printf("No data with this Primary key\n");
            return 1;
        }
    }
    if (select_type == 2) {
        int amount;
        printf("Enter amount of data you want or -1 if you want it all\n");
        if (scanf("%d", &amount) != 1 || amount < -1) {
            printf("Invalid value\n");
            return 1;
        }
        selectf(-1, table, amount);
    }
    return 0;
}


int table_menu() {
    printf("Please choose a table:\n");
    printf("    1. Modules\n");
    printf("    2. Levels\n");
    printf("    3. Status events\n");
    int oper;
    if (scanf("%d", &oper) != 1 || oper > 3 || oper <= 0)
        return -1;
    return oper - 1;
}
int select_menu() {
    printf("    1. Select by primary key\n");
    printf("    2. Select all\n");
    int oper;
    if (scanf("%d", &oper) != 1 || oper > 2 || oper <= 0)
        return -1;
    return oper;
}

