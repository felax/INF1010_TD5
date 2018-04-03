#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <vector>
#include "Usager.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"

using namespace std;

class Gestionnaire
{
  public:
    vector<Usager *> obtenirUsagers() const;
    void afficherLesProfils() const;
    double obtenirChiffreAffaires() const;

    void ajouterUsager(Usager *usager);
    void reinitialiser();
    void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;

  private:
    vector<Usager *> usagers_;
};

#endif
