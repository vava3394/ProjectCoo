//valentin, Mask
#pragma once

#include "Figure.h"

class LittleSuite : public Figure {
public:
	LittleSuite() {
		this->name = "PetitesSuite";
		this->desc = "Suite : 1,2,3,4 / 2,3,4,5, / 3,4,5,6 , Points = 30.";
		this->points = 30;
	};

	virtual bool verif(const array<int, 5> tabDe) {
		int aux = 1;
		int pos = 1;
		for (int i = 0; i < 3; i++) {
			if (tabDe[i]+1 == tabDe[pos]) {
				aux++;
				if (aux == 3) {
					return true;
				}
			}
			pos++;
		}
		return false;
	}
};