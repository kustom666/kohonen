#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SFML/OpenGL.h>
#include <SFML/Window.h>
#include "data.h"
#include "neuron.h"


int main(int argc, char *argv[])
{
	Data *DataSet[20];
	Neuron *NeuronSet[20];
	InitialiseSet(DataSet);
	InitialiseNeuronSet(NeuronSet);
	printSet(DataSet);
	Data buffData;
	SortData(DataSet, &buffData);
	printf("RandomData : %d,%d\n", buffData.a, buffData.b);
	printSet(DataSet);

	potentiel(NeuronSet, &buffData);
	printNeuronSet(NeuronSet);
	freeSet(DataSet);

	sfEvent *event;
	bool cont = true;
	sfVideoMode mode = {800,600,24};
	sfWindow *window = sfWindow_create(mode, "OpenGL",2, NULL);
	sfWindow_display(window);

	while(cont)
	{
		sfWindow_pollEvent (window, event);
		if(event->type == sfEvtClosed)
		{
			cont = false;
		}
		//sfWindow_display(window);

	}
	sfWindow_close(window);
	return 0;
}