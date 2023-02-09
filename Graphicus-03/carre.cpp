/********
 * Fichier: carre.cpp
 * Auteurs: Roxanne Cote et Philippe Durette
 * Date: 10 janvier 2023 (creation)
 * Description:Declaration des classes de formes Carre
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "carre.h"

Carre::Carre() : Rectangle() {
	cote = 1;
}
Carre::Carre(int x1, int y1) : Rectangle(x1, y1, 1, 1) {
	cote = 1;
}
Carre::Carre(int x1, int y1, int size) : Rectangle(x1, y1, size, size) {
    cote = size;
}
Carre::Carre(int size) : Rectangle(0, 0, size, size) {
    cote = size;
}
Carre::~Carre() {

}

int Carre::GetLargeur() {
	return cote;
}
void Carre::SetLargeur(int l) {
	cote = l;
}

double Carre::aire() {
	return cote * cote;
}
void Carre::afficher(ostream& s) {
	s << "K "
		<< ancrage.x << " "
		<< ancrage.y << " "
		<< cote << "\n";
}
