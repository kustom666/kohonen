#include <stdlib.h>
#include <stdio.h>
#include "data.h"

int main(int argc, char* argv[])
{
	Data *DataSet[20];
	InitialiseSet(DataSet);
	printSet(DataSet);
	Data buffData;
	SortData(DataSet, &buffData);
	printf("RandomData : %d,%d\n", buffData.a, buffData.b);
	freeSet(DataSet);
	return 0;
}