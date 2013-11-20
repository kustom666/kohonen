#ifndef DEF_NEURON
#define DEF_NEURON
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "data.h"


typedef struct Neuron{
	float activite;
	float potentiel;
	int wix;
	int wiy;
}Neuron;

void potentiel(Neuron **NeuronSet, Data *inVecteur);
void printNeuronSet(Neuron **NeuronSet);
void InitialiseNeuronSet(Neuron **inNeuron);
void activite(Neuron **NeuronSet);
int gagnant(Neuron **NeuronSet);
float phi(int rangWinner, int rang);

#endif