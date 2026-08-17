//
// Created by gnkih on 16/08/2026.
//

/*
 * A telecom has a number, name, persons ID, and payment
 * A user can delete, add and view payments
 * Records of calls
 */
#include "telecom_header.h"
#include <stdio.h>
#include <string.h>


void add_customer(char name[], int number, float payment) {
    //inhibit number duplication
    for (int i = 0; i < customer_count; i++) {
        if (logged_customer[i].phone_number == number) {
            printf("The number %d is already owned", number);
            return;
        }
    }
    //log the phone number, payment and name
    logged_customer[customer_count].phone_number = number;

    logged_customer[customer_count].payment = payment;

    strcpy(logged_customer[customer_count].name, name);

    //initialize the call counter
    logged_customer[customer_count].caller_history = 0;

    printf("The user registered name is a %s \n Registered phone number %d \n Payment each month %.2f\n",
           logged_customer[customer_count].name, logged_customer[customer_count].phone_number,
           logged_customer[customer_count].payment);
    //add the counter for the elements in the array
    customer_count++;
}

void view_customer(int number) {
    for (int i = 0; i < customer_count; i++) {
        if (logged_customer[i].phone_number == number) {
            printf("The user name is %s, with payment %f in phone number %d",
                   logged_customer[i].name, logged_customer[i].payment, logged_customer[i].phone_number);
            return;
        }
    }
    printf("this phone number does not exist");
}

void change_customer(int number, float payment) {
    for (int i = 0; i < customer_count; i++) {
        if (logged_customer[i].phone_number == number) {
            logged_customer[i].payment = payment;
            printf("The customer with phone number %d to %.2f", number, logged_customer[i].payment);
            return;
        }
    }
    printf("No customer can be found");
}

void delete_customer(int number) {
    for (int i = 0; i < customer_count; i++) {
        if (logged_customer[i].phone_number == number) {
            printf("We have deleted number %d \n Customer name %s and payment %f",
                   logged_customer[i].phone_number, logged_customer[i].name, logged_customer[i].payment);

            //move the number to the last value in the array
            for (int j = i; j < customer_count; j++) {
                logged_customer[j] = logged_customer[j + 1];
            }
            customer_count--;
        }
    }
    printf("This phone number does not exist");
}

void call_log(int caller_number, int receiver_number,   float time) {
    for (int i = 0; i < customer_count; i++) {
        //ensure the caller exist
        if (logged_customer[i].phone_number == caller_number && caller_number != receiver_number) {

            for (int s = 0; s < customer_count; s++) {
                //ensure the reciever also exists
                if (receiver_number == logged_customer[s].phone_number) {

                    //add to callers history
                    logged_customer[i].number_of_calls[logged_customer[i].caller_history] = caller_number;
                    logged_customer[i].caller_history += 1;

                    //the time counter
                    logged_customer[i].call_hours += time;

                    printf("The number %d has called %d amount of hours"
                           "for %.2f amount of minutes \n", caller_number, receiver_number, time);

                    printf("Number of times the caller has called: %d\n ", logged_customer[i].caller_history);

                    //print caller history
                    printf("phone numbers the caller has called: \n");
                    for (int j = 0; j < logged_customer[i].caller_history; j++) {
                        printf("%d\n", logged_customer[i].number_of_calls[j]);
                    }
                    return;
                }
            }
        }
    }
}


int main() {
        char name[100], action[100];
        float payment, call_time;
        int created_number, receiver_number, caller_number;

        while (customer_count < data_size) {
            printf("\nEnter what action you which to do with the data base. \n"
                "Do you want to add, view, delete, change or call a customer: ");
            scanf("%s", action);

            if (strcmp(action, "add") == 0) {
                printf("input user name: \n");
                scanf("%s", name);

                printf("input their payment plan: \n");
                scanf("%f", &payment);

                printf("input user their phone number: \n");
                scanf("%d", &created_number);

                add_customer(name, created_number, payment);

            }

            if (strcmp(action, "view") == 0) {
                printf("input user their phone number: \n");
                scanf("%d", &created_number);

                view_customer(created_number);
            }

            if (strcmp(action, "delete") == 0) {
                printf("input user their phone number: \n");
                scanf("%d", &created_number);

                delete_customer(created_number);
            }

            if (strcmp(action, "change") == 0) {
                printf("input user their phone number: \n");
                scanf("%d", &created_number);

                printf("What should would you change to the payment: \n");
                scanf("%f", &payment);

                change_customer(created_number, payment);
            }

            if (strcmp(action, "call") == 0) {
                printf("input the caller number: \n");
                scanf("%d", &caller_number);

                printf("input the receivers number: \n");
                scanf("%d", &receiver_number);

                printf("input the time of calling: \n");
                scanf("%f", &call_time);

                call_log(caller_number, receiver_number,  call_time);
            }

        }
        return 0;
}

