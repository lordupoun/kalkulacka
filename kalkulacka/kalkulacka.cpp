// kalkulacka.cpp : Defines the entry point for the application.
//

#include "kalkulacka.h"

using namespace std;
//zjistit jak udelat pole ktere ma definovanou velikost az v programu (po nacteni hodnot)
//float misto int
//automaticke zjisteni velikosti matice

//Nacte aktualni matici

//Naplni vlozene pole rozmery matice od uzivatele
void nactiRozmer(int rozmer[2])
{
	scanf_s("%d %d", &rozmer[0], &rozmer[1]);
}
//Nacte od uzivatele matici
void nactiMatici(int matice[5][5], int Xmax, int Ymax) //nebo int (*matice[5])
{
	for (int y = 0; y < Ymax; y++)
	{
		for (int x = 0; x < Xmax; x++)
		{
			scanf_s(" %d", &matice[x][y]);
		}
	}
}
//Vypise zadanou matici
void vypisMatici(int matice[5][5], int Xmax, int Ymax)
{
	for (int y = 0; y < Ymax; y++) //vypis
	{
		for (int x = 0; x < Ymax; x++)
		{
			printf_s("%5d", matice[x][y]);
		}
		printf_s("\n");
	}
}
int main()
{
	
	int matice1[5][5];
	int rozmer1[2];
	int matice2[5][5];
	int rozmer2[2];
	printf_s("Zadejte rozmery 1. matice(AxB): ");
	nactiRozmer(rozmer1);
	printf_s("Zapiste 1. matici:\n");
	nactiMatici(matice1, rozmer1[0], rozmer1[1]);
	printf_s("Byla vlozena 1. matice ve tvaru: \n");
	vypisMatici(matice1, rozmer1[0], rozmer1[1]);

	printf_s("\nZadejte rozmery 2. matice(AxB): ");
	nactiRozmer(rozmer2);
	printf_s("Zapiste 2. matici:\n");
	nactiMatici(matice2, rozmer2[0], rozmer2[1]);
	printf_s("Byla vlozena 2. matice ve tvaru: \n");
	vypisMatici(matice2, rozmer2[0], rozmer2[1]);
	// je to správně? možnost přepsat řádek
	
	
	
	return 0;
}
//------
//FILE* soubor = fopen("matice.txt", "r"); //"r" - read
//ošetřit null
//char buffer[1024];
//while (fscanf(soubor, " %[^\n ]", buffer) != EOF) //co když %1023[^\n] //pri nalezeni znaku z [] vypise bez daneho znaku 
//{
//	if(0!=0)
//	{
//		printf("PRD");
//	}
//	printf("%s\n", buffer);
//	counter++;

//	
//}

//ošetřit zavírání
//-----------