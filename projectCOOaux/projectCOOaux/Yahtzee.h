//valentin, Mask
#pragma once
#include "Figure.h"

class Yahtzee : public Figure {
public:
	Yahtzee() {
		this->name = "Yahtzee";
		this->desc = "Cinq dés identiques, Points = 50.";
		this->points = 50;
	};
	virtual bool verif(const vector<int> tabDe) {
		int pos = 1;
		int aux = tabDe[0];
		while (aux == tabDe[pos]) {
			pos++;
			if (pos == 5) {
				return true;
			}
		}
		return false;
	}
};
