#include "Fournisseur.h"
#include <iostream>
#include "Foncteur.h"

Fournisseur::Fournisseur()
    : Usager()
{
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal)
{
	catalogue_ = new GestionnaireProduits;
}

GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
	// TODO : À modifier
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
	cout << "CATALOGUE (de " << obtenirNom() << ")" << endl;
	catalogue_->afficher();
	cout << endl;
}

void Fournisseur::afficher() const
{
	// TODO : À modifier
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << catalogue_->obtenirConteneur().size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
	catalogue_->reinitialiserFournisseur();
}

void Fournisseur::ajouterProduit(Produit *produit)
{
	// TODO : À modifier
	/*for (auto it : catalogue_->obtenirConteneur()) {
		if (produit == it.second)
			return;
	}*/
	if (catalogue_ == nullptr)
		catalogue_ = new GestionnaireProduits;
    Fournisseur* fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
	catalogue_->ajouter(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
	// TODO : À modifier
    produit->modifierFournisseur(nullptr);
    for(auto it : catalogue_->obtenirConteneur())
    {
        if (produit == (it.second))
        {
			it.second->modifierFournisseur(nullptr);
			catalogue_->supprimer(produit);
        }
    }
}

Produit* Fournisseur::trouverProduitPlusCher() const 
{
	return catalogue_->trouverProduitPlusCher();
}

void Fournisseur::DiminuerPrix(int pourcent) const 
{
	FoncteurDiminuerPourcent diminuer(pourcent);
	catalogue_->pourChaqueElement(diminuer);
}
