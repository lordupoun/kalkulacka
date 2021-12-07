#include "output.h"
#include "funkce.h"

#include <stdio.h>

void outputVypis(FILE* file, struct matice* a) {
	for (int y = 0; y < a->Yrozmer; y++)
	{
		for (int x = 0; x < a->Xrozmer; x++)
		{
			fprintf_s(file, "%8g", a->hodnoty[x][y]);
		}
		fprintf_s(file, "\n");
	}
}

void outputScitani(FILE* file, struct matice* a, struct matice* b, struct matice* c, int chyba) {
	fprintf_s(file, "Soucet matic\n\n");
	outputVypis(file, a);
	fprintf_s(file, "\n\t+\n\n");
	outputVypis(file, b);
	if (chyba) {
		fprintf_s(file, "\nneexistuje; matice nejsou stejneho rozmeru.\n\n----------\n\n");
	}
	else {
		fprintf_s(file, "\n\t=\n\n");
		outputVypis(file, c);
		fprintf_s(file, "\n\n----------\n\n");
	}
}

void outputOdcitani(FILE* file, struct matice* a, struct matice* b, struct matice* c, int chyba) {
	fprintf_s(file, "Rozdil matic\n\n");
	outputVypis(file, a);
	fprintf_s(file, "\n\t-\n\n");
	outputVypis(file, b);
	if (chyba) {
		fprintf_s(file, "\nneexistuje; matice nejsou stejneho rozmeru.\n\n----------\n\n");
	}
	else {
		fprintf_s(file, "\n\t=\n\n");
		outputVypis(file, c);
		fprintf_s(file, "\n\n----------\n\n");
	}
}

void outputNasobeniM(FILE* file, matice* a, matice* b, matice* c, int chyba){
	fprintf_s(file, "Nasobeni matic\n\n");
	outputVypis(file, a);
	fprintf_s(file, "\n\tx\n\n");
	outputVypis(file, b);
	if (chyba) {
		fprintf_s(file, "\nnelze provest; x-ovy rozmer prvni matice se lisi od y-oveho rozmeru druhe matice.\n\n----------\n\n");
	}
	else {
		fprintf_s(file, "\n\t=\n\n");
		outputVypis(file, c);
		fprintf_s(file, "\n\n----------\n\n");
	}
}

void outputNasobeniS(FILE* file, matice* a, double b, matice* c) {
	fprintf_s(file, "Nasobeni skalarem\n\n");
	outputVypis(file, a);
	fprintf_s(file, "\n\tx %.2lf\n\n", b);
	outputVypis(file, c);
	fprintf_s(file, "\n\n----------\n\n");
}

void outputDeterminant(FILE* file, matice* a, double d){
	if (a->Xrozmer==a->Yrozmer) {
		fprintf_s(file, "Determinant matice\n\n");
		outputVypis(file, a);
		fprintf_s(file, "\n\t= %8g\n\n----------\n\n",d);
	}
	else {
		fprintf_s(file, "Matice\n\n");
		outputVypis(file, a);
		fprintf_s(file, "\nneni ctvercova, nelze proto vypocitat jeji determinant.\n\n----------\n\n");
	}
}

void outputTransponovana(FILE* file, matice* a, matice* b){
	fprintf_s(file, "Matice\n\n");
	outputVypis(file, a);
	fprintf_s(file, "\ntransponovana je\n\n");
	outputVypis(file, b);
	fprintf_s(file, "\n\n----------\n\n");
}

