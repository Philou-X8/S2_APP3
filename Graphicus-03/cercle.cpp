/********
 * Fichier: Cercle.cpp
 * Auteurs: Roxanne Cote et Philippe Durette
 * Date: 10 janvier 2023 (creation)
 * Description: Declaration des classes de formes Cercle
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "cercle.h"
#include <math.h>

Cercle :: Cercle() : Forme()
{
   Rayon = 1;

}
Cercle :: Cercle(int x1, int y1, int R) : Forme (x1, y1)
{
   Rayon = R;
}
Cercle:: ~Cercle()
{

}
 
 int Cercle :: GetRayon()
 {
   return Rayon;
 }

void Cercle :: SetRayon (int r)
{
   Rayon = r;
}
double Cercle :: aire () 
{
   return 3.1415 * Rayon * Rayon;
}

void Cercle :: afficher (ostream& s)
{
	s << "C "
		<< ancrage.x << " "
		<< ancrage.y << " "
		<< Rayon << "\n";
}
