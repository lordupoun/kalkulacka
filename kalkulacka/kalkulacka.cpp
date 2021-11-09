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
void nactiMatici(int matice[5][5], int max[2]) //nebo int (*matice[5])
{
	for (int y = 0; y < max[1]; y++)
	{
		for (int x = 0; x < max[0]; x++)
		{
			scanf_s(" %d", &matice[x][y]);
		}
	}
}
//Vypise zadanou matici
void vypisMatici(int matice[5][5], int max[2])
{
	for (int y = 0; y < max[1]; y++) //vypis
	{
		for (int x = 0; x < max[0]; x++)
		{
			printf_s("%5d", matice[x][y]);
		}
		printf_s("\n");
	}
	//vnořit do sebe funkce a dát tam opakovací přetížení -přidat if do přechozí funkce, a přidat (, int cislo);
}
int stejnytypMatice(int max1[2], int max2[2])
{
	if (max1[0] != max2[0] || max1[1] != max2[1])
	{
		printf("Nelze scitat - matice nejsou stejneho typu");
		return 1;
	}
	return 0;
}
//secte matice
void sectiMatice(int Matice1[5][5], int Matice2[5][5], int final[5][5], int max1[2], int max2[2])
{
	if(stejnytypMatice(max1, max2)==1)
	{
		
	}
	else
	{ 
		for (int y = 0; y < max1[1]; y++)
		{
			for (int x = 0; x < max1[0]; x++)
			{
				final[x][y] = Matice1[x][y] + Matice2[x][y];
			}
		}
	}
}
void odectiMatice(int Matice1[5][5], int Matice2[5][5], int final[5][5], int max1[2], int max2[2])
{
	int stejnytypMatice(int max1[2], int max2[2]);
	if(stejnytypMatice(max1, max2) == 1)
	{
	
	}
	else
	{
		for (int y = 0; y < max1[1]; y++)
		{
			for (int x = 0; x < max1[0]; x++)
			{
				final[x][y] = Matice1[x][y] - Matice2[x][y];
			}
		}
	}
}
int main()
{
	
	int matice1[5][5];
	int rozmer1[2];
	int matice2[5][5];
	int rozmer2[2];
	int maticeFinal[5][5];
	printf_s("Zadejte rozmery 1. matice (format: m n): ");
	nactiRozmer(rozmer1);
	printf_s("Zapiste 1. matici:\n");
	nactiMatici(matice1, rozmer1);
	printf_s("Byla vlozena 1. matice ve tvaru: \n");
	vypisMatici(matice1, rozmer1);

	printf_s("\nZadejte rozmery 2. matice(mn): ");
	nactiRozmer(rozmer2);
	printf_s("Zapiste 2. matici:\n");
	nactiMatici(matice2, rozmer2);
	printf_s("Byla vlozena 2. matice ve tvaru: \n");
	vypisMatici(matice2, rozmer2);
	// je to správně? možnost přepsat řádek
	//switch pro vyber
	//------scitani
	//for(matice)
	sectiMatice(matice1, matice2, maticeFinal, rozmer1, rozmer2);
	vypisMatici(maticeFinal, rozmer2);
	odectiMatice(matice1, matice2, maticeFinal, rozmer1, rozmer2);
	vypisMatici(maticeFinal, rozmer2);
	
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