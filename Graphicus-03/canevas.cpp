/********
 * Fichier: canevas.cpp
 * Auteurs: Philippe Durette, Roxanne Cote
 * Date: 10 janvier 2023 (creation)
 * Description: Declaration de la classe Canevas. La classe gere un
 * tableau de couches en accord avec les specifications de Graphicus.
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"
 
Canevas::Canevas()
{
	couches.add(Couche()); // ajoute la couche 0
	couches.setActiveIndex(0);
	coucheMemoire = 0;
	changerEtatCouche(ACTIVE);
	inversionPile = false;
}

Canevas::~Canevas()
{
}
// Retourne Vrai si la fonction a été reinitialiser
bool Canevas::reinitialiser()
{
	for (int i = 0; i < couches.getSize(); i++)
	{
		couches[i].ReinitialiserCouche(); // delete le contenue de la couche
	}
	couches.clear(); // delete les couches
	couches.add(Couche()); // ajoute la couche 0
	couches.setActiveIndex(0);
	coucheMemoire = 0;
	changerEtatCouche(ACTIVE);
	return true;
}
// Retourne Vrai si la couche a été activer

void Canevas::changerCouche(int deplacement) {
	coucheMemoire = couches.getActiveIndex();
	switch (deplacement) {
	case PREMIERE:
		couches.setActiveIndex(0);
		break;
	case PRECEDANTE:
		if (couches.getActiveIndex() > 0) {
			couches--;
		}
		break;
	case SUIVANTE:
		if (couches.getActiveIndex() < (couches.getSize() - 1)) {
			couches++;
		}
		break;
	case DERNIERE:
		couches.setActiveIndex(couches.getSize() - 1);
		break;
	default:
		break;
	}
	//cout << "- changerCouche: couches.getActiveIndex() ===== " << couches.getActiveIndex() << " " << coucheMemoire << endl;
	if (couches[coucheMemoire].getEtat() != CACHE) { // si la couche n'est pas à l'état cache
		couches[coucheMemoire].ChangerEtat(INACTIVE); // desactive la vieille couche 
	}
	couches[couches.getActiveIndex()].ChangerEtat(ACTIVE); // active la nouvelle couche
	coucheMemoire = couches.getActiveIndex();
	//cout << "\n--- couche dans Canevas ---\n";
}

void Canevas::changerEtatCouche(int etat){
	
	couches[couches.getActiveIndex()].ChangerEtat(etat);
}

void Canevas::coucheAjouter() {
	//cout << "\n--- coucheAjouter() dans Canevas ---\n";
	if (couches[couches.getActiveIndex()].getEtat() != CACHE) { // si la couche n'est pas à l'état cache
		couches[couches.getActiveIndex()].ChangerEtat(INACTIVE); // desactive la vieille couche 
	}
	couches.add(Couche());
	changerCouche(DERNIERE);
}
void Canevas::coucheRetirer() {
	if ((couches.getActiveIndex() >= 0) && (couches.getActiveIndex() <= couches.getSize())) {
		couches[couches.getActiveIndex()].ReinitialiserCouche();
		couches.removeItem(couches.getActiveIndex());
	}
	if (couches.getSize() == 0) {
		reinitialiser();
	}
	changerCouche(PRECEDANTE);
}
void Canevas::coucheCacher() {
	//cout << "---------- call: couche cache -\n";
	if (couches[couches.getActiveIndex()].getEtat() == CACHE) {
		//cout << "- couche était cache -\n";
		couches[couches.getActiveIndex()].ChangerEtat(ACTIVE);
	}
	else if ((couches[couches.getActiveIndex()].getEtat()) == ACTIVE) {
		//cout << "- couche était active -\n";
		couches[couches.getActiveIndex()].ChangerEtat(CACHE);
	}
}

void Canevas::changerFormeActive(int deplacement) {
	couches[couches.getActiveIndex()].changerFormeActive(deplacement);
}

bool Canevas::ajouterForme(Forme *p_forme)
{
	return couches[couches.getActiveIndex()].Ajout(p_forme);
	//return couches[indexActif].Ajout(p_forme); // old version
}
Forme* Canevas::retirerForme()
{
	return couches[couches.getActiveIndex()].RetraitForme();
	//return couches[indexActif].RetraitForme(index); // old version
}

double Canevas::aire()
{
	int AireTotaleCanevas=0;
	for (int i = 0; i < couches.getSize(); i++)
	{
		AireTotaleCanevas+= couches[i].AireTotaleCouche();
	}
	return AireTotaleCanevas;
}

bool Canevas::translater(int deltaX, int deltaY)
{
	return couches[couches.getActiveIndex()].Translater(deltaX, deltaY);
}
/* Obsolete: use the << operator instead
void Canevas::afficher(ostream &s)
{
	for (int x =0; x<5; x++)
	{
	  s<<"----- Couche "<< x<< endl;
	  couches[x].AfficherCouche(s);
	}
}
*/

void Canevas::inversePile(bool mode) {
	inversionPile = mode;
}

void Canevas::updateInfo(Informations& info) {
	info.nbCouches = couches.getSize();
	info.nbFormesCanevas = 0;
	info.coucheActive = couches.getActiveIndex();
	info.nbFormesCouche = 0;
	
	for (int i = 0; i < couches.getSize(); i++) {
		//cout << "Active Laver: [ " << couches.getActiveIndex() << " ] , Value of i: [ " << i << " ]\n";
		//cout << "i == couches.getActiveIndex(): [ " << (i == couches.getActiveIndex()) << " ]\n";
		couches[i].updateInfo(info, (i == couches.getActiveIndex()));
	}
	info.aireCanevas = aire();
}

