#include "Fournisseur.h"
#include <iostream>

Fournisseur::Fournisseur()
    : Usager()
{
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal)
{
	// TODO : À modifier
}

vector<Produit *> Fournisseur::obtenirCatalogue() const
{
	// TODO : À modifier
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
	// TODO : À modifier
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
    for (unsigned int i = 0; i < catalogue_.size(); i++)
        catalogue_[i]->afficher();
    cout << endl;
}

void Fournisseur::afficher() const
{
	// TODO : À modifier
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << catalogue_.size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
	// TODO : À modifier
    for (unsigned int i = 0; i < catalogue_.size(); i++)
        catalogue_[i]->modifierFournisseur(nullptr);
    catalogue_.clear();
}

void Fournisseur::ajouterProduit(Produit *produit)
{
	// TODO : À modifier
    for (unsigned int i = 0; i < catalogue_.size(); i++)
        if (catalogue_[i] == produit)
            return;
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
    catalogue_.push_back(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
	// TODO : À modifier
    produit->modifierFournisseur(nullptr);
    for (unsigned int i = 0; i < catalogue_.size(); i++)
    {
        if (catalogue_[i] == produit)
        {
            catalogue_[i] = catalogue_[catalogue_.size() - 1];
            catalogue_.pop_back();
            return;
        }
    }
}
