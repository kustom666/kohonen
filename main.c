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

	sfContextSettings settings = {24,8,0,2,1};
	bool cont = true;
	sfVideoMode mode = {800,600,24};
	sfWindow *window = sfWindow_create(mode, "OpenGL",sfDefaultStyle, &settings);

	glMatrixMode (GL_PROJECTION);
	glOrtho(0, 200, 0, 200, 0, 1);

	while(sfWindow_isOpen(window))
	{
		sfEvent event;

		while(sfWindow_pollEvent (window, &event))
		{
			if(event.type == sfEvtClosed)
			{
				sfWindow_close(window);
			}
			else if(event.type == sfEvtResized)
			{
				 glViewport(0, 0, event.size.width, event.size.height);
				 glOrtho(0, 200, 0, 200, 1, 1);
			}
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glBegin(GL_POINTS);
			showData(DataSet);
		glEnd();
		sfWindow_display(window);

	}

	freeSet(DataSet);
	return 0;
}