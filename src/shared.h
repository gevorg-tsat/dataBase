#ifndef SRC_SHARED_H_
#define SRC_SHARED_H_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "status_events.h"
#include "module.h"
#include "levels.h"
#include <string.h>

struct date_time {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};
int compare(struct date_time door_1, struct date_time door_2);
int selectf(int id, int table, int amount);
int update(int table, int id);
int insert(int table);
int delete(int table, int id);
void bunt();
void set_protected_mode(int id);
void set_status(int id, int status);
int max_event_id();
int move_module(int id, int level, int cell);
int set_protect_flag_in_levels(int lev);
int delete_mod_by_id(int id);
void get_all_active();
int get_status(module mod);
int date_compare(status_events first, status_events second);

#endif  // SRC_SHARED_H_
