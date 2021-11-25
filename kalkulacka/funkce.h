#pragma once

struct matice
{
	int hodnoty[5][5];
	int Xrozmer;
	int Yrozmer;
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
void sectiMatice(struct matice* a, struct matice* b, struct matice* c);
//odecte matice
void odectiMatice(struct matice* a, struct matice* b, struct matice* c);
//vynasobi matici skalarem
void nasobSkalarem(struct matice* a, int skalar, struct matice* c);
//vynasobi matice
void nasobMatice(struct matice* a, struct matice* b, struct matice* c);
//spocita determinant
void determinant(struct matice* a);
//vypocte transponovanou matici
void transponovana(struct matice* a, struct matice* c);