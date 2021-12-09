//valentin, Mask
#pragma once
#include <array> 
#include <iostream>
#include<string>
#include <cstdlib>
#include "Figure.h"
#include "Brelan.h"
#include "Full.h"
#include "BigSuite.h"
#include "LittleSuite.h"
#include "Carre.h"
#include "Yahtzee.h"
#include "Chance.h"
#include "PartieSuperieur.h"
#include <algorithm>
#include <map>

using namespace std;

class Lancer {
	friend class Joueur;
private:
	vector <int> vectDe;
	vector <bool> vectRoll;
	vector <Figure*> vectTabF;
	map<string, int> mapScoreByFigure;
public:
	Lancer();
	void verif();
	void des();
	void roll();
	friend std::ostream& operator<<(std::ostream& os, const Lancer& t);
};