#ifndef DEF_DATA
#define DEF_DATA
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct Data{
	int a;
	int b;
}Data;

void InitialiseSet(Data **inData);
void freeSet(Data **inData);
void printSet(Data **inData);
void SortData(Data **inData, Data *inVect);

#endif // DEF_DATA