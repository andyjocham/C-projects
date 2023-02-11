#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>



int main()
{
char playerChoice[10];
char nochmal[5];
char *compChoice;
int pwins = 0, cwins = 0, unentschieden = 0;

while(1)
{
	do
	{
	printf("\n\nStein, Schere oder Papier? : ");
	fgets(playerChoice, sizeof(playerChoice), stdin);
	playerChoice[strcspn(playerChoice, "\n")] = 0;
	strlwr(playerChoice);
	playerChoice[0] -= 32;
	if(strcmp(playerChoice, "Stein") != 0 && strcmp(playerChoice, "Schere") != 0 && strcmp(playerChoice, "Papier") != 0 )
	{
		printf("\nUngueltige Eingabe!");
	}
	}
	while(strcmp(playerChoice, "Stein") != 0 && strcmp(playerChoice, "Schere") != 0 && strcmp(playerChoice, "Papier") != 0 );

srand(time(0));
switch (rand() % 3)
{
	case 0:
	compChoice = "Stein";
	break;
	case 1:
	compChoice = "Schere";
	break;
	case 2:
	compChoice = "Papier";
	break;
}


if(strcmp(playerChoice, compChoice) == 0)
{
	printf("\nComputer nimmt %s - Unentschieden", compChoice);
	unentschieden++;
}
else if(strcmp(playerChoice, "Stein") == 0 && (strcmp(compChoice, "Schere") == 0 || (strcmp(playerChoice, "Schere") == 0 && (strcmp(compChoice, "Papier")== 0  || (strcmp(playerChoice, "Papier") == 0 && (strcmp(compChoice, "Stein") == 0))))))
{
	printf("\nComputer nimmt %s - Du hast gewonnen!", compChoice);
	pwins++;
}
else
{
	printf("\nComputer nimmt %s - Du hast verloren!", compChoice);
	cwins++;
}

printf("\n\nDeine Punkte: %d - Computer Punkte: %d - Unentschieden: %d",pwins, cwins, unentschieden);
printf("\n--------------------------------------------------------");
}
	return 0;
}