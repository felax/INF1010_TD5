/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"
#include "ClientPremium.h"

double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	double chiffreAffaire = 0.0;
	for (auto it : conteneur_) {
		chiffreAffaire += it->obtenirTotalAPayer();
	}
	return chiffreAffaire;
}

void GestionnaireUsagers::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
	for (auto it : conteneur_) {
		if (it != client && montant > produit->obtenirPrix()) {
			produit->mettreAJourEnchere(client, montant);
		}
	}
}
void GestionnaireUsagers::reinitialiser()
{
	for (auto it : conteneur_) {
		it->reinitialiser();
	}
}
void GestionnaireUsagers::afficherProfils() const
{
	cout << "PROFILS" << endl;
	for (auto it : conteneur_) {
		if (dynamic_cast<ClientPremium*>(it) == nullptr) {
			it->afficher();
		}
		else {
			dynamic_cast<ClientPremium*>(it)->afficherProfil();
		}
	}
}