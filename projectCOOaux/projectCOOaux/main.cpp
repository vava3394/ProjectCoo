#include"Plateau.h"

int main() {
	try {
		int nbJoueurs;
		cout << "nombre de Joueur "<< endl;
		cin >> nbJoueurs;
		Plateau p = Plateau(nbJoueurs);
		p.run();
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}


	
}