#ifndef DEF_NEURON
#define DEF_NEURON
#include <SFML/OpenGL.h>
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
void showNeuron(Neuron **inNeuronSet);
void calculPoids(float pas, Neuron **NeuronSet, int rang, Data inVecteur);

#endif