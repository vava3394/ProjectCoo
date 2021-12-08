#include "Joueur.h"

Joueur::Joueur(string name, Lancer* lance) :name(name), totalScore(0), tabRoll({0,0,0,0,0}) {
	this->l = lance;
	for (int i = 0; i < (int)l->scoreByFigure.size(); i++) {
		for (map<string, int>::iterator it = this->l->scoreByFigure.begin(); it != this->l->scoreByFigure.end(); it++) {
			this->mapScore.insert(pair<string, Score*>((*it).first, 0));
		}
	}
};

void Joueur::lancer() {
	this->l->des();
	this->l->de = { 5,5,5,5,6 };
	cout << *this->l << endl;
	this->l->verif();
	for (map<string, int>::iterator it = this->l->scoreByFigure.begin(); it != this->l->scoreByFigure.end(); it++) {
		cout << (*it).first << " : " << (*it).second << " points !" << endl;
	}
};

void Joueur::roll() {
	string rep;
	cout << "choisisez les dés que vous voulais garder un chiffre puis espace : (exemple : 1 2 3 ou 3 2 5)" << endl;
	cin >> rep;
};

void Joueur::save() {
	//this->saveFigure[pos] = 1;
}

std::ostream& operator<<(std::ostream& os, const Joueur& t) {
	return os << "Joueur : " << t.name << " a un score de : " << t.totalScore;
};