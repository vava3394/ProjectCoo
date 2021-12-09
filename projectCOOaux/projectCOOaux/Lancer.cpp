//valentin, Mask
#include "Lancer.h"
#define RED     "\033[31m"      /* Red */
#define WHITE   "\033[37m"      /* White */

Lancer::Lancer() {
	this->vectDe = { 0,0,0,0,0 };
	this->vectRoll = { 0,0,0,0,0 };
	this->vectTabF = { new PartieSuperieur<1>() ,new PartieSuperieur<2>() ,new PartieSuperieur<3>() ,new PartieSuperieur<4>() ,new PartieSuperieur<5>() ,new PartieSuperieur<6>() ,new BigSuite(), new LittleSuite(),new Brelan(),new Full(),new Carre(),new Yahtzee(),new Chance() };
	for (int i = 0; i < (int)size(this->vectTabF); i++) {
		mapScoreByFigure.insert(pair<string,int>((*this->vectTabF[i]).name,0));
	}
}

void Lancer::verif() {
	for (map<string, int>::iterator it = mapScoreByFigure.begin(); it != mapScoreByFigure.end(); it++) {
		(*it).second = 0;
	}
	vector<int> aux = this->vectDe;
	sort(aux.begin(),aux.end());
	for (int i = 0; i < (int)size(this->vectTabF); i++) {
		if ((*this->vectTabF[i]).verif(aux)) {
			mapScoreByFigure[(*this->vectTabF[i]).name] = (*this->vectTabF[i]).points;
		}
	}
}

void Lancer::des() {
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		this->vectRoll[i] = 0;
		this->vectDe[i] = (rand() % 6) + 1;
	}
	cout << *this << endl;;
}

void Lancer::roll() {
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		if (!this->vectRoll[i]) {
			this->vectDe[i] = (rand() % 6) + 1;
			
		}
		this->vectRoll[i] = 0;
	}
	cout << *this << endl;
}


std::ostream& operator<<(std::ostream& os, const Lancer& t) {
	string res = "Voici les des : [ ";
	for (int i = 0; i < 5;i++) {
		if (!t.vectRoll[i]) {
			res += to_string(t.vectDe[i]) + " ";
		}
		else {
			res += RED + to_string(t.vectDe[i]) + WHITE + " ";
		}
		
		
	}
	res += "]";
	return os << res;
}