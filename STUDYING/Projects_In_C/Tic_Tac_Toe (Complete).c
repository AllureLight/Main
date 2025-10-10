#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct gameBoard{
    char Board[3][3];
    char Player;
    int GameOver, Choice;
}GameBoard;

void BoardInitialization(GameBoard* gb, int type){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            gb->Board[i][j] = '-';
        }
    }
    if(type == 2){
        do{
            printf("\n0 - X or 1 - O\nPlayer Choice: ");
            scanf("%d", &gb->Choice);
            if(gb->Choice != 1 && gb->Choice != 0)
                printf("Invalid!\n");
        }while(gb->Choice != 1 && gb->Choice != 0);
    }
    else{
        gb->Choice = 2;
    }
    gb->Player = 'X';
    gb->GameOver = 0;
}

void PrintBoard(GameBoard *gb){
    printf("\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %c", gb->Board[i][j]);
            if(j != 2)
                printf(" |");
        }
        if(i != 2)
            printf("\n-----------\n");
    }
    printf("\n");
}

void MakeYourMove(GameBoard *gb){
    int line, column, valid = 0;

    while(!valid){
        if(gb->Choice == 2){
            printf("\nPlayer %c, make your move.\n", gb->Player);
            printf("Enter a line (1 - 3): ");
            scanf("%d", &line);
            printf("Enter a column (1 - 3): ");
            scanf("%d", &column);
            line--; column--;
        }
        else{
            if(gb->Choice == 0){
                if(gb->Player == 'X'){
                    printf("\nPlayer, make your move.\n");
                    printf("Enter a line (1 - 3): ");
                    scanf("%d", &line);
                    printf("Enter a column (1 - 3): ");
                    scanf("%d", &column);
                    line--; column--;
                }
                else{
                    do{
                        line = rand() % 3;
                        column = rand() % 3;
                    }while(gb->Board[line][column] != '-');
                }
            }else{
                if(gb->Player == 'O'){
                    printf("\nPlayer, make your move.\n");
                    printf("Enter a line (1 - 3): ");
                    scanf("%d", &line);
                    printf("Enter a column (1 - 3): ");
                    scanf("%d", &column);
                    line--; column--;
                }
                else{
                    do{
                        line = rand() % 3;
                        column = rand() % 3;
                    }while(gb->Board[line][column] != '-');
                }
            }
        }
        if(line >= 0 && line < 3 && column >= 0 && column < 3){
            if(gb->Board[line][column] == '-'){
                gb->Board[line][column] = gb->Player;
                valid = 1;
            }else{
                printf("Invalid!\n");
            }
        }else{
            printf("Invalid! Enter numbers between 1 and 3\n");
        }
    }
}


int CheckWinner(GameBoard *gb){
    for(int i = 0; i < 3; i++){
        //Check Line
        if(gb->Board[i][0] == gb->Player && gb->Board[i][1] == gb->Player && gb->Board[i][2] == gb->Player){
            return 1;
        }
        //Check Column
        else if(gb->Board[0][i] == gb->Player && gb->Board[1][i] == gb->Player && gb->Board[2][i] == gb->Player){
            return 1;
        }
    }
    if((gb->Board[0][0] == gb->Player && gb->Board[1][1] == gb->Player && gb->Board[2][2] == gb->Player) || (gb->Board[0][2] == gb->Player && gb->Board[1][1] == gb->Player && gb->Board[2][0] == gb->Player)){
        return 1;
    }
    return 0;
}

int CheckDraw(GameBoard *gb){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(gb->Board[i][j] == '-')
                return 0;
        }
    }
    return 1;
}

void ChangePlayer(GameBoard *gb){
    gb->Player = (gb->Player == 'X') ? 'O' : 'X';
}

int main(){
    GameBoard gb;
    srand((unsigned)time(NULL));
    int type;
    printf("Welcome to Tic Tac Toe Game!\n1 - Player x Player\n2 - Player x Machine\nChoose Game Type: ");
    scanf("%d", &type);

    if(type == 1){
        BoardInitialization(&gb, type);
        while (!gb.GameOver){
            PrintBoard(&gb);
            MakeYourMove(&gb);

            if(CheckDraw(&gb)){
                PrintBoard(&gb);
                printf("\nDraw!");
                gb.GameOver = 1;
            }else if(CheckWinner(&gb)){
                PrintBoard(&gb);
                printf("\nPlayer %c Win!", gb.Player);
                gb.GameOver = 1;
            }
            ChangePlayer(&gb);
        }
    }else if(type == 2){
        BoardInitialization(&gb, type);
        while(!gb.GameOver){
            PrintBoard(&gb);
            MakeYourMove(&gb);

            if(CheckDraw(&gb)){
                PrintBoard(&gb);
                printf("\nDraw!");   
                gb.GameOver = 1;
            }else if(CheckWinner(&gb)){
                PrintBoard(&gb);
                if(gb.Choice == 2){
                    printf("\nPlayer %c Win!", gb.Player);   
                }
                else{
                    if((gb.Choice == 0 && gb.Player == 'X') || (gb.Choice == 1 && gb.Player == 'O')){
                        printf("\nPlayer, you Win!");
                    }else{
                        printf("Machine Win!");
                    }
                }
                gb.GameOver = 1;
            }
            if(!gb.GameOver)
                ChangePlayer(&gb);
        }
    }
    printf("\nThanks for Playing!");

    return 0;
}