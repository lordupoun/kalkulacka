#include "funkce.h"
#include <stdio.h>

#define Xsloupce 0
#define Yradky 1 //zamenit max a rozmer

void inicializuj(struct matice *a)
{
	a->Xrozmer = 0;
	a->Yrozmer = 0;
for(int y = 0; y < 5; y++)
{
	for (int x = 0; x < 5; x++)
	{
		a->hodnoty[x][y]=0;
	}
}
}

//Naplni vlozene pole rozmery matice od uzivatele
void nactiRozmer(struct matice* a)
{
	scanf_s("%d %d", &a->Xrozmer, &a->Yrozmer);
}
//Nacte od uzivatele matici
void nactiMatici(struct matice* a) //nebo int (*matice[5])
{
	for (int y = 0; y < a->Yrozmer; y++)
	{
		for (int x = 0; x < a->Xrozmer; x++)
		{
			scanf_s(" %lf", &a->hodnoty[x][y]);
		}
	}
}
//Vypise zadanou matici
void vypisMatici(struct matice* a)
{
	for (int y = 0; y < a->Yrozmer; y++) //vypis
	{
		for (int x = 0; x < a->Xrozmer; x++)
		{
			printf_s("%5g", a->hodnoty[x][y]);
		}
		printf_s("\n");
	}
	//vnoøit do sebe funkce a dát tam opakovací pøetížení -pøidat if do pøechozí funkce, a pøidat (, int cislo);
}
int stejnytypMatice(struct matice* a, struct matice* b)
{
	if (a->Xrozmer != b->Xrozmer || a->Yrozmer != b->Yrozmer)
	{
		printf_s("Nelze scitat - matice nejsou stejneho typu\n");
		return 1;
	}
	return 0;
}
//secte matice
void sectiMatice(struct matice* a, struct matice* b, struct matice* c)
{
	if (stejnytypMatice(a, b) == 1)
	{

	}
	else
	{
		c->Xrozmer = a->Xrozmer;
		c->Yrozmer = a->Yrozmer;
		for (int y = 0; y < a->Yrozmer; y++)
		{
			for (int x = 0; x < a->Xrozmer; x++)
			{
				c->hodnoty[x][y] = a->hodnoty[x][y] + b->hodnoty[x][y];
			}
		}
	}
}
//Odecte zadane matice
void odectiMatice(struct matice* a, struct matice* b, struct matice* c)
{
	if (stejnytypMatice(a, b) == 1)
	{

	}
	else
	{
		c->Xrozmer = a->Xrozmer;
		c->Yrozmer = a->Yrozmer;
		for (int y = 0; y < a->Yrozmer; y++)
		{
			for (int x = 0; x < a->Xrozmer; x++)
			{
				c->hodnoty[x][y] = a->hodnoty[x][y] - b->hodnoty[x][y];
			}
		}
	}
}
//vynasobi matici skalarem
void nasobSkalarem(struct matice* a, int skalar, struct matice* c)
{
	c->Xrozmer = a->Xrozmer;
	c->Yrozmer = a->Yrozmer;
	for (int y = 0; y < a->Yrozmer; y++)
	{
		for (int x = 0; x < a->Xrozmer; x++)
		{
			c->hodnoty[x][y] = a->hodnoty[x][y]*skalar;
		}
	}
}
//vynasobi matice M1*M2 - pozor neni komutativni
void nasobMatice(struct matice* a, struct matice* b, struct matice* c) //doplnit nuly
{ //nasobeni matic musi byt ulozeno do jineho pole, jinak se bude prepisovat --- zarid smazani
	if (a->Xrozmer == b->Yrozmer)
	{
		for (int y = 0; y < 5; y++) //nulovani
		{
			for (int x = 0; x < 5; x++)
			{
				c->hodnoty[x][y] = 0;
			}
		}
		for (int j = 0; j < a->Xrozmer; j++) //pravidlo o velikosti proto dokud neskonci rozmer matice (stejne se nasobi kazdy s kazdym, jinak by to nevyslo)
		{
			for (int d = 0; d < a->Yrozmer; d++) //drive max2[1]
			{
				for (int h = 0; h < a->Yrozmer; h++)
				{					//  x  y       x  y       x  y
					c->hodnoty[d][h] = c->hodnoty[d][h] + a->hodnoty[j][h] * b->hodnoty[d][j];
				}
			}
		}
		c->Xrozmer = b->Xrozmer;//pocet x ve finalnim rozmeru stejny jako pocet x v druhe matici
		c->Yrozmer = a->Yrozmer;//pocet y ve finalnim rozmeru stejny jako pocet y v druhe matici
	}
	else
	{
		printf_s("Matice nelze nasobit. \n");
	}
}
void determinant(struct matice* a) //lze optimalizovat, mozna se na to kouknout
{
	if (a->Xrozmer == a->Yrozmer)
	{
		if (a->Xrozmer == 1)
		{
			printf_s("Determinant = %lf \n", a->hodnoty[0][0]);
		}
		else if (a->Xrozmer == 2)
		{
			printf_s("Determinant = %lf \n", (a->hodnoty[0][0] * a->hodnoty[1][1]) - (a->hodnoty[1][0] * a->hodnoty[0][1]));
		}
		else if (a->Xrozmer == 3)
		{
			printf_s("Determinant = %lf \n", (a->hodnoty[0][0] * a->hodnoty[1][1]* a->hodnoty[2][2])+ (a->hodnoty[0][1] * a->hodnoty[1][2] * a->hodnoty[2][0])+ (a->hodnoty[0][2] * a->hodnoty[1][0] * a->hodnoty[2][1]) - (a->hodnoty[2][0] * a->hodnoty[1][1]* a->hodnoty[0][2])- (a->hodnoty[2][1] * a->hodnoty[1][2] * a->hodnoty[0][0])- (a->hodnoty[2][2] * a->hodnoty[1][0] * a->hodnoty[0][1]));
		}
		else if (a->Xrozmer == 4)
		{
			//dodelat
		}
		else
		{
			printf_s("Program pocita determinant matice ve formatu nejvyse 4x4 \n");
		}
	}
	else
	{
		printf_s("Matice neni ctvercova! \n");
	}
}
void transponovana(struct matice* a, struct matice* c)
{
	for (int y = 0; y < a->Yrozmer; y++)
	{
		for (int x = 0; x < a->Xrozmer; x++)
		{
			c->hodnoty[y][x] = a->hodnoty[x][y]; //opacne souradnice nefunguji
		}
		c->Xrozmer = a->Yrozmer;
		c->Yrozmer = a->Xrozmer;
	}

	
	/*int vetsiRozmer; //bude se delat asi i pro hodnoty co nejsou naplnene
	if (max[0] > max[1])
	{
		vetsiRozmer = max[0];
	}
	else 
	{
		vetsiRozmer = max[1];
	}
	for (int i = 0; i < vetsiRozmer*vetsiRozmer; i++)
	{
		final[i]
	}*/
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