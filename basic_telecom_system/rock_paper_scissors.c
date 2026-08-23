//
// Created by gnkih on 17/07/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define min_rand 0
#define max_rand 100
void rock_paper_scissor (const char *user_1, const char* user_2) {

    char rock []= "r"; char scissor [] = "s"; char paper [] = "p";
    if (strcmp(user_1, user_2) == 0) {
        printf("it is a tie");
        return;
    }
    //paper
    if (strcmp(user_1, rock) == 0 && strcmp(user_2, paper) == 0) {
        printf("paper wins and the computer wins");
    } else if (strcmp(user_1, paper) == 0 && strcmp(user_2, rock) == 0) {
        printf("paper wins and the you wins");
        //rock
    } else if (strcmp(user_1, rock) == 0 && strcmp(user_2, scissor) == 0) {
        printf("rock wins and the you wins");
    }  else if (strcmp(user_1, scissor) == 0 && strcmp(user_2, rock) == 0) {
        printf("rock wins and the computer wins");
        //scissors
    } else if (strcmp(user_1, paper) == 0 && strcmp(user_2, scissor) == 0) {
        printf("scissors wins and the computer wins");
    } else if (strcmp(user_1, scissor) == 0 && strcmp(user_2, paper) == 0) {
        printf("scissors wins and the you wins");
    }

}

char* computer_selection(int random) {
    if (random > 0 && random <= 33) return "r";
    if (random > 33 && random <= 66) return "p";

    return "s";
}

int calculator (int first_number, int second_number, char *operation) {
    if (strcmp(operation, "+") == 0) {
        return first_number + second_number;
    }

    if (strcmp(operation, "-") == 0) {
        return first_number - second_number;
    }

    if (strcmp(operation, "/") == 0) {
        return first_number / second_number;
    }

    if (strcmp(operation, "*") == 0) {
        return first_number * second_number;
    }

    return 0;
}

int main (void) {

    srand(time(NULL));

   int computer_rand = rand() % max_rand;
    printf("The user inputs either s (scissors), r (rock), p (paper): \n");

    char user_1[2];

    scanf("%c", &user_1[0]);
    user_1[1] = '\0';

    printf("%c \n", user_1[0]);


    printf("The you choose: %c, and computer choose %c \n", user_1[0], *computer_selection(computer_rand));
    rock_paper_scissor(user_1, computer_selection(computer_rand));
    
    return 0;
}