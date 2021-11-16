#pragma once
//Naplni vlozene pole rozmery matice od uzivatele
void nactiRozmer(int rozmer[2]);

//Nacte od uzivatele matici
void nactiMatici(int matice[5][5], int max[2]); //nebo int (*matice[5])

//Vypise zadanou matici
void vypisMatici(int matice[5][5], int max[2]);

int stejnytypMatice(int max1[2], int max2[2]);

//secte matice
void sectiMatice(int Matice1[5][5], int Matice2[5][5], int final[5][5], int max1[2], int max2[2]);

void odectiMatice(int Matice1[5][5], int Matice2[5][5], int final[5][5], int max1[2], int max2[2]);

void nasobSkalarem(int cislo, int matice[5][5], int final[5][5], int max[2]);