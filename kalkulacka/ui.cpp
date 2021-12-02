#include "ui.h"
#include "funkce.h"
#include <stdio.h>
#include <stdlib.h>

int metoda() {
	int a;
	do {
		system("cls");
		printf_s("Vyberte metodu zadani matice:\n\n[1]\tZe souboru (soubor input.txt)\n[2]\tManualne\n\n[0]\tUkoncit program\n\n> ");
		scanf_s("%d", &a);
	} while (a < 0 || a > 2);
	return a;
}

int operace_1() {
	int a;
	do {
		system("cls");
		printf_s("Vyberte operaci:\n\n[1]\tDeterminant matice\n[2]\tTransponovana matice\n\n[0]\tZpet\n\n> ");
		scanf_s("%d", &a);
	} while (a < 0 || a>2);
	return a;
}

int operace_2() {
	int a;
	do {
		system("cls");
		printf_s("Vyberte operaci:\n\n[1]\tScitani matic\n[2]\tOdecitani matic\n[3]\tNasobeni matice\n[4]\tNasobeni skalarem\n[5]\tDeterminant matice\n[6]\tTransponovana matice\n\n[0]\tZpet\n\n> ");
		scanf_s("%d", &a);
	} while (a < 0 || a>6);
	return a;
}

int vyberMatice_1(matice* a, matice* b){
	int m;
	do {
		system("cls");
		printf_s("Vyberte matici:\n\n[1]\n\n");
		vypisMatici(a);
		printf_s("\n\n[2]\n\n");
		vypisMatici(b);
		printf_s("\n\n> ");
		scanf_s("%d", &m);
	} while (m != 1 && m != 2);
	return m;
}

int vyberMatice_2(matice* a, matice* b, char op) {
	int m;
	do {
		system("cls");
		printf_s("Vyberte poradi matic v operaci:\n\nA\n\n");
		vypisMatici(a);
		printf_s("\n\nB\n\n");
		vypisMatici(b);
		printf_s("\n\n[1]\tA %c B\n[2]\tB %c A\n\n> ", op, op);
		scanf_s("%d", &m);
	} while (m != 1 && m != 2);
	return m;
}

double getCislo()
{
	double a;
	system("cls");
	printf_s("Vlozte koeficient nasobeni: ");
	scanf_s("%lf", &a);
	return a;
}
