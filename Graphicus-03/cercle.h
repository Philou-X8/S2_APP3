/********
 * Fichier: Cercle.h
 * Auteurs: Philippe Durette, Youlian Houehounou
 *		base sur Cercle.h par: Philippe Durette, Roxanne Cote
 * Date: 10 janvier 2023 (creation)
 * Description: Declaration des classes de formes Cercle
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

using namespace std;
#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include "forme.h"
using namespace std;

class Cercle : public Forme
{
public : 
  Cercle (int x1, int y1, int rayon);
  Cercle ();
  ~ Cercle ();

  // getter
  int GetRayon ();

  // setter
  void SetRayon (int R);


  // fonction amis
  double aire();
  void afficher(ostream& s);

private:
  int Rayon;

};


#endif
