//valentin, Mask
#pragma once
#include<algorithm>
#include <iostream>
#include<string>
#include<array>
#include<map>
#include"Lancer.h"
#include"Score.h"


using namespace std;
class Joueur
{
private:
	string name;
	int totalScore;
	map <string, Score*> mapScore;
	Lancer* l;
public:
	Joueur(string name, Lancer* l);
	void lancer();
	void roll();
	void save();
	void affichage();
	friend std::ostream& operator<<(std::ostream& os, const Joueur& t);
};
