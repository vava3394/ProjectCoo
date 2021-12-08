//valentin, Mask
#pragma once
#include <array> 
#include <iostream>
#include<string>
#include <ctime>
#include <cstdlib>
#include "Figure.h"
#include "Brelan.h"
#include "Full.h"
#include "BigSuite.h"
#include "LittleSuite.h"
#include "Carre.h"
#include "Yahtzee.h"
#include "Chance.h"
#include <algorithm>
#include <map>

using namespace std;

class Lancer {
	friend class Joueur;
private:
	array < int, 5 > de;
	array < Figure*, 7> tabF;
	map<string, int> scoreByFigure;
public:
	Lancer();
	void verif();
	void des();
	void des(array <bool,5>);
	friend std::ostream& operator<<(std::ostream& os, const Lancer& t);
};