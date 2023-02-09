/********
* Fichier: monInterface.cpp
* Auteurs: C.-A. Brunet
* Date: 21 décembre 2021 (création)
* Description: Voir fichier d'entête pour informations.
*
* Copyright 2022 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#include <random>
#include <sstream>
#include "monInterface.h"
#include "canevas.h"

#include <iostream>

using namespace std;

MonInterface::MonInterface(const char* theName) : GraphicusGUI(theName)
{
	
	//reinitialiserCanevas();
	clearInformations();
	updateUI();
}

void MonInterface::reinitialiserCanevas()
{
	canevas.reinitialiser();
	updateUI();
}

bool MonInterface::sauvegarderFichier(const char* c_fileName) {
	ofstream outFile;
	outFile.open(c_fileName);
	if (outFile.is_open()) {
		outFile << canevas;
		outFile.close();
		return true;
	}
	else return false;
	
}

void MonInterface::coucheTranslater(int deltaX, int deltaY) {
	canevas.translater(deltaX, deltaY);
	updateUI();
}

void MonInterface::ajouterCercle(int x, int y, int rayon) {
	canevas.ajouterForme(new Cercle(x, y, rayon));
	updateUI();
}
void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur) {
	canevas.ajouterForme(new Rectangle(x, y, longueur, largeur));
	updateUI();
}
void MonInterface::ajouterCarre(int x, int y, int cote) {
	canevas.ajouterForme(new Carre(x, y, cote));
	updateUI();
}

void MonInterface::coucheAjouter() {
	canevas.coucheAjouter();
	updateUI();
}
void MonInterface::coucheRetirer() {
	canevas.coucheRetirer();
	updateUI();
}
void MonInterface::coucheCacher() {
	canevas.coucheCacher();
	updateUI();
}

void MonInterface::retirerForme() {
	delete canevas.retirerForme();
	updateUI();
}

void MonInterface::couchePremiere() {
	canevas.changerCouche(PREMIERE);
	updateUI();
}
void MonInterface::couchePrecedente() {
	canevas.changerCouche(PRECEDANTE);
	updateUI();
}
void MonInterface::coucheSuivante() {
	canevas.changerCouche(SUIVANTE);
	updateUI();
}
void MonInterface::coucheDerniere() {
	canevas.changerCouche(DERNIERE);
	updateUI();
}

void MonInterface::formePremiere() {
	canevas.changerFormeActive(PREMIERE);
	updateUI();
}
void MonInterface::formePrecedente() {
	canevas.changerFormeActive(PRECEDANTE);
	updateUI();
}
void MonInterface::formeSuivante() {
	canevas.changerFormeActive(SUIVANTE);
	updateUI();
}
void MonInterface::formeDerniere() {
	canevas.changerFormeActive(DERNIERE);
	updateUI();
}

void MonInterface::updateUI() {

	canevas.updateInfo(info); // update the info struct
	setInformations(info); /// send the info struct to the UI
	stringstream ss;
	ss << canevas; // convert canvas to text
	dessiner(ss.str().c_str()); // send text to UI
	//cout << canevas;

}