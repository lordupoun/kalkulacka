#include "funkce.h"
#include <stdio.h>

#define Xsloupce 0
#define Yradky 1 //zamenit max a rozmer

//Naplni vlozene pole rozmery matice od uzivatele
void nactiRozmer(int rozmer[2])
{
	scanf_s("%d %d", &rozmer[1], &rozmer[0]);
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
//vynasobi matice M1*M2 - pozor neni komutativni
void nasobMatice(int M1[5][5], int M2[5][5], int final[5][5], int max1[2], int max2[2], int finalRozmer[2]) //doplnit nuly
{ //nasobeni matic musi byt ulozeno do jineho pole, jinak se bude prepisovat --- zarid smazani
	if (max1[0] == max2[1])
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				final[x][y] = 0;
			}
		}
		for (int c = 0; c < max1[0]; c++) //pravidlo o velikosti proto dokud neskonci rozmer matice (stejne se nasobi kazdy s kazdym, jinak by to nevyslo)
		{
			for (int d = 0; d < max1[0]; d++) //drive max2[1]
			{
				for (int h = 0; h < max1[0]; h++)
				{
					final[d][h] = final[d][h] + M1[c][h] * M2[d][c];
				}
			}
		}
		finalRozmer[0] = max2[0];//pocet x ve finalnim rozmeru stejny jako pocet x v druhe matici
		finalRozmer[1] = max1[1];//pocet y ve finalnim rozmeru stejny jako pocet y v druhe matici
	}
	else
	{
		printf("Matice nelze nasobit. \n");
	}
}
		/*



		for (int y = 0; y < max1[1]; y++)
		{
			for (int x = 0; x < max2[0]; x++)
			{
				//final[x][y] = Matice1[0][0]*Matice2[0][0]+Matice1[1][0]*Matice2[0][1]+Matice1[2][0]*Matice2[0][2];
				for (int c = 0; c < max1[2]; c++)
				{		//x  y
					final[0][0] = final[0][0] + M1[c][0] * M2[0][c];
					final[1][0] = final[1][0] + M1[c][0] * M2[1][c];
					final[2][0] = final[2][0] + M1[c][0] * M2[2][c];
					//-----------------------------------------------
					final[0][1] = final[0][1] + M1[c][1] * M2[0][c];
					final[1][1] = final[1][1] + M1[c][1] * M2[1][c];
					final[2][1] = final[2][1] + M1[c][1] * M2[2][c];
					//-----------------------------------------------
					final[0][2] = final[0][2] + M1[c][2] * M2[0][c];
					final[1][2] = final[1][2] + M1[c][2] * M2[1][c];
					final[2][2] = final[2][2] + M1[c][2] * M2[2][c];
				}
				final[c][0] = final[c][0] + M1[c][0] * M2[c][c];
				final[c][1] = final[c][1] + M1[c][1] * M2[c][c];
				final[c][2] = final[c][2] + M1[c][2] * M2[c][c];
				
				//final[x][y] = final[x][y] + M1[1][0]*M2[0][1]
				//+M1[2][0]*M2[0][2]
			}//první krát první, druhej krát druhej, tøetí krát tøetí
		}
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			final[x][y] = 0;
		}
	}
		//for(int d=0; d<;d++)
	//for (int d = 0; d < max2[0]; d++)
	//{
			for (int c = 0; c < max1[1]; c++)
			{		//x  y
				/*final[0][0] = final[0][0] + M1[c][0] * M2[0][c];
				final[1][0] = final[1][0] + M1[c][0] * M2[1][c];
				final[2][0] = final[2][0] + M1[c][0] * M2[2][c];
				//-----------------------------------------------
				final[0][1] = final[0][1] + M1[c][1] * M2[0][c];
				final[1][1] = final[1][1] + M1[c][1] * M2[1][c];
				final[2][1] = final[2][1] + M1[c][1] * M2[2][c];
				//-----------------------------------------------
				final[0][2] = final[0][2] + M1[c][2] * M2[0][c];
				final[1][2] = final[1][2] + M1[c][2] * M2[1][c];
				final[2][2] = final[2][2] + M1[c][2] * M2[2][c];
				//---------------
				for(int d=0; d<max2[0]; d++)
				{ 
					for (int h = 0; h < max1[1]; h++)
					{ 
						final[d][h] = final[d][h] + M1[c][h] * M2[d][c];
				/*final[d][0] = final[d][0] + M1[c][0] * M2[d][c];
				final[d][1] = final[d][1] + M1[c][1] * M2[d][c];
				final[d][2] = final[d][2] + M1[c][2] * M2[d][c];
					}
				}
					//final[c][d] = final[c][d] + M1[c][d] * M2[c][c];
			}
				//final[c][d] = final[c][d] + M1[c][d]*M2[d][c]
	//}
	*/

//prvni matice urcuje pocet radku, druha pocet sloupcu finalni
//moznosti: 1) doplnit nuly, bude se vykonavat hodne zbytecneho nasobeni
//2) zapodminkovat
//---- rozmyslet dopad pri velkych maticich
/*				final[0][0] = final[0][0] + M1[c][0] * M2[0][c];
				final[1][0] = final[1][0] + M1[c][0] * M2[1][c];
				final[2][0] = final[2][0] + M1[c][0] * M2[2][c];
				//-----------------------------------------------
				final[0][1] = final[0][1] + M1[c][1] * M2[0][c];
				final[1][1] = final[1][1] + M1[c][1] * M2[1][c];
				final[2][1] = final[2][1] + M1[c][1] * M2[2][c];
				//-----------------------------------------------
				final[0][2] = final[0][2] + M1[c][2] * M2[0][c];
				final[1][2] = final[1][2] + M1[c][2] * M2[1][c];
				final[2][2] = final[2][2] + M1[c][2] * M2[2][c];*/
//pøiète jednièku tolikrát, kolikrát je velká matice