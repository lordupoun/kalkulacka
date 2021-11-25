// kalkulacka.cpp : Defines the entry point for the application.
//

#include "kalkulacka.h"
#include "funkce.h"


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


int main()
{
	//šlo by dát do structu
	struct matice A;
	struct matice B;
	struct matice Final;
	int cislo = 5;
	//int matice1[5][5];
	//int rozmer1[2]; //[0] - x; [1] -y
	//int matice2[5][5];
	//int rozmer2[2];
	//int maticeFinal[5][5];
	//int rozmerFinal[2];

	printf_s("Zadejte rozmery 1. matice (format: mxn - radkyXsloupce): ");
	nactiRozmer(&A);
	printf_s("Zapiste 1. matici:\n");
	nactiMatici(&A);
	printf_s("Byla vlozena 1. matice ve tvaru: \n");
	vypisMatici(&A);

	printf_s("\nZadejte rozmery 2. matice(mn): ");
	nactiRozmer(&B);
	printf_s("Zapiste 2. matici:\n");
	nactiMatici(&B);
	printf_s("Byla vlozena 2. matice ve tvaru: \n");
	vypisMatici(&B);
	// je to správně? možnost přepsat řádek
	////switch pro vyber
	////------scitani
	////for(matice)
	sectiMatice(&A, &B, &Final);
	printf_s("Soucet matic: \n");
	vypisMatici(&Final);
	odectiMatice(&A, &B, &Final);
	printf_s("Rozdil matic: \n");
	vypisMatici(&Final);
	printf_s("Nasobeni skalarem: \n");
	nasobSkalarem(&A, cislo, &Final);
	vypisMatici(&Final); //maticeFinal.rozmer
	printf_s("Nasobeni M1xM2: \n");
	nasobMatice(&A, &B, &Final);
	vypisMatici(&Final);
	printf_s("Determinant: \n");
	determinant(&A); //slo by hodit returnem
	printf_s("Transponovana matice: \n");
	transponovana(&A, &Final);
	vypisMatici(&Final); //rozmer je stejny jako puvodni rozmer



	
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