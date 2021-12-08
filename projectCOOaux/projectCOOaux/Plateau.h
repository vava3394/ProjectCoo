#pragma once
#include "Lancer.h"
#include "Joueur.h"
#include <vector>

class Plateau
{
	int nbJoueurs;
	Lancer lance;
	vector<Joueur*> joueurs;
public:
	Plateau(int nbJoueurs);
	void run();
};

