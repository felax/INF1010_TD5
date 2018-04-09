/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
#include "GestionnaireGenerique.h"
#include "ProduitAuxEncheres.h"
#include "Produit.h"
#include "Foncteur.h"
#include <vector>
#include <functional>
#include <iostream>

void GestionnaireProduits::reinitialiserClient()
{
	for (auto it : conteneur_) {
		ProduitAuxEncheres* pEnch = dynamic_cast<ProduitAuxEncheres*>(it.second);
		if (pEnch != nullptr) {
			pEnch->modifierEncherisseur(nullptr);
			pEnch->modifierPrix(pEnch->obtenirPrixInitial());
		}
	}
	conteneur_.clear();
}
void GestionnaireProduits::reinitialiserFournisseur()
{
	for (auto it : conteneur_)
		it.second->modifierFournisseur(nullptr);
	conteneur_.clear();
}
void GestionnaireProduits::afficher() const 
{
	for (auto it : conteneur_) {
		it.second->afficher();
		cout << "\t\texemplaires:\t" << count(conteneur_.begin(), conteneur_.end(), it) << "\n";
		// ajuster laffichage apres les tests
	}
}
double GestionnaireProduits::obtenirTotalAPayer()
{
	double totalAPayer = 0.0;
	for (auto it : conteneur_) {
		totalAPayer += it.second->obtenirPrix();
	}
	return totalAPayer;
}
double GestionnaireProduits::obtenirTotalApayerPremium()
{
	double totalAPayerPremium = 0.0;
	for (auto it : conteneur_) {
		if (it.second->obtenirPrix() > 5) {
			totalAPayerPremium += (it.second->obtenirPrix()-5);
		}
	}
	return totalAPayerPremium;
}
Produit* GestionnaireProduits::trouverProduitPlusCher()
{
	if (conteneur_.size() != 0) {
		Produit* produitPlusCher = conteneur_.begin()->second;
		for (auto it : conteneur_) {
			if (it.second->obtenirPrix() > produitPlusCher->obtenirPrix())
			{
				produitPlusCher = it.second;
			}
		}
		return produitPlusCher;
	}
	else
		return nullptr;
}

vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double lower, double upper) 
{
	vector<pair<int, Produit*>> produitEntre;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(produitEntre), FoncteurIntervalle(lower, upper));
	return produitEntre;
}
Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* produit)
{
	//auto predicat = bind(FoncteurEgal<Produit>, produit);
	auto it = find_if(conteneur_.begin(), conteneur_.end(), FoncteurEgal<Produit>(produit));
	int prevRef = it->first;
	bool returned = false;
	while (returned == false)
	{
		if ((++it)->first != prevRef) {
			returned = true;
			return it->second;
		}
	}
}