#include "funkce.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//#define Xsloupce 0
//#define Yradky 1

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
			printf_s("%8g", a->hodnoty[x][y]);
		}
		printf_s("\n");
	}
	
}
int stejnytypMatice(struct matice* a, struct matice* b)
{
	if (a->Xrozmer != b->Xrozmer || a->Yrozmer != b->Yrozmer)
	{
		system("cls");
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
	system("cls");
	printf_s("Soucet matic je:\n\n");
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
	system("cls");
	printf_s("Rozdil matic je:\n\n");
	}
}
//vynasobi matici skalarem
void nasobSkalarem(struct matice* a, double skalar, struct matice* c)
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
	printf_s("Matice vynasobena cislem %.2lf:\n\n", skalar);
}
//vynasobi matice M1*M2 - pozor neni komutativni
void nasobMatice(struct matice* a, struct matice* b, struct matice* c) //doplnit nuly
{ 
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
			for (int d = 0; d < a->Yrozmer; d++) 
			{
				for (int h = 0; h < a->Yrozmer; h++)
				{					//  x  y       x  y       x  y
					c->hodnoty[d][h] = c->hodnoty[d][h] + a->hodnoty[j][h] * b->hodnoty[d][j];
				}
			}
		}
		c->Xrozmer = b->Xrozmer;//pocet x ve finalnim rozmeru stejny jako pocet x v druhe matici
		c->Yrozmer = a->Yrozmer;//pocet y ve finalnim rozmeru stejny jako pocet y v druhe matici

		system("cls");
		printf_s("Vynasobena matice:\n\n");
	}
	else
	{
		system("cls");
		printf_s("Matice nelze nasobit. \n");
	}
}
void determinant(struct matice* a) //obecne i pro 5x5	B-)
{
	if (a->Xrozmer == a->Yrozmer)
	{
		struct matice c = *a;
		double d;
		double swap;
		for (int i = 0; i < c.Xrozmer; i++) {
			for (int y = i+1; y < c.Yrozmer; y++) {
				if (c.hodnoty[i][i] == 0) { //ZAMEMENI RADKU ZA NASLEDUJICI
					for (int j = i; j < c.Xrozmer; j++) {
						swap = c.hodnoty[j][i];
						c.hodnoty[j][i] = c.hodnoty[j][i + 1];
						c.hodnoty[j][i + 1] = swap*(-1);
					}
				}
				d = c.hodnoty[i][y] / c.hodnoty[i][i];
				for (int x = i; x < c.Xrozmer; x++) {
					c.hodnoty[x][y] = (c.hodnoty[x][y] - (d * c.hodnoty[x][i]));
				}
			}
		}
		double det = 1;
		for (int x = 0; x < c.Xrozmer; x++) {
 			det *= c.hodnoty[x][x];
		}
		system("cls");
		printf_s("Determinant matice: %.3lf", det);
	}
	else
	{
		system("cls");
		printf_s("Matice neni ctvercova!\n");
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
	system("cls");
	printf_s("Transponovana matice je:\n\n");
	vypisMatici(c);
}

int manualniInput(struct matice* a, struct matice* b) {
	int count;
	do {
		system("cls");
		printf_s("Zadejte pocet matic (1/2):");
		scanf_s("%d", &count);
	} while (count != 1 && count != 2);

	printf_s("Zadejte rozmery 1. matice (format: mxn - radkyXsloupce): ");
	nactiRozmer(a);
	printf_s("Zapiste 1. matici:\n");
	nactiMatici(a);
	printf_s("Byla vlozena 1. matice ve tvaru: \n");
	vypisMatici(a);

	if (count == 2) {
		printf_s("\nZadejte rozmery 2. matice(mn): ");
		nactiRozmer(b);
		printf_s("Zapiste 2. matici:\n");
		nactiMatici(b);
		printf_s("Byla vlozena 2. matice ve tvaru: \n");
		vypisMatici(b);
	}
	return count;
}

int zeSouboru(struct matice* a, struct matice* b) {
	//Return table
	//
	//-2 = Moc velka matice
	//-1 = Nenasel se soubor
	// 1 = Jedna matice
	// 2 = Dve matice
	//

	FILE* input;
	fopen_s(&input, "input.txt", "r");
	if (input == NULL) {
		perror("Chyba pri cteni ze souboru");
		return -1;
	}
	int p;
	int x = 0;
	int y = 0;
	int xMax = 0;
	int newLine = 0;

	for (int i = 0; i < 5; i++) {		//VYNULOVÁNÍ ÈLENÙ MATICE 
		for (int j = 0; j < 5; j++) {	// (pro pøípad neúplného zapsaní matice, napø. (1 2 3 | 4 5 | 7 8 9),
			a->hodnoty[i][j] = 0;		// nyní bude (1 2 3 | 4 5 0 | 7 8 9)
			b->hodnoty[i][j] = 0;		// namísto (1 2 3 | 4 5 -DBL_MAX | 7 8 9)
		}
	}

	while (1) { //MATICE 1
		p = fgetc(input);
		if (p == 32) { //MEZERA
			x++;
			newLine = 0;
		}
		else if (p == 10) { //LINE FEED (NOVY RADEK)
			if (newLine == 1) break;
			newLine++; //pokud jsou za sebou dva znaky noveho radku -> konec 1. matice
			y++;
			if (x > xMax) xMax = x;
			x = 0;
			}
		else if (p >= 48 && p <= 57) { //CISLO
 			fseek(input, -1, SEEK_CUR);
			fscanf_s(input, "%lf", &a->hodnoty[x][y]);
			newLine = 0;
		}
		else if (p == EOF) { //KONEC SOUBORU
			printf_s("Byla nalezena jen jedna matice.\n");
			a->Xrozmer = xMax+1;
			a->Yrozmer = y+1;
			fclose(input);
			return 1;
		}

		if (x > 5 || y > 5) { //OMEZENI VELIKOSTI MATICE
			printf_s("Matice 1 presahuje povolene rozmery 5x5.\n");
			fclose(input);
			return 3;
		}
	}
	a->Xrozmer = xMax+1;
	a->Yrozmer = y;
	x = 0; y = 0; xMax = 0;

	do { //MATICE 2
		p = fgetc(input);
		if (p == 32) { //MEZERA
			x++;
		}
		else if (p == 10) { //LINE FEED
			y++;
			if (x > xMax) xMax = x;
			x = 0;
		}
		else if (p >= 48 && p <= 57) { //CISLO
			fseek(input, -1, SEEK_CUR);
			fscanf_s(input, "%lf", &b->hodnoty[x][y]);
		}

		if (x > 5 || y > 5) { //OMEZENI VELIKOSTI MATICE
			printf_s("Matice 2 presahuje povolene rozmery 5x5.\n");
			fclose(input);
			return 3;
		}
	} while (feof(input)==0);
	b->Xrozmer = xMax+1;
	b->Yrozmer = y+1;
	fclose(input);
	return 2;
}

#pragma region OLD_VER

#pragma endregion