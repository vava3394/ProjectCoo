//valentin, Mask
#include "Lancer.h"

Lancer::Lancer() {
	this->de = { 0,0,0,0,0 };
	this->tabF = { new BigSuite(), new LittleSuite(),new Brelan(),new Full(),new Carre(),new Yahtzee(),new Chance() };
	for (int i = 0; i < (int)size(this->tabF); i++) {
		scoreByFigure.insert(pair<string,int>((*this->tabF[i]).name,0));
	}
}

void Lancer::verif() {
	for (map<string, int>::iterator it = scoreByFigure.begin(); it != scoreByFigure.end(); it++) {
		(*it).second = 0;
	}
	sort(this->de.begin(),this->de.end());
	cout << *this << endl;
	for (int i = 0; i < (int)size(this->tabF); i++) {
		if ((*this->tabF[i]).verif(this->de)) {
			scoreByFigure[(*this->tabF[i]).name] = (*this->tabF[i]).points;
		}
	}
}

void Lancer::des() {
	for (int i = 0; i < 5; i++) {
		this->de[i] = (rand()%6)+1 ;
	}
}

std::ostream& operator<<(std::ostream& os, const Lancer& t) {
	string res = "Voici les des tirés : [ ";
	for (int i = 0; i < 5;i++) {
		res += to_string(t.de[i]) + " ";
	}
	res += "]";
	return os << res;
}