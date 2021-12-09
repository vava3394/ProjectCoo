//valentin, Mask
#pragma once
#include "Figure.h"
template<int de>
class PartieSuperieur : public Figure {
public:
	PartieSuperieur(){
		switch (de)
		{
		case 1:
			this->name = "As";
			break;
		case 2:
			this->name = "Deux";
			break;
		case 3:
			this->name = "Trois";
			break;
		case 4:
			this->name = "Quatre";
			break;
		case 5:
			this->name = "Cinq";
			break;
		case 6:
			this->name = "Six";
			break;
		default:
			cout << "hmmmm il y a un probleme, je crois, enfin j'suis pas sûr" << endl;
			break;
		}
		this->desc = "le nombre de dés " + to_string(de) + " obtenus";
		this->numberDe = de;
		this->points = 0;
	}

	virtual bool verif(const vector<int> tabDe) {
		this->points = 0;
		for (int i = 0; i < (int)size(tabDe); i++)
		{
			if (tabDe[i] == numberDe) {
				this->points += numberDe;
			}
		}
		return true;
	}
};
