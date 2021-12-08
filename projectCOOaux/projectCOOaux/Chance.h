//valentin, Mask
#pragma once
#include "Figure.h"

class Chance : public Figure {
public:
	Chance() {
		this->name = "Chance";
		this->desc = "Rien de sp�cial, Points = Somme de tous les d�s.";
		this->points = 0;
	};
	virtual bool verif(const vector<int> tabDe) {
		this->points = 0;
		for (int i = 0; i < (int)size(tabDe); i++) {
			this->points += tabDe[i];
		}
		return true;
	}
};
