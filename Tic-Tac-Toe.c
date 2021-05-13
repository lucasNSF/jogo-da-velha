#include <stdio.h>
#include <locale.h>
#define size 3

//Game array
char hash[3][3];

//Options menu variables
int options[9] = {0}, count_options = 0;
int aux_options[9] = {0};

//Variable indicating the winner of the game
int winner = 0;

/* This function is used to ask the user an option relative to where he'll go to play. 
    It's also going to check if the option is available or not. */
void checker_option() {
    do {
        printf("\nChoose one of the options:");
        scanf("%d", &options[count_options]);
        if (options[count_options] < 1 || options[count_options] > 9)
            printf("The option is out the available range! Please, try again.\n");

        for (int i = 0; i < 9; i++) {
            if (aux_options[i] == options[count_options]) {
                printf("The option isn't more available! Please, enter a new number.\n");
                options[count_options] = 0;
                break;
            }
        }
    
    } while (options[count_options] < 1 || options[count_options] > 9);

    aux_options[count_options] = options[count_options];
    count_options++;
}

//This function returns the game selection panel.
void game_menu() {
    int numbers[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int line, column;

    for (line = 0; line < size; line++) {
        for (column = 0; column < size; column++) {
            if (hash[line][column] == 'X' || hash[line][column] == 'O')
                printf("   %c   ", hash[line][column]);
            else
                printf("   %d   ", numbers[line][column]);
            if (column != 2)
                printf("%c", 166);            
        }
        if (line != 2)
            printf("\n-----------------------\n");
    }
}

// This function calculates the game winner, returning the winner's name.
int checker_game() {
    //Checking the rows.
    if (hash[0][0] == 'X' && hash[0][1] == 'X' && hash[0][2] == 'X' ||
        hash[1][0] == 'X' && hash[1][1] == 'X' && hash[1][2] == 'X' ||
        hash[2][0] == 'X' && hash[2][1] == 'X' && hash[2][2] == 'X') {
            winner = 1;
        }

    if (hash[0][0] == 'O' && hash[0][1] == 'O' && hash[0][2] == 'O' ||
        hash[1][0] == 'O' && hash[1][1] == 'O' && hash[1][2] == 'O' ||
        hash[2][0] == 'O' && hash[2][1] == 'O' && hash[2][2] == 'O') {
            winner = 2;
        }

    //Checking the columns.
    if (hash[0][0] == 'X' && hash[1][0] == 'X' && hash[2][0] == 'X' ||
        hash[0][1] == 'X' && hash[1][1] == 'X' && hash[2][1] == 'X' ||
        hash[0][2] == 'X' && hash[1][2] == 'X' && hash[2][2] == 'X') {
            winner = 1;
        }

    if (hash[0][0] == 'O' && hash[1][0] == 'O' && hash[2][0] == 'O' ||
        hash[0][1] == 'O' && hash[1][1] == 'O' && hash[2][1] == 'O' ||
        hash[0][2] == 'O' && hash[1][2] == 'O' && hash[2][2] == 'O') {
            winner = 2;
        }

    //Checking the main diagonal.
    if (hash[0][0] == 'X' && hash[1][1] == 'X' && hash[2][2] == 'X')
        winner = 1;

    if (hash[0][0] == 'O' && hash[1][1] == 'O' && hash[2][2] == 'O')
        winner = 2;

    //Checking the secondary diagonal.
    if (hash[0][2] == 'X' && hash[1][1] == 'X' && hash[2][0] == 'X')
        winner = 1;

    if (hash[0][2] == 'O' && hash[1][1] == 'O' && hash[2][0] == 'O')
        winner = 2;
    
    return winner;
}

//This function reset the game.
void reset() {
    //Resetting the game's array.
    for (int line = 0; line < size; line++) {
        for (int column = 0; column < size; column++) {
            hash[line][column] = '0';
        }
    }

    //Resetting the game options menu.
    for (int j = 0; j < 9; j++) {
        options[j] = 0;
        aux_options[j] = 0;
    }

    count_options = 0;
    winner = 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    const char choice_p1 = 'X', choice_p2 = 'O';

    // entrance: Loop control variable;  input: choice control variable;  
    int input, entrance = 1;

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\tTHE TIC-TAC-TOE\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");


    while (entrance == 1) {
        game_menu();
        printf("\n");
        checker_option();

        switch (options[0]) { // 1st Move
            case 1: hash[0][0] = choice_p1; break;
            case 2: hash[0][1] = choice_p1; break;
            case 3: hash[0][2] = choice_p1; break;
            case 4: hash[1][0] = choice_p1; break;
            case 5: hash[1][1] = choice_p1; break;
            case 6: hash[1][2] = choice_p1; break;
            case 7: hash[2][0] = choice_p1; break;
            case 8: hash[2][1] = choice_p1; break;
            default: hash[2][2] = choice_p1;
        }

        game_menu();
        printf("\n");
        checker_option();

        switch (options[1]) { // 2nd Move
            case 1: hash[0][0] = choice_p2; break;
            case 2: hash[0][1] = choice_p2; break;
            case 3: hash[0][2] = choice_p2; break;
            case 4: hash[1][0] = choice_p2; break;
            case 5: hash[1][1] = choice_p2; break;
            case 6: hash[1][2] = choice_p2; break;
            case 7: hash[2][0] = choice_p2; break;
            case 8: hash[2][1] = choice_p2; break;
            default: hash[2][2] = choice_p2;
        }

        game_menu();
        printf("\n");
        checker_option();

        switch (options[2]) { // 3rd Move
            case 1: hash[0][0] = choice_p1; break;
            case 2: hash[0][1] = choice_p1; break;
            case 3: hash[0][2] = choice_p1; break;
            case 4: hash[1][0] = choice_p1; break;
            case 5: hash[1][1] = choice_p1; break;
            case 6: hash[1][2] = choice_p1; break;
            case 7: hash[2][0] = choice_p1; break;
            case 8: hash[2][1] = choice_p1; break;
            default: hash[2][2] = choice_p1;
        }

        game_menu();
        printf("\n");
        checker_option();

        switch (options[3]) { // 4th Move
            case 1: hash[0][0] = choice_p2; break;
            case 2: hash[0][1] = choice_p2; break;
            case 3: hash[0][2] = choice_p2; break;
            case 4: hash[1][0] = choice_p2; break;
            case 5: hash[1][1] = choice_p2; break;
            case 6: hash[1][2] = choice_p2; break;
            case 7: hash[2][0] = choice_p2; break;
            case 8: hash[2][1] = choice_p2; break;
            default: hash[2][2] = choice_p2;
        }

        game_menu();
        printf("\n");
        checker_option();

        switch (options[4]) { // 5th Move. Here begins the checks.
            case 1: hash[0][0] = choice_p1; break;
            case 2: hash[0][1] = choice_p1; break;
            case 3: hash[0][2] = choice_p1; break;
            case 4: hash[1][0] = choice_p1; break;
            case 5: hash[1][1] = choice_p1; break;
            case 6: hash[1][2] = choice_p1; break;
            case 7: hash[2][0] = choice_p1; break;
            case 8: hash[2][1] = choice_p1; break;
            default: hash[2][2] = choice_p1;
        }

        game_menu();
        if (checker_game() == 1 || checker_game() == 2)
            goto end;
        printf("\n");
        checker_option();

        switch (options[5]) { // 6th Move.
            case 1: hash[0][0] = choice_p2; break;
            case 2: hash[0][1] = choice_p2; break;
            case 3: hash[0][2] = choice_p2; break;
            case 4: hash[1][0] = choice_p2; break;
            case 5: hash[1][1] = choice_p2; break;
            case 6: hash[1][2] = choice_p2; break;
            case 7: hash[2][0] = choice_p2; break;
            case 8: hash[2][1] = choice_p2; break;
            default: hash[2][2] = choice_p2;
        }

        game_menu();
        if (checker_game() == 1 || checker_game() == 2)
            goto end;
        printf("\n");
        checker_option();

        switch (options[6]) { // 7th Move.
            case 1: hash[0][0] = choice_p1; break;
            case 2: hash[0][1] = choice_p1; break;
            case 3: hash[0][2] = choice_p1; break;
            case 4: hash[1][0] = choice_p1; break;
            case 5: hash[1][1] = choice_p1; break;
            case 6: hash[1][2] = choice_p1; break;
            case 7: hash[2][0] = choice_p1; break;
            case 8: hash[2][1] = choice_p1; break;
            default: hash[2][2] = choice_p1;
        }

        game_menu();
        if (checker_game() == 1 || checker_game() == 2)
            goto end;
        printf("\n");
        checker_option();
        
        switch (options[7]) { // 8th Move.
            case 1: hash[0][0] = choice_p2; break;
            case 2: hash[0][1] = choice_p2; break;
            case 3: hash[0][2] = choice_p2; break;
            case 4: hash[1][0] = choice_p2; break;
            case 5: hash[1][1] = choice_p2; break;
            case 6: hash[1][2] = choice_p2; break;
            case 7: hash[2][0] = choice_p2; break;
            case 8: hash[2][1] = choice_p2; break;
            default: hash[2][2] = choice_p2;
        }

        game_menu();
        if (checker_game() == 1 || checker_game() == 2)
            goto end;
        printf("\n");
        checker_option();

        switch (options[8]) { // Last Move.
            case 1: hash[0][0] = choice_p1; break;
            case 2: hash[0][1] = choice_p1; break;
            case 3: hash[0][2] = choice_p1; break;
            case 4: hash[1][0] = choice_p1; break;
            case 5: hash[1][1] = choice_p1; break;
            case 6: hash[1][2] = choice_p1; break;
            case 7: hash[2][0] = choice_p1; break;
            case 8: hash[2][1] = choice_p1; break;
            default: hash[2][2] = choice_p1;
        }

        game_menu();
        if (checker_game() == 1 || checker_game() == 2)
            goto end;
        printf("\n");

        end:
            if (winner == 1) {
                printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                printf("\tCONGRATULATIONS! Player 1 Wins.\n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            }
            else if (winner == 2) {
                printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                printf("\tCONGRATULATIONS! Player 2 Wins.\n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            }
            else {
                printf("\n\n-=-=-=-=-=-=-=-=-=-=-=\n");
                printf("\tDRAW\n");
                printf("-=-=-=-=-=-=-=-=-=-=-=\n");
            }

        do {
            printf("\n\nDo you want to play again?\n");
            printf("[1] Yes.   [2] No.\n");
            printf("Option: ");
            scanf("%d", &input);

            if (input < 1 || input > 2)
                printf("Invalid option. Try again!");
            
            if (input == 2)
                entrance = 2;
            else
                reset();
        
        } while (input < 1 || input > 2);
        printf("\n\n");
    }
    
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\tTHANKS FOR PLAYING! :D\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    return 0;
}