/********
 * Fichier: Rectangle.cpp
 * Auteurs: Philippe Durette, Youlian Houehounou
 *		base sur Rectangle.cpp par: Philippe Durette, Roxanne Cote
 * Date: 10 janvier 2023 (creation)
 * Description: Declaration des classes de formes Rectangle
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "rectangle.h"

Rectangle::Rectangle() : Forme()
{
   hauteur = 1;
   largeur = 1;
}

Rectangle::Rectangle (int x, int y, int L, int H) : Forme (x, y)
{
   hauteur = H;
   largeur = L;
}
Rectangle::~Rectangle()
{

}
int Rectangle::GetHauteur()
{
   return hauteur;
}
int Rectangle::GetLargeur()
{
   return largeur;
}
void Rectangle::SetHauteur(int H)
{
   hauteur = H;
}
void Rectangle::SetLargeur(int L)
{
   largeur= L;
}
double Rectangle::aire()
{
   return hauteur * largeur;
}
void Rectangle::afficher(ostream& s) {
	s << "R " 
		<< ancrage.x << " " 
		<< ancrage.y <<" " 
		<< largeur <<" " 
		<< hauteur << "\n";
}
