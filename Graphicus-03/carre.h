/********
 * Fichier: carre.h
 * Auteurs: Philippe Durette, Youlian Houehounou
 *		base sur carre.h par: Philippe Durette, Roxanne Cote
 * Date: 10 janvier 2023 (creation)
 * Description: Declaration des classes de formes Carre
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

using namespace std;
#ifndef CARRE_H
#define CARRE_H
#include "forme.h"
#include "rectangle.h"
class Carre : public Rectangle
{
public:
	Carre();
	Carre(int x1, int y1);
	Carre(int cote);
	Carre(int x1, int y1,int cote);
	~Carre();

	int GetLargeur();
	void SetLargeur(int l);

	double aire();
	void afficher(ostream& s);

private:
	int cote;

};

#endif