// kalkulacka.cpp : Defines the entry point for the application.
//

#include "kalkulacka.h"
#include "funkce.h"
#include "ui.h"
#include "output.h"
#include <stdio.h>
#include <time.h>


using namespace std;
//zjistit jak udelat pole ktere ma definovanou velikost az v programu (po nacteni hodnot)
//TO DO:
//automaticke zjisteni velikosti matice

//Nacte aktualni matici
//odemknout pro tvorbu matic vetsich nez 5x5
//limit na 5x5
//nevypisovat cisla kdyz funkce nema reseni
//pridat %g pro determinant
//zmenit formatovani


int main()
{
	struct matice A;
	struct matice B;
	struct matice Final;
	int maticeCount;
	int operace;
	FILE* output = nullptr;
	double k;


	while (1) {
		switch (metoda()) {
		case 0:
			system("cls");
			return 0;
		case 1:
			maticeCount = zeSouboru(&A, &B);
			break;
		case 2:
			maticeCount = manualniInput(&A, &B);
			break;
		}

		time_t rawtime;
		struct tm* info;
		char name[28];
		time(&rawtime);
		info = localtime(&rawtime);
		strftime(name, 28, "output-%d-%m-%y-%H-%M-%s.txt", info);
		fopen_s(&output, name, "w");

		do {
			switch (maticeCount) {
			case -1:
				return -1;
			case 0:
				return -2;
			case 1:
				operace = operace_1();
				switch (operace) {
				case 0:
					break;
				case 1:
					outputDeterminant(output, &A, determinant(&A));
					break;
				case 2:
					transponovana(&A, &Final);
					outputTransponovana(output, &A, &Final);
					break;
				}
				break;
			case 2:
				operace = operace_2();
				switch (operace) {
				case 0:
					break;
				case 1:
					outputScitani(output, &A, &B, &Final, sectiMatice(&A, &B, &Final));
					vypisMatici(&Final);
					break;
				case 2:
					switch (vyberMatice_2(&A, &B, 45)) {
					case 1:
						outputOdcitani(output, &A, &B, &Final, odectiMatice(&A, &B, &Final));
						vypisMatici(&Final);
						break;
					case 2:
						outputOdcitani(output, &B, &A, &Final, odectiMatice(&B, &A, &Final));
						vypisMatici(&Final);
						break;
					}
					break;
				case 3:
					switch (vyberMatice_2(&A, &B, 120)) {
					case 1:
						outputNasobeniM(output, &A, &B, &Final, nasobMatice(&A, &B, &Final));
						vypisMatici(&Final);
						break;
					case 2:
						outputNasobeniM(output, &B, &A, &Final, nasobMatice(&B, &A, &Final));
						vypisMatici(&Final);
						break;
					}
					break;
				case 4:
					k = getCislo();
					switch (vyberMatice_1(&A, &B)) {
					case 1:
						nasobSkalarem(&A, k, &Final);
						vypisMatici(&Final);
						outputNasobeniS(output, &A, k, &Final);
						break;
					case 2:
						nasobSkalarem(&B, k, &Final);
						vypisMatici(&Final);
						outputNasobeniS(output, &B, k, &Final);
						break;
					}
					break;
				case 5:
					switch (vyberMatice_1(&A, &B)) {
					case 1:
						outputDeterminant(output, &A, determinant(&A));
						break;
					case 2:
						outputDeterminant(output, &B, determinant(&B));
						break;
					}
					break;
				case 6:
					switch (vyberMatice_1(&A, &B)) {
					case 1:
						transponovana(&A, &Final);
						outputTransponovana(output, &A, &Final);
						break;
					case 2:
						transponovana(&B, &Final);
						outputTransponovana(output, &B, &Final);
						break;
					}
					break;
				}
				break;
			}
			printf_s("\n");
			system("pause");
			fclose(output);
		} while (operace);
	}
}
