//
//  elementary_data_structures.c
//  problemsets_1a
//
//  Created by Steve on 8/1/20.
//  Copyright © 2020 Steve. All rights reserved.
//

#include <stdio.h>

typedef struct
{
    int day;
    int month;
    int year;
} DateT;

typedef struct
{
    int hour;
    int minute;
} TimeT;

typedef struct
{
    int transaction;
    char weekday[3]; // 3 chars + terminateing '\0'
    DateT date;
    TimeT time;
    char mode;  // B, F or T
    char from[32];  // no more than 31 chars
    int journey;
    char faretext[12];
    float fare, discount, amount;
} JourneyT;
