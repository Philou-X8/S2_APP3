/********
 * Fichier: couche.h
 * Auteurs: Philippe Durette, Roxanne C�t�
 * Date: 10 janvier 2023 (creation)
 * Description:Implementation des methodes des classes decrites dans
 * Couche.cpp. 
 *   Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H

#include "forme.h"
#include "vecteur.h"
#include "../GraphicusGUI/graphicusGUI.h"

#define INITIALISER 1
#define ACTIVE 2
#define INACTIVE 3
#define CACHE 4

#define PREMIERE 0
#define PRECEDANTE 1
#define SUIVANTE 2
#define DERNIERE 3

using namespace std;

class Couche
{
public:
	Couche();
   ~Couche();
   bool Ajout(Forme *newForme);
   Forme* RetraitForme();
   Forme* ObtenirForme(int i); 
   double AireTotaleCouche();
   bool Translater(int h, int v);
   bool ReinitialiserCouche();
   bool ChangerEtat(int ChoixEtat);/////////A FAIRE
   int getEtat();
   void changerFormeActive(int deplacement);
   void AfficherCouche(ostream & s);
	
   void updateInfo(Informations& info, bool activeLayer);

	friend ostream& operator << (ostream& stream, Couche& c) {
		switch (c.Etat) {
		case INITIALISER:
			stream << "L i\n";
			break;
		case ACTIVE:
			stream << "L a\n";
			break;
		case INACTIVE:
			stream << "L x\n";
			break;
		case CACHE:
			stream << "L c\n";
			break;
		default:
			stream << "\n";
			return stream;
		}
		stream << c.vecteur;
		return stream;
	}

private:
	int Etat;//1 initialiser, 2 Active, 3 Inactive, 4 cache
	Vecteur<Forme*> vecteur;
   
   
};

#endif
