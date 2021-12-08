//valentin, Mask
#pragma once
#include "Figure.h"

class Carre : public Figure {
public:
	Carre() {
		this->name = "Carre";
		this->desc = "Quatre dés identiques, Points = Somme de tous les des.";
		this->points = 0;
	};
	virtual bool verif(const vector<int> tabDe) {
		int de = tabDe[0];
		int aux = 1;
		this->points = 0;
		for (int i = 1; i < (int)size(tabDe) - 2; i++) {
			if (tabDe[i] == de) {
				while (tabDe[i] == tabDe[i + aux]) {
					aux++;
					if (aux == 3) {
						for (int i = 0; i < (int)size(tabDe); i++) {
							if (tabDe[i] != de) {
								this->points += tabDe[i];
							}
						}
						this->points += de * 4;
						this->numberDe = de;
						return true;
					}
				}
			}
			else {
				de = tabDe[i];
			}
		}
		return false;
	}
};
