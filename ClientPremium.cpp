#include "ClientPremium.h"
#include <iostream>

ClientPremium::ClientPremium(unsigned int joursRestants)
    : Client(),
      joursRestants_(joursRestants)
{
}

ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
    : Client(nom, prenom, identifiant, codePostal, codeClient),
      joursRestants_(joursRestants)
{
}

unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}

double ClientPremium::obtenirTotalAPayer() const
{
    double montant = 0;
    for (unsigned int i = 0; i < panier_.size(); i++) {
        double prix = panier_[i]->obtenirPrix();
        montant += prix < 5 ? 0 : prix - 5;
    }
    return montant;
}

void ClientPremium::afficherProfil() const
{
    Client::afficherProfil();
    cout << "\t\tjours restants:\t" << joursRestants_ << endl;
}

void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants_;
}
