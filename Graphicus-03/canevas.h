/********
 * Fichier: canevas.h
 * Auteurs: Philippe Durette, Roxanne Cote
 * base sur canevas.h par: Philippe Durette, Roxanne Cote
 * Date: 10 janvier 2023 (creation)
 * Description: Declaration de la classe Canevas. La classe gere un
 *    tableau de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef DESSIN_H
#define DESSIN_H


#include <iostream>
#include "forme.h"
#include "couche.h"
#include "vecteur.h"


using namespace std;

class Canevas
{
public:
	Canevas();
	~Canevas();
	
	bool reinitialiser();

	void changerCouche(int deplacement);
	void coucheAjouter();
	void coucheRetirer();
	void coucheCacher();
	void changerFormeActive(int deplacement);

	void changerEtatCouche(int etat);
	
	bool ajouterForme(Forme *p_forme);
	Forme* retirerForme();
	
	double aire();
	bool translater(int deltaX, int deltaY);
	//void afficher(ostream &s); // Obsolete: use the << operator instead

	void inversePile(bool mode);
	void updateInfo(Informations& info);

    friend ostream& operator << (ostream& stream, Canevas& caneva) {
		if (caneva.inversionPile) {
			for (int i = (caneva.couches.getSize() - 1); i >= 0; i--) {
				stream << caneva.couches[i];
			}
		}
		else {
			for (int i = 0; i < caneva.couches.getSize(); i++) {
				stream << caneva.couches[i];
			}
		}
		
		return stream;
	}

	Vecteur<Couche> couches;

private:
	bool inversionPile; // f = default | t = inverted
	int coucheMemoire;
};

#endif
