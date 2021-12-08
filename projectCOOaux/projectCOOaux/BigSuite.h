//valentin, Mask
#pragma once
#include "Figure.h"

class BigSuite : public Figure {
public:
	BigSuite() {
		this->name = "GrandeSuite";
		this->desc = "Suite : 1,2,3,4,5 / 2,3,4,5,6 , Points = 40.";
		this->points = 40;
	};
	virtual bool verif(const array<int, 5> tabDe) {
		int pos = 1;
		for (int i = 0; i < 4; i++) {
			if (tabDe[i] + 1 != tabDe[pos]) {
				return false;
			}
			pos++;
		}
		return true;
	}
};