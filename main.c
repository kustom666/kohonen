#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SFML/OpenGL.h>
#include <SFML/Window.h>
#include "data.h"
#include "neuron.h"


int main(int argc, char *argv[])
{
	bool cont = true;
	int max = 0;
	Data *DataSet[20];
	Neuron *NeuronSet[20];
	InitialiseSet(DataSet);
	InitialiseNeuronSet(NeuronSet);

	sfVideoMode mode = {800,600,24};
	sfContextSettings settings = {24,8,0,2,1};
	sfWindow *window = sfWindow_create(mode, "Kohonen",sfDefaultStyle, &settings);

	glMatrixMode (GL_PROJECTION);
	glOrtho(0, 200, 0, 200, 0, 1);

	while(cont)
	{

		/** Logique de kohonen
		*
		**/

		if(max <20)
		{
			Data buffData;
			SortData(DataSet, &buffData);
			potentiel(NeuronSet, &buffData);
			activite(NeuronSet); 
			int rangGagnant = gagnant(NeuronSet);
			calculPoids(0.5, NeuronSet, rangGagnant, buffData);
			max ++;
		}
		/** Logique d'affichage 
		*
		**/
		sfEvent event;

		while(sfWindow_pollEvent (window, &event))
		{
			if(event.type == sfEvtClosed)
			{
				cont = false;
			}
			else if(event.type == sfEvtResized)
			{
				glViewport(0, 0, event.size.width, event.size.height);
			}
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glBegin(GL_POINTS);
			showData(DataSet);
			showNeuron(NeuronSet);
		glEnd();

		sfWindow_display(window);

	}

	sfWindow_close(window);
	freeSet(DataSet);
	return 0;
}