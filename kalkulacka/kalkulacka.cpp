// kalkulacka.cpp : Defines the entry point for the application.
//

#include "kalkulacka.h"

using namespace std;
//zjistit jak udelat pole ktere ma definovanou velikost az v programu (po nacteni hodnot)
//float misto int

int main()
{
	int hodnoty[5][5];
	for(int y = 0; y < 5; y++)
	{ 
		for (int x = 0; x < 5; x++)
		{
			scanf("%d", &hodnoty[x][y]);
			//přidat reset funkci
			printf(" ");
		}
		printf("\n");
	}
	//--------------------------------------
	for (int y = 0; y < 5; y++) //vypis
	{
		for (int x = 0; x < 5; x++)
		{
			printf("%5d", hodnoty[x][y]);
		}
		printf("\n");
	}
	
	
	return 0;
}
