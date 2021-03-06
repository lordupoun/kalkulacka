#pragma once

struct matice
{
	double hodnoty[5][5];
	int Xrozmer; //max X rozmer matice
	int Yrozmer; //max Y rozmer matice
};
void inicializuj(struct matice *a);

//Naplni vlozene pole rozmery matice od uzivatele, predavat adresou
void nactiRozmer(struct matice* a);

//Nacte od uzivatele matici
void nactiMatici(struct matice* a); //nebo int (*matice[5])

//Vypise zadanou matici
void vypisMatici(struct matice* a);
//zkontroluje mxn
int stejnytypMatice(struct matice* a, struct matice* b);
//secte matice
int sectiMatice(struct matice* a, struct matice* b, struct matice* c);
//odecte matice
int odectiMatice(struct matice* a, struct matice* b, struct matice* c);
//vynasobi matici skalarem
void nasobSkalarem(struct matice* a, double skalar, struct matice* c);
//vynasobi matice
int nasobMatice(struct matice* a, struct matice* b, struct matice* c);
//spocita determinant
double determinant(struct matice* a);
//vypocte transponovanou matici
void transponovana(struct matice* a, struct matice* c);
//vepsani matice do konzole
int manualniInput(struct matice* a, struct matice*b);
//vytahne matic(i/e) ze souboru
int zeSouboru(struct matice* a, struct matice* b);