// kalkulacka.cpp : Defines the entry point for the application.
//

#include "kalkulacka.h"
#include "funkce.h"
#include "ui.h"


using namespace std;
//zjistit jak udelat pole ktere ma definovanou velikost az v programu (po nacteni hodnot)
//TO DO:
//float misto int
//automaticke zjisteni velikosti matice

//Nacte aktualni matici
//done-struct
//ify zmackni s pro scitani
//done-finalRozmer pro vsechny funkce
//odemknout pro tvorbu matic vetsich nez 5x5
//limit na 5x5
//nevypisovat cisla kdyz funkce nema reseni
//pridat %g pro determinant
//zmenit formatovani


int main()
{
	//šlo by dát do structu
	struct matice A;
	struct matice B;
	struct matice Final;
	int maticeCount;
	int operace;
	//int matice1[5][5];
	//int rozmer1[2]; //[0] - x; [1] -y
	//int matice2[5][5];
	//int rozmer2[2];
	//int maticeFinal[5][5];
	//int rozmerFinal[2];

	// je to správně? možnost přepsat řádek
	////switch pro vyber
	////------scitani
	////for(matice)

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
	

	//sectiMatice(&A, &B, &Final);
	//printf_s("Soucet matic: \n");
	//vypisMatici(&Final);
	//odectiMatice(&A, &B, &Final);
	//printf_s("Rozdil matic: \n");
	//vypisMatici(&Final);
	//printf_s("Nasobeni skalarem: \n");
	//nasobSkalarem(&A, cislo, &Final);
	//vypisMatici(&Final); //maticeFinal.rozmer
	//printf_s("Nasobeni M1xM2: \n");
	//nasobMatice(&A, &B, &Final);
	//vypisMatici(&Final);
	//printf_s("Determinant: \n");
	//determinant(&A); //slo by hodit returnem
	//printf_s("Transponovana matice: \n");
	//transponovana(&A, &Final);
	//vypisMatici(&Final); //rozmer je stejny jako puvodni rozmer



	
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

/*while (uzivatel nezmackne enter)
{
	pocitadlo;
	scanf_s("%d", &rozmer[0], &rozmer[1]);
}
*/