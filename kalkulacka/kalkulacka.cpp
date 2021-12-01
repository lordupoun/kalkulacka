// kalkulacka.cpp : Defines the entry point for the application.
//

#include "kalkulacka.h"
#include "funkce.h"
#include "ui.h"


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

	switch (maticeCount){
	case -1:
		return -1;
	case 0:
		return -2;
	case 1:
		switch (operace_1()) {
		case 1:
			determinant(&A);
			break;
		case 2:
			transponovana(&A, &Final);
			break;
		}
		break;
	case 2:
		switch (operace_2()) {
		case 1:
			sectiMatice(&A, &B, &Final);
			vypisMatici(&Final);
			break;
		case 2:
			switch (vyberMatice_2(&A,&B,45)) {
			case 1:
				odectiMatice(&A, &B, &Final);
				vypisMatici(&Final);
				break;
			case 2:
				odectiMatice(&B, &A, &Final);
				vypisMatici(&Final);
				break;
			}
			break;
		case 3:
			switch (vyberMatice_2(&A, &B, 120)) {
			case 1:
				nasobMatice(&A, &B, &Final);
				vypisMatici(&Final);
				break;
			case 2:
				nasobMatice(&B, &A, &Final);
				vypisMatici(&Final);
				break;
			}
			break;
		case 4:
			switch (vyberMatice_1(&A, &B)) {
			case 1:
				nasobSkalarem(&A, getCislo(), &Final);
				vypisMatici(&Final);
				break;
			case 2:
				nasobSkalarem(&B, getCislo(), &Final);
				vypisMatici(&Final);
				break;
			}
			break;
		case 5:
			switch (vyberMatice_1(&A, &B)) {
			case 1:
				determinant(&A);
				break;
			case 2:
				determinant(&B);
				break;
			}
			break;
		case 6:
			switch (vyberMatice_1(&A, &B)) {
			case 1:
				transponovana(&A, &Final);
				break;
			case 2:
				transponovana(&B, &Final);
				break;
			}
			break;
		}
		break;
	}

	printf_s("\n\n----------\n");
	return 0;
}
