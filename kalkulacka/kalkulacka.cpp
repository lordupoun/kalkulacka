// kalkulacka.cpp : Defines the entry point for the application.
//

#include "kalkulacka.h"
#include "funkce.h"


using namespace std;
//zjistit jak udelat pole ktere ma definovanou velikost az v programu (po nacteni hodnot)
//float misto int
//automaticke zjisteni velikosti matice

//Nacte aktualni matici


int main()
{
	//šlo by dát do structu
	int matice1[5][5];
	int rozmer1[2];
	int matice2[5][5];
	int rozmer2[2];
	int maticeFinal[5][5];
	printf_s("Zadejte rozmery 1. matice (format: m n): ");
	nactiRozmer(rozmer1);
	printf_s("Zapiste 1. matici:\n");
	nactiMatici(matice1, rozmer1);
	printf_s("Byla vlozena 1. matice ve tvaru: \n");
	vypisMatici(matice1, rozmer1);

	printf_s("\nZadejte rozmery 2. matice(mn): ");
	nactiRozmer(rozmer2);
	printf_s("Zapiste 2. matici:\n");
	nactiMatici(matice2, rozmer2);
	printf_s("Byla vlozena 2. matice ve tvaru: \n");
	vypisMatici(matice2, rozmer2);
	// je to správně? možnost přepsat řádek
	//switch pro vyber
	//------scitani
	//for(matice)
	sectiMatice(matice1, matice2, maticeFinal, rozmer1, rozmer2);
	printf_s("Soucet matic: \n");
	vypisMatici(maticeFinal, rozmer2);
	odectiMatice(matice1, matice2, maticeFinal, rozmer1, rozmer2);
	printf_s("Rozdil matic: \n");
	vypisMatici(maticeFinal, rozmer2);
	printf_s("Náosbení skalárem: \n");
	nasobSkalarem(5, matice1, maticeFinal, rozmer1);
	vypisMatici(maticeFinal, rozmer2);
	
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