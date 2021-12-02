#pragma once

#include <stdio.h>

void outputVypis(FILE* file, struct matice* a);
void outputScitani(FILE* file, struct matice* a, struct matice* b, struct matice* c, int chyba);
void outputOdcitani(FILE* file, struct matice* a, struct matice* b, struct matice* c, int chyba);
void outputNasobeniM(FILE* file, struct matice* a, struct matice* b, struct matice* c, int chyba);
void outputNasobeniS(FILE* file, struct matice* a, double b, struct matice* c);
void outputDeterminant(FILE* file, struct matice* a, double d);
void outputTransponovana(FILE* file, struct matice* a, struct matice* b);