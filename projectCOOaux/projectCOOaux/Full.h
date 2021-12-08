//valentin, Mask
#pragma once

#include "Figure.h"
#include "Brelan.h"
#include <vector>

class Full : public Figure {
public:
	Full() {
		this->name = "full";
		this->desc = "Trois dés identiques + deux dés identiques, Points = 25.";
		this->points = 25;
	};
	virtual bool verif(const array<int, 5> tabDe) {
		Brelan b = Brelan();
		vector<int> listePossibleDouble;
		if (b.verif(tabDe)) {
			for (int i = 0; i < (int)size(tabDe); i++) {
				if (tabDe[i] != b.getNumberDe()) {
					listePossibleDouble.push_back(tabDe[i]);
				}
			}
			if (!listePossibleDouble.empty()) {
				int aux = listePossibleDouble[0];
				for (int i = 1; i < (int)size(listePossibleDouble); i++) {
					if (listePossibleDouble[i] == aux) {
						return true;
					}
					aux = listePossibleDouble[i];
				}
			}
			else {
				return true;
			}
		}
		return false;
	}
};