#include "Plateau.h"

Plateau::Plateau(int nbJoueurs) :nbJoueurs(nbJoueurs), lance(Lancer()) {
	string name;
	for (int i = 0; i < nbJoueurs; i++) {
		cout << "name joueur" + to_string(i+1)<< endl;
		cin >> name;
		this->joueurs.push_back(new Joueur(name, &lance));
	}
}

void Plateau::run() {
	string rep;
	for (int tour = 0; tour < 12; tour++) {
		for (int numJoueur = 0; numJoueur < (int)size(joueurs); numJoueur++) {
			joueurs[numJoueur]->lancer();
			for (int i = 0; i < 3; i++) {
				cout << "roll ? (y/n)" << endl;
				cin >> rep;
				while (rep != "y" && rep != "n") {
					cout << "petite erreur roll ? (y/n)" << endl;
					cin >> rep;
				}
				if (rep == "y") {
					joueurs[numJoueur]->roll();
				}
				else {
					i = 3;
				}
			}
			joueurs[numJoueur]->save();
		}
	}
	cout << "----------classement----------" << endl;
	while ((int)size(joueurs) > 0) {
		Joueur j = *this->joueurs[0];
		for (int numJoueur = 0; numJoueur < (int)size(joueurs); numJoueur++) {
			
		}
	}
}