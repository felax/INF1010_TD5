#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"

using namespace std;

class Client : public Usager
{
  public:
    Client(unsigned int codeClient = 0);
    Client(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient = 0);

    unsigned int obtenirCodeClient() const;
	void modifierCodeClient(unsigned int codeClient);
	// TODO : Modifier ses méthodes : -------------------
    vector<Produit *> obtenirPanier() const;
    virtual double obtenirTotalAPayer() const;
    void afficherPanier() const;
    virtual void afficher() const;
    virtual void enleverProduit(Produit *produit);
    virtual void ajouterProduit(Produit *produit);
    virtual void reinitialiser();
	// --------------------------------------------------

	// TODO : Implémenter cette méthodes : 
	Produit* trouverProduitPlusCher() const;
  
  protected:
    vector<Produit *> panier_;

  private:
    unsigned int codeClient_;
};

#endif
