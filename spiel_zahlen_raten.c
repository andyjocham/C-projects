#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>



int main()
{
	const int MIN = 1;
	const int MAX = 100;
	int tip, antwort;
	int anzahl =  0;

	srand(time(0));
	
	antwort = rand() % MAX + MIN;


	
	do
	{
		printf("Gib eine Zahl zwischen %d und %d ein: ", MIN, MAX);
		scanf("%d", &tip);
		if (tip > antwort)
		{
			printf("A weng weniger...\n");
		}
		else if (tip < antwort)
		{
			printf("A weng mehr...\n");
		}
		else
		{
			printf("Richtig!!...\n");
		}
		anzahl++;
		
		if (anzahl > 19)
		{	
			printf("\n\nDu hast %d Versuche verbraucht, %d waere die richtige Antwort gewesen", anzahl, antwort);
			break;
		}
	}
	while(tip != antwort);
	
	anzahl < 19 ? printf("\n\nGratuliere, %d ist die richtige Antwort, du hast %d Versuche gebraucht ", antwort, anzahl):0;
	
	return 0;
}