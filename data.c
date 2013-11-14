#include "data.h"

void InitialiseSet(Data **inData)
{
	srand(time(NULL));
	*inData = (Data *)calloc(20, sizeof(Data));
	for(int i = 0; i < 20; i++){
		Data *buffData = malloc(sizeof(Data));
		buffData->a = rand()%201;
		buffData->b = rand()%201;

		inData[i] = buffData; 
	}
}

void freeSet(Data **inData)
{
	for(int i = 0; i < 20; i++){
		free(inData[i]);
		inData[i] = NULL;
	}
}

void printSet(Data **inData)
{
	for(int i=0; i <20; i++){
		printf("[%d]\tA : %d\tB : %d\n",i,inData[i]->a,inData[i]->b);
	}
}

void SortData(Data **inData, Data *inVect)
{
	int cont = 0;
	while(cont != 1)
	{
		int indice = rand()%20;
		if(inData[indice]->a !=-1.0)
		{
			inVect->a = inData[indice]->a;
			inVect->b = inData[indice]->b;

			inData[indice]->a = -1.0;
			cont = 1;
		}
	}
}