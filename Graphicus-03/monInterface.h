/********
* Fichier: monInterface.h
* Auteurs: C.-A. Brunet
* Date: 21 décembre 2021 (création)
* Description: La classe MonInterface teste l'interface usager GraphicusGUI.
*
* Copyright 2022 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include <fstream>
#include "../GraphicusGUI/graphicusGUI.h"
#include "canevas.h"
#include "cercle.h"
#include "carre.h"
#include "rectangle.h"


class MonInterface : public GraphicusGUI
{
public:
	MonInterface(const char *theName = nullptr);
	virtual void reinitialiserCanevas();

	bool ouvrirFichier(const char* fichier);
	bool sauvegarderFichier(const char* c_fileName);
	
	virtual void coucheTranslater(int deltaX, int deltaY);
	virtual void ajouterCercle(int x, int y, int rayon);
	virtual void ajouterRectangle(int x, int y, int longueur, int largeur);
	virtual void ajouterCarre(int x, int y, int cote);

	void coucheAjouter();
	void coucheRetirer();
	void coucheCacher();

	void retirerForme();

	void couchePremiere();
	void couchePrecedente();
	void coucheSuivante();
	void coucheDerniere();

	void formePremiere();
	void formePrecedente();
	void formeSuivante();
	void formeDerniere();

	void modePileChange(bool mode);

private:
	void updateUI();
	//Couche c1;
	Canevas canevas;

	Informations info;
};

#endif // MONINTERFACE_H