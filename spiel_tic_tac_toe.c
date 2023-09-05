#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

// funktionen deklaration
void resetBoard();
void printBoard();
int checkFreeSpaces();
void player1Move();
void player2Move();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);
void printWinner2(char);




int main()
{
	char winner = ' ';
	char nochmal;
	int player = 0;
	
	printf("Wieviele Spieler? 1 oder 2 : ");
	scanf("%d", &player);
	
	if (player == 1)
	{
	
	do
	{
		winner = ' ';
		nochmal = ' ';
		resetBoard();
	
	while (winner == ' ' && checkFreeSpaces() != 0)
	{
		printBoard();		
		playerMove();
		winner = checkWinner();
		if(winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}
		computerMove();
		winner = checkWinner();
		if(winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}
	}
	printBoard();
	printWinner(winner);
	printf("Noch eine Runde (J)a (N)ein?: ");
	scanf("%c");
	scanf("%c", &nochmal);
	nochmal = toupper(nochmal);
	}
	while(nochmal == 'J');
	}
	else
	{
			do
	{
		winner = ' ';
		nochmal = ' ';
		resetBoard();
	
	while (winner == ' ' && checkFreeSpaces() != 0)
	{
		printBoard();		
		player1Move();
		winner = checkWinner();
		if(winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}
		printBoard();
		player2Move();
		winner = checkWinner();
		if(winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}
	}
	printBoard();
	printWinner2(winner);
	printf("Noch eine Runde (J)a (N)ein?: ");
	scanf("%c");
	scanf("%c", &nochmal);
	nochmal = toupper(nochmal);
	}
	while(nochmal == 'J');
	}
	
	
	return 0;
}

//funktionen initialisieren nach der main() wegen übersichtlichkeit oder auch nicht
void resetBoard()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void printBoard()
{
	printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
	printf("\n");
}
int checkFreeSpaces()
{
	int freeSpaces = 9;
	
	for(int i = 0; i < 3; i++)
	{
			for(int j = 0; j < 3; j++)
		{
			if(board[i][j] != ' ')
			{
				freeSpaces--;
			}
		}
	}
	return freeSpaces;
}
void playerMove()
{
	int x, y;
	
	do
	{
	printf("Welche Reihe (1-3)?: ");
	scanf("%d", &x);
	x--;
	printf("Welche Spalte (1-3)?: ");
	scanf("%d", &y);
	y--;
	
	if(board[x][y] != ' ')
	{
		printf("Leider schon belegt!\n");
	}
	else
	{
		board[x][y] = PLAYER;
		break;
	}
	
	}
	while (board[x][y] != ' ');
	
}
void computerMove()
{
	srand(time(0));
	int x, y;

		do
		{
			x = rand() % 3;
			y= rand() % 3;
		}
		while (board[x][y] != ' ');
		
		board[x][y] = COMPUTER;
	
}
void player1Move()
{
	int x, y;
	
	do
	{
	printf("Spieler %c - Welche Reihe (1-3)?: ", PLAYER1);
	scanf("%d", &x);
	x--;
	printf("Spieler %c - Welche Spalte (1-3)?: ", PLAYER1);
	scanf("%d", &y);
	y--;
	
	if(board[x][y] != ' ')
	{
		printf("Leider schon belegt!\n");
	}
	else
	{
		board[x][y] = PLAYER1;
		break;
	}
	
	}
	while (board[x][y] != ' ');
	
}
void player2Move()
{
	int x, y;
	
	do
	{
	printf("Spieler %c - Welche Reihe (1-3)?: ", PLAYER2);
	scanf("%d", &x);
	x--;
	printf("Spieler %c - Welche Spalte (1-3)?: ", PLAYER2);
	scanf("%d", &y);
	y--;
	
	if(board[x][y] != ' ')
	{
		printf("Leider schon belegt!\n");
	}
	else
	{
		board[x][y] = PLAYER2;
		break;
	}
	
	}
	while (board[x][y] != ' ');
	
}
char checkWinner()
{
	// erst die reihen anschauen
	for(int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	// jetzt die spalten
	for(int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	// jetzt diagonal
	for(int i = 0; i < 3; i ++)
	{
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
		{
			return board[0][0];
		}
	}	
	for(int i = 0; i < 3; i ++)
	{
		if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
		{
			return board[0][2];
		}
	}	
	return ' ';
}
void printWinner(char winner)
{
	if (winner == PLAYER)
	{
		printf("Gratuliere - Du hast gewonnen!\n");
	}
	else if (winner == COMPUTER)
	{
		printf("Schade - Der Computer hat gewonnen!\n");
	}
	else printf("Unentschieden!\n");
}
void printWinner2(char winner)
{
	if (winner == PLAYER1)
	{
		printf("Spieler %c hat gewonnen!\n", PLAYER1);
	}
	else if (winner == PLAYER2)
	{
		printf("Spieler %c hat gewonnen!\n", PLAYER2);
	}
	else printf("Unentschieden!\n");
}