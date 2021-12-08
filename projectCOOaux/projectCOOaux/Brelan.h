//valentin, Mask
#pragma once
#include "Figure.h"

class Brelan : public Figure {
public :
	Brelan() {
		this->name = "Brelan";
		this->desc = "Trois des identiques, Points = Somme de tous les des.";
		this->points = 0;
	};
	virtual bool verif(const vector<int> tabDe) {
		this->points = 0;
		int de = tabDe[0];
		int aux = 1;
		for (int i = 1; i < (int)size(tabDe)-1; i++) {
			if (tabDe[i] == de) {
				while (tabDe[i] == tabDe[i+aux]) {
					aux++;
					if (aux == 2) {
						for (int i = 0; i < (int)size(tabDe); i++) {
							if (tabDe[i] != de) {
								this->points += tabDe[i];
							}
						}
						this->points += de * 3;
						this->numberDe = de;
						return true;
					}
				}
				de = tabDe[i];
			}
			else {
				de = tabDe[i];
			}
		}
		return false;
	}
};