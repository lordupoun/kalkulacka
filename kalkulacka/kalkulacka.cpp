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
	int returnVal;
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
		char name[50]; //max filename size?
		time(&rawtime);
		info = localtime(&rawtime);
		//strftime(name, 28, "%d.%m.%y_%H.%M.%S.txt", info); //nesmi byt moc dlouhy
		strftime(name, 28, "output-%d%m%y_%H%M%S.txt", info);
		fopen_s(&output, name, "w");
		//fopen_s(&output, "output.txt", "w");

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
					returnVal = sectiMatice(&A, &B, &Final);
					outputScitani(output, &A, &B, &Final, returnVal);
					if(returnVal==0)
					{
					vypisMatici(&Final);
					}
					break;
				case 2:
					switch (vyberMatice_2(&A, &B, 45)) {
					case 1:
						returnVal = odectiMatice(&A, &B, &Final);
						outputOdcitani(output, &A, &B, &Final, returnVal);
						if (returnVal == 0)
						{
							vypisMatici(&Final);
						}
						break;
					case 2:
						returnVal = odectiMatice(&B, &A, &Final);
						outputOdcitani(output, &B, &A, &Final, returnVal);
						if (returnVal == 0)
						{
							vypisMatici(&Final);
						}
						break;
					}
					break;
				case 3:
					switch (vyberMatice_2(&A, &B, 120)) {
					case 1:
						returnVal = nasobMatice(&A, &B, &Final);
						outputNasobeniM(output, &A, &B, &Final, returnVal);
						if (returnVal == 0)
						{
							vypisMatici(&Final);
						}
						break;
					case 2:
						returnVal = nasobMatice(&B, &A, &Final);
						outputNasobeniM(output, &B, &A, &Final, returnVal);
						if (returnVal == 0)
						{
							vypisMatici(&Final);
						}
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
		} while (operace);
		fclose(output);
	}
}
