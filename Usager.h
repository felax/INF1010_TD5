#ifndef USAGER_H
#define USAGER_H

#include "Produit.h"
#include <string>

using namespace std;

class Usager
{
  public:
    Usager(const string &nom = "Doe", const string &prenom = "John",
           int identifiant = 0, const string &codePostal = "A1A A1A");

    string obtenirNom() const;
    string obtenirPrenom() const;
    int obtenirReference() const;
    string obtenirCodePostal() const;
    virtual double obtenirTotalAPayer() const;
    virtual void afficher() const = 0;

    void modifierNom(const string &nom);
    void modifierPrenom(const string &prenom);
    void modifierReference(int identifiant);
    void modifierCodePostal(const string &codePostal);
    virtual void reinitialiser() = 0;
    virtual void ajouterProduit(Produit *produit) = 0;
    virtual void enleverProduit(Produit *produit) = 0;

  private:
    string nom_;
    string prenom_;
    int reference_;
    string codePostal_;
};

#endif
