/********
 * Fichier: Rectangle.h
 * Auteurs: Roxanne Cote et Philippe Durette
 * Date: 10 janvier 2023 (creation)
 * Description: Declaration des classes de formes Rectangle
 *    Ce fichier fait partie de la distribution de Graphicus.
********/
using namespace std;
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "forme.h"
using namespace std;

class Rectangle: public Forme

{
  public:
    Rectangle ();
    Rectangle (int x, int y, int L, int H);
    ~Rectangle ();
    // getter
    int GetHauteur ();
    int GetLargeur ();

    // setter
    void SetHauteur (int H);
    void SetLargeur (int L); 
    
  // fonction amis
  virtual double aire();
  virtual void afficher(ostream& s);
  private:
    double hauteur;
    double largeur;



};
#endif
