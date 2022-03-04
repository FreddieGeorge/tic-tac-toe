/**
 * @file tic_tac_toe.c
 * @author Flork
 *         CSDN :Flork
 *         github:https://github.com/FreddieGeorge
 * @brief A simple tic tac toe game running at terminal
 * @version 0.1
 * @date 2022-03-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

int isWin(int chess_bord[3][3]);
void DisplayBoard(int chess_bord[3][3]);
void Change_chess_board(int chess_bord[3][3], int player);
int game_engine();

/**
 * @brief change the chess_board array and display it on the terminal
 * 
 * @param chess_bord :The array of the chess board
 * @param player 1 or 2 ,means player 1 or player 2
 */
void Change_chess_board(int chess_bord[3][3], int player)
{
    int x, y = 0;
    printf("Player %d input your chess place:\nx y\n", player);
    scanf("%d %d", &x, &y);
    if (1 <= x && x <= 3 && 1 <= y && y <= 3)
    {
        if (chess_bord[x - 1][y - 1] != 0)
        {
            system("cls");
            printf("Wrong Input,this place has had a chess!\n");
            DisplayBoard(chess_bord);
            Change_chess_board(chess_bord, player);
        }
        else
        {
            chess_bord[x - 1][y - 1] = player;
            system("cls");
            DisplayBoard(chess_bord);
        }
        
    }
    else
    {
        system("cls");
        printf("Wrong Input,please enter again(x, y between 1 and 3)!\n");
        DisplayBoard(chess_bord);
        Change_chess_board(chess_bord, player);
    }
}

/**
 * @brief
 *
 * @param chess_bord The array of the chess board
 * @return int the winner
 *      0:nobody win
 *      1:player 1 wins
 *      2:player 2 wins
 */
int isWin(int chess_bord[3][3])
{
    int ret = 0;
    const int LENGTH = 3;
    int i = 0;

    for (i = 0; i < LENGTH; i++)
    {
        if (chess_bord[i][0] == chess_bord[i][1] && chess_bord[i][1] == chess_bord[i][2] && chess_bord[i][0] != 0)
            return ret = chess_bord[i][0];
        if (chess_bord[0][i] == chess_bord[1][i] && chess_bord[1][i] == chess_bord[2][i] && chess_bord[0][i] != 0)
            return ret = chess_bord[0][i];
        if (chess_bord[0][0] == chess_bord[1][1] && chess_bord[1][1] == chess_bord[2][2] && chess_bord[0][0] != 0)
            return ret = chess_bord[0][0];
        if (chess_bord[0][2] == chess_bord[1][1] && chess_bord[1][1] == chess_bord[2][0] && chess_bord[0][2] != 0)
            return ret = chess_bord[0][2];
    }

    return ret;
}
/**
 * @brief Dispalay the chess board according the array of chess board
 * 
 * @param chess_bord The array of the chess board
 */
void DisplayBoard(int chess_bord[3][3])
{
    // SetPos(0, 0);
    

    const int LENGTH = 3;
    int i = 0;
    printf("    1   2   3\n");
    printf("    ---------\n");
    for (i = 0; i < LENGTH; i++)
    {
        int j = 0;
        printf("%d |",i+1);
        for (j = 0; j < LENGTH; j++)
        {
            printf(" %d ", chess_bord[i][j]);
            if (j < LENGTH - 1)
                printf("|");
        }
        printf("|\n");
        if (i < LENGTH - 1)
        {
            printf("   ");
            for (j = 0; j < LENGTH; j++)
            {
                printf("---");
                if (j < LENGTH - 1)
                    printf("|");
            }
            printf("\n");
        }
    }
    printf("   --- --- ---\n");
}
/**
 * @brief Game engine ,run the tic tac toe game
 *
 * @return int the winner
 *      0:tie
 *      1:player 1 wins
 *      2:player 2 wins
 */
int game_engine()
{
    /**
     * winner means the winner of the tic_tac_toe
     * winner = 0 means tie
     * winner = 1 means 1p win
     * winner = 2 means 2p win
     */
    int winner = 0;
    /**
     * define a chess board
     * 0 means null 
     * 1 means 1p 's chess
     * 2 means 2p 's chess
     */
    int chess_bord[3][3] =
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
        };

    int step = 0;

    DisplayBoard(chess_bord);
    while (step != 8)
    {
        Change_chess_board(chess_bord, 1);
        if (isWin(chess_bord))
            return winner = isWin(chess_bord);
        Change_chess_board(chess_bord, 2);
        if (isWin(chess_bord))
            return winner = isWin(chess_bord);
        step += 2;
    }
    Change_chess_board(chess_bord, 1);
    if (isWin(chess_bord))
        return winner = isWin(chess_bord);

    return winner;
}

void main()
{
    int mode;
    int winner = 0;
    //print the startup screen
    printf("************************************\n");
    printf("**********   TicTacToe  ************\n");
    printf("********** 1:Game Start ************\n");
    printf("********** 2:   Quit    ************\n");
    printf("************************************\n");


    scanf("%d", &mode);
    switch (mode)
    {
    case 1:
        system("cls");
        winner = game_engine();
        printf("**********  GAME OVER!  ************\n");
        if (winner != 0)
            printf("     The Winner Is Player %d!\n",winner);
        else
            printf("         Tie!\n");
        break;

    default:
        //clear the terminal
        system("cls");
        printf("Goodbye!");
        break;
    }
    system("pause");
}