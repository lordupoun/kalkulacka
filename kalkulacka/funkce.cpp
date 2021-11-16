#include "funkce.h"
#include <stdio.h>

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
	//vnoøit do sebe funkce a dát tam opakovací pøetížení -pøidat if do pøechozí funkce, a pøidat (, int cislo);
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
	if (stejnytypMatice(max1, max2) == 1)
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
//Odecte zadane matice
void odectiMatice(int Matice1[5][5], int Matice2[5][5], int final[5][5], int max1[2], int max2[2])
{
	int stejnytypMatice(int max1[2], int max2[2]);
	if (stejnytypMatice(max1, max2) == 1)
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
//vynasobi matici skalarem
void nasobSkalarem(int cislo, int matice[5][5], int final[5][5], int max[2])
{
	for (int y = 0; y < max[1]; y++)
	{
		for (int x = 0; x < max[0]; x++)
		{
			final[x][y] = matice[x][y]*cislo;
		}
	}
}