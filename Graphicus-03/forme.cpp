/********
 * Fichier: forme.cpp
 * Auteurs: Philippe Durette, Youlian Houehounou
 *		base sur forme.cpp par: Philippe Durette, Roxanne Cote
 * Date: 10 janvier 2023 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    forme.h. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "forme.h"

Forme::Forme(int x1, int y1)
{
  ancrage.x = x1;
  ancrage.y = y1;
}

Forme::~Forme()
{
}

void Forme::translater(int deltaX, int deltaY)
{
   ancrage.x += deltaX;
   ancrage.y += deltaY;
}

Coordonnee Forme::getAncrage()
{
   return ancrage;
}

void Forme::setAncrage(Coordonnee c)
{
   ancrage = c;
}
