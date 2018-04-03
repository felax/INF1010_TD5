#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

void Gestionnaire::afficherLesProfils() const
{
    cout << "PROFILS" << endl;
    for (unsigned int i = 0; i < usagers_.size(); i++)
        usagers_[i]->afficherProfil();
    cout << endl;
}

double Gestionnaire::obtenirChiffreAffaires() const
{
    double chiffreAffaires = 0;
    for (unsigned int i = 0; i < usagers_.size(); i++)
        chiffreAffaires += usagers_[i]->obtenirTotalAPayer();
    return chiffreAffaires;
}

void Gestionnaire::ajouterUsager(Usager *usager)
{
    for (unsigned int i = 0; i < usagers_.size(); i++)
        if (usagers_[i] == usager)
            return;
    usagers_.push_back(usager);
}

void Gestionnaire::reinitialiser()
{
    for (unsigned int i = 0; i < usagers_.size(); i++)
        usagers_[i]->reinitialiser();
}

void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
    if (produit->obtenirPrix() < montant)
        produit->mettreAJourEnchere(client, montant);
}
