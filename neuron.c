#include "neuron.h"
#include "data.h"

void potentiel(Neuron **NeuronSet, Data *inVecteur)
{
	for(int i = 0; i < 20; i ++){
		NeuronSet[i]->potentiel = sqrt(pow(inVecteur->a - NeuronSet[i]->wix,2)+pow(inVecteur->b - NeuronSet[i]->wiy,2));
	} 
}

void activite(Neuron **NeuronSet)
{
	for(int i = 0; i < 20; i ++){
		NeuronSet[i]->activite = 1/(1+NeuronSet[i]->potentiel);
	} 
}

void printNeuronSet(Neuron **NeuronSet)
{
	for (int i = 0; i < 20; ++i)
	{
		printf("NS[%d]\t%f\n",i, NeuronSet[i]->potentiel);
	}
}

void InitialiseNeuronSet(Neuron **inNeuron)
{
	srand(time(NULL));
	for(int i = 0; i < 20; i++){
		Neuron *buffNeuron = malloc(sizeof(Neuron));
		buffNeuron->wix = i+90;
		buffNeuron->wiy = i+90;
		inNeuron[i] = buffNeuron; 
	}
}

int gagnant(Neuron **NeuronSet)
{
	int indice = 0;
	float buffActivite = NeuronSet[0]->activite;

	for (int i = 0; i < 20; ++i)
	{
			if(buffActivite < NeuronSet[i]->activite)
			{
				indice = i;
			}
	}
	return indice;
}

void calculPoids(float pas, Neuron **NeuronSet, int rang, Data inVecteur)
{
	if (rang >= 2)
	{
		for (int i = rang-2; i < rang+2; ++i)
		{
			NeuronSet[i]->wix += pas + inVecteur.a - NeuronSet[i]->wix * phi(rang, i);
		}
	}
	else
	{
		for (int i = 0; i < rang+2; ++i)
		{
			NeuronSet[i]->wix += pas + inVecteur.a - NeuronSet[i]->wix * phi(rang, i);
		}
	}
}

float phi(int rangWinner, int rang)
{
	float retour = 0.0;
	if(abs(rang-rangWinner) == 2)
	{
		retour = -0.5;
	}
	else if(abs(retour-rangWinner) == 1)
	{
		retour = 0.5;
	}
	else
	{
		retour = 1;
	}
	return retour;
}

void showNeuron(Neuron **inNeuronSet)
{
	glColor3f(1.0,0.0,0.0);
	
	for (int i = 0; i < 20; ++i)
	{
		glVertex2i(inNeuronSet[i]->wix, inNeuronSet[i]->wiy);
	}
}