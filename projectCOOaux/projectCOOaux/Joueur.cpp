#include "Joueur.h"

Joueur::Joueur(string name, Lancer* lance) :name(name), totalPartieSup(0), totalTwoPartie(0) {
	this->l = lance;
	for (int i = 0; i < (int)l->mapScoreByFigure.size(); i++) {
		for (map<string, int>::iterator it = this->l->mapScoreByFigure.begin(); it != this->l->mapScoreByFigure.end(); it++) {
			this->mapScore.insert(pair<string, Score*>((*it).first, new Score()));
		}
	}
};

void Joueur::lancer() {
	this->l->des();
	this->l->verif();
	affichage();
};

void Joueur::affichage() {
	Score s;
	for (map<string, int>::iterator it = this->l->mapScoreByFigure.begin(); it != this->l->mapScoreByFigure.end(); it++) {
		s = *mapScore[(*it).first];
		if (!s.save) {
			cout << (*it).first << " : " << (*it).second << " points !" << endl;
		}
	}
}

void Joueur::roll() {
	string rep;
	string line;
	int de;
	cout << "choisisez les dés que vous voulais garder un chiffre puis espace : (exemple : 1 2 3 ou 2 5)" << endl;
	cin >> rep;
	while (rep != "v") {
		try {
			de = stoi(rep);
			if (de < 6 && de>0) {
				this->l->vectRoll[de-1] = !this->l->vectRoll[de-1];	
			}
			else {
				cout << "il y a une erreure dans votre saisie, vous pouvais bloquer/débloquer un/des dés ou validé" << endl;
			}
			//putain moi
			if (cin.end) {
				cout << *this->l << endl;
				cout << "vous pouvais bloquer/débloquer un/des dés ou validé" << endl;
			}
			cin >> rep;
		}
		catch(exception e){
			cout << "il y a une erreure dans votre saisie, vous pouvais bloquer/débloquer un/des dés ou validé" << endl;
			cin >> rep;
		}
	}
	this->l->roll();
	this->l->verif();
	affichage();
};

template<typename Base, typename T>
inline bool instanceof(const T*) {
	return is_base_of<Base, T>::value;
}

void Joueur::save() {
	string rep;
	Score* s;
	cout << "choisisez figure vous voulais garder : (exemple : Brelan ou Full)" << endl;
	cin >> rep;
	s = this->mapScore[rep];
	while (s == nullptr || s->save) {
		cout << "il y a une erreure dans votre saisie" << endl;
		cin >> rep;
		s = this->mapScore[rep];
	}
	s->save = true;
	s->point = this->l->mapScoreByFigure[rep];
	this->totalTwoPartie += s->point;
}

std::ostream& operator<<(std::ostream& os, const Joueur& t) {
	string res = "";
	os << "----------Joueur " << t.name << "----------" << endl;
	return os << "score de : " << t.totalTwoPartie;
};