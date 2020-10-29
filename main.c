#include <stdio.h>
#include <stdlib.h>



 char square[10]  = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int choice, player;

    int checkForWin();
    void markBoard(char mark);
    void displayBoard();



int main()
{

    int gameStatus;
    char mark;
    player = 1;


    //this keeps loops till the game is over
    do
    {

       displayBoard();
       player = (player % 2) ? 1: 2;

       printf("player %d enter a number", player);
       scanf("%d",&choice);

       // set the X or O depending on the player either 1 or 2
       mark = (player == 1) ?  'X': 'O';

       // set based on  user choice
       markBoard(mark);

       gameStatus = checkForWin();
       player ++;
    }
    while(gameStatus == -1);

    if(gameStatus == 1)
        printf("==>\aPlayer %d wins", --player);
    else{
        printf("==>\aGame draw");
    }
    return 0;
}



/**************************************
Drawing the board for the tic tac toe
***************************************/

    void displayBoard()
    {
        // to clear the screen at all time the function is called
        system("cls");
         printf("\t Tic Tac Toe\n\n");

        printf("Player 1 (X) - Player 2 (O) \n\n\n");

        printf("   |    |   \n");
        printf(" %c |  %c |  %c\n", square[1],square[2],square[3]);

        printf(" __|____|___\n");
        printf("   |    |    \n");

        printf(" %c |  %c |  %c\n", square[4],square[5],square[6]);

        printf(" __|____|___\n");
        printf("   |    |    \n");

        printf(" %c |  %c |  %c\n", square[7],square[8],square[9]);
         printf("   |    |   \n\n");
    }

/******************************************
Setting the board with the correct character
 x and o in the correct spot in the array
****************************************/

void markBoard(char mark)
{
    // it checks what the player enters
    if (choice == 1 && square [1] == '1')
        square[1] = mark;

    else if (choice == 2 && square [2] == '2')
        square[2] = mark;

    else if (choice == 3 && square [3] == '3')
        square[3] = mark;

    else if (choice == 4 && square [4] == '4')
        square[4] = mark;

    else if (choice == 5 && square [5] == '5')
        square[5] = mark;

    else if (choice == 6 && square [6] == '6')
        square[6] = mark;

    else if (choice == 7 && square [7] == '7')
        square[7] = mark;

    else if (choice == 8 && square [8] == '8')
        square[8] = mark;

    else if (choice == 9 && square [9] == '9')
        square[9] = mark;

    else
        {
            printf("Invalid move\n  ");

            player--;

        }
}
/********************************
function that returns game status
 returns 1 if game over with result
 returns -1 if game is still on
 returns 0 if game is over with no result
*********************************/

int checkForWin()
{
    int returnValue = 0;
    //Checking if there is a match either in rows or column or diagonal
    if (square[1] == square[2] && square[2] == square[3])
    {
       returnValue = 1;
    }
   else if (square[4] == square[5] && square[5] == square[6])
    {
       returnValue = 1;
    }
   else if (square[7] == square[8] && square[8] == square[9])
    {
       returnValue= 1;
    }
  else if (square[1] == square[4] && square[4] == square[7])
    {
       returnValue = 1;
    }
  else if (square[2] == square[5] && square[5] == square[8])
    {
       returnValue = 1;
    }
  else if (square[3] == square[6] && square[6] == square[9])
    {
       returnValue = 1;
    }
   else if (square[1] == square[5] && square[5] == square[9])
    {
       returnValue = 1;
    }
   else if (square[3] == square[5] && square[5] == square[7])
    {
       returnValue = 1;
    }
   else if (
 square[1] != '1' && square[2] != '2'
 && square[3] != '3' && square[4] != '4'&&
 square[5] != '5' && square[6] != '6' && square[7] != '7' &&
  square[8] != '8' && square[9] != '9')
   {
      returnValue = 0;
   }


  else  {
            returnValue = -1;
        }
        return returnValue;
}

