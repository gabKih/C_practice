//
// Created by gnkih on 16/08/2026.
//

#ifndef PROJECT_DATA_HOLDING_C_H
#define PROJECT_DATA_HOLDING_C_H

#define data_size 200

typedef struct  {
    int phone_number;
    char name [50];
    float payment;
    float call_hours; //time

    int caller_history;

    int number_of_calls[data_size * 3]; //what number called
} customer;


static customer logged_customer [data_size];

static int customer_count = 0;

#endif //PROJECT_DATA_HOLDING_C_H
