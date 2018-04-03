#include <iostream>
#include <iomanip>
#include "Produit.h"
#include "Solde.h"
#include "ProduitAuxEncheres.h"
#include "ProduitSolde.h"
#include "Client.h"
#include "ClientPremium.h"
#include "Fournisseur.h"
#include "GestionnaireProduits.h"
#include "GestionnaireUsagers.h"
#include <vector>
#include "Foncteur.h"

using namespace std;

int main()
{
	FoncteurGenerateurId genIdUsager, genIdProduit;
    GestionnaireUsagers poly;
    Client ratus;
	ratus.modifierReference(genIdUsager());
    Client gaspard("Donada--Vidal", "Gaspard", genIdUsager(), "P4R 1I5", 1997);
    Client rick("S", "Rick", genIdUsager(), "HF1 8H3", 20012003);
    ClientPremium marou;
	marou.modifierReference(genIdUsager());
    ClientPremium julie("Cash", "Julie", genIdUsager(), "HZ9 1J4", 19141918, 50);
    Fournisseur mina;
	mina.modifierReference(genIdUsager());
    Fournisseur martine("Bellaiche", "Martine", genIdUsager(), "H4C 8D4");
    Fournisseur samuel("Kadoury", "Samuel", genIdUsager(), "H1G 2G4");
    Produit sel;
	sel.modifierReference(genIdProduit());
    Produit chaussures(&martine, "chaussures", genIdProduit(), 40.0);
    Produit stylo(&samuel, "stylo", genIdProduit(), 3.0);
    ProduitAuxEncheres sculpture;
	sculpture.modifierReference(genIdProduit());
    ProduitAuxEncheres violoncelle(&martine, "violoncelle", genIdProduit(), 5000.0);
    ProduitSolde saladier;
	saladier.modifierReference(genIdProduit());
    ProduitSolde montre(&mina, "montre", genIdProduit(), 100.0, 30);
    ProduitSolde nem(&samuel, "nem crevettes", genIdProduit(), 2.0);
    poly.ajouter(&gaspard);
    poly.ajouter(&rick);
    poly.ajouter(&martine);
    poly.ajouter(&samuel);
    poly.ajouter(&ratus);
    poly.ajouter(&marou);
    poly.ajouter(&mina);
    poly.ajouter(&julie);

    vector<bool> tests;

    // TEST 01 : le constructeur par défaut de client doit fonctionner
    tests.push_back(ratus.obtenirNom() == "Doe" &&
                    ratus.obtenirPrenom() == "John" &&
                    ratus.obtenirReference() == 0 &&
                    ratus.obtenirCodePostal() == "A1A A1A" &&
                    ratus.obtenirCodeClient() == 0);
    // TEST 02 : le constructeur par paramètres de client doit fonctionner
    tests.push_back(gaspard.obtenirNom() == "Donada--Vidal" &&
                    gaspard.obtenirPrenom() == "Gaspard" &&
                    gaspard.obtenirReference() == 1 &&
                    gaspard.obtenirCodePostal() == "P4R 1I5" &&
                    gaspard.obtenirCodeClient() == 1997);
    // TEST 03 : le constructeur par défaut de client premium doit fonctionner
    tests.push_back(marou.obtenirNom() == "Doe" &&
                    marou.obtenirPrenom() == "John" &&
                    marou.obtenirReference() == 3 && //
                    marou.obtenirCodePostal() == "A1A A1A" &&
                    marou.obtenirCodeClient() == 0 &&
                    marou.obtenirJoursRestants() == 0);
    // TEST 04 : le constructeur par paramètres de client premium doit fonctionner
    tests.push_back(julie.obtenirNom() == "Cash" &&
                    julie.obtenirPrenom() == "Julie" &&
                    julie.obtenirReference() == 4 &&
                    julie.obtenirCodePostal() == "HZ9 1J4" &&
                    julie.obtenirCodeClient() == 19141918 &&
                    julie.obtenirJoursRestants() == 50);
    // TEST 05 : le constructeur par défaut de fournisseur doit fonctionner
    tests.push_back(mina.obtenirNom() == "Doe" &&
                    mina.obtenirPrenom() == "John" &&
                    mina.obtenirReference() == 5 &&
                    mina.obtenirCodePostal() == "A1A A1A");
    // TEST 06 : le constructeur par paramètres de fournisseur doit fonctionner
    tests.push_back(martine.obtenirNom() == "Bellaiche" &&
                    martine.obtenirPrenom() == "Martine" &&
                    martine.obtenirReference() == 6 &&
                    martine.obtenirCodePostal() == "H4C 8D4");
    // TEST 07 : le constructeur par défaut de produit doit fonctionner
    tests.push_back(sel.obtenirNom() == "outil" &&
                    sel.obtenirReference() == 0 &&
                    sel.obtenirFournisseur() == nullptr &&
                    sel.obtenirPrix() == 0.0);
    // TEST 08 : le constructeur par paramètres de produit doit fonctionner
    tests.push_back(stylo.obtenirNom() == "stylo" &&
                    stylo.obtenirReference() == 2 &&
                    stylo.obtenirFournisseur() == &samuel &&
                    stylo.obtenirPrix() == 3.0);
    // TEST 09 : le constructeur par défaut de produit aux enchères doit fonctionner
    tests.push_back(sculpture.obtenirNom() == "outil" &&
                    sculpture.obtenirReference() == 3 &&
                    sculpture.obtenirFournisseur() == nullptr &&
                    sculpture.obtenirPrix() == 0.0 &&
                    sculpture.obtenirPrixInitial() == 0.0);
    // TEST 10 : le constructeur par paramètres de produit aux enchères doit fonctionner
    tests.push_back(violoncelle.obtenirNom() == "violoncelle" &&
                    violoncelle.obtenirReference() == 4 &&
                    violoncelle.obtenirFournisseur() == &martine &&
                    violoncelle.obtenirPrix() == 5000.0 &&
                    violoncelle.obtenirPrixInitial() == 5000.0);
    // TEST 11 : le constructeur par défaut de produit soldé doit fonctionner
    tests.push_back(saladier.obtenirNom() == "outil" &&
                    saladier.obtenirReference() == 5 &&
                    saladier.obtenirFournisseur() == nullptr &&
                    saladier.obtenirPrix() == 0.0 &&
                    saladier.obtenirPourcentageRabais() == 0);
    // TEST 12 : le constructeur par paramètres de produit soldé doit fonctionner
    tests.push_back(nem.obtenirNom() == "nem crevettes" &&
                    nem.obtenirReference() == 7 &&
                    nem.obtenirFournisseur() == &samuel &&
                    nem.obtenirPrix() == 2 &&
                    nem.obtenirPourcentageRabais() == 0);

    // TEST 13 : une surenchère doit être strictement supérieure à l'offre précédente
    poly.encherir(&julie, &violoncelle, 5000.0);
    tests.push_back(julie.obtenirPanier()->obtenirConteneur().size() == 0);
    poly.encherir(&gaspard, &violoncelle, 6000.0);
    poly.encherir(&julie, &violoncelle, 6000.0);
	// TEST 14
    tests.push_back(julie.obtenirPanier()->obtenirConteneur().size() == 0);
    poly.encherir(&julie, &violoncelle, 7000.0);
	// TEST 15
    tests.push_back(julie.obtenirPanier()->obtenirConteneur().size() == 1);
    // TEST 16 : on ne peut pas surencherir sur sa propre enchère
    poly.encherir(&julie, &violoncelle, 8000.0);
    tests.push_back(violoncelle.obtenirPrix() == 7000.0);
    // TEST 17 : surenchérir doit enlever le produit du panier de l'ancien encherisseur
    poly.encherir(&gaspard, &violoncelle, 8000.0);
    tests.push_back(julie.obtenirPanier()->obtenirConteneur().size() == 0);
    // TEST 18 : surenchérir doit ajouter le produit au panier du nouvel enchérisseur
    poly.encherir(&julie, &violoncelle, 9000.0);
    tests.push_back(julie.obtenirPanier()->obtenirConteneur().size() == 1 &&
                    julie.obtenirPanier()->obtenirConteneur().find(violoncelle.obtenirReference())->second->obtenirNom() == "violoncelle");
    // TEST 19 : surenchérir doit mettre à jour l'attribut encherisseur_
    tests.push_back(violoncelle.obtenirEncherisseur() != nullptr &&
                    violoncelle.obtenirEncherisseur()->obtenirPrenom() == "Julie");
    // TEST 20 : surenchérir doit mettre à jour le prix du produit
    tests.push_back(violoncelle.obtenirPrix() == 9000.0);
    // TEST 21 : le prix initial ne doit pas varier
    tests.push_back(violoncelle.obtenirPrixInitial() == 5000.0);

    // TEST 22 : ajouter le produit au client doit l'ajouter au panier
    gaspard.ajouterProduit(&stylo); // produit normal
    gaspard.ajouterProduit(&nem);   // produit soldé
    tests.push_back(gaspard.obtenirPanier()->obtenirConteneur().size() == 2 &&
                    gaspard.obtenirPanier()->obtenirConteneur().find(stylo.obtenirReference())->second->obtenirNom() == "stylo" &&
                    gaspard.obtenirPanier()->obtenirConteneur().find(nem.obtenirReference())->second->obtenirNom() == "nem crevettes");
    // TEST 23 : idem pour client premium
    julie.ajouterProduit(&stylo); // produit normal
    julie.ajouterProduit(&nem);   // produit soldé
    tests.push_back(julie.obtenirPanier()->obtenirConteneur().size() == 3 &&
                    julie.obtenirPanier()->obtenirConteneur().find(stylo.obtenirReference())->second->obtenirNom() == "stylo" &&
                    julie.obtenirPanier()->obtenirConteneur().find(nem.obtenirReference())->second->obtenirNom() == "nem crevettes");
    // TEST 24 : il est possible d'ajouter le même produit deux fois dans le panier
    gaspard.ajouterProduit(&stylo); // produit normal
    gaspard.ajouterProduit(&nem);   // produit soldé
    tests.push_back(gaspard.obtenirPanier()->obtenirConteneur().size() == 4);

	// TEST 25 : enlever un produit doit mettre à jour l'attribut du client
	gaspard.enleverProduit(&stylo);
	tests.push_back(gaspard.obtenirPanier()->obtenirConteneur().size() == 3);

	// TEST 26 : enlever un produit un deuxième fois doit aussi mettre à jour l'attribu du client
	gaspard.enleverProduit(&stylo);
	tests.push_back(gaspard.obtenirPanier()->obtenirConteneur().size() == 2);

    // TEST 27 : idem pour client premium
    julie.ajouterProduit(&stylo); // produit normal
    julie.ajouterProduit(&nem);   // produit soldé
    tests.push_back(julie.obtenirPanier()->obtenirConteneur().size() == 5);

    // TEST 28 : ajouter le produit au fournisseur doit l'ajouter au catalogue
    tests.push_back(martine.obtenirCatalogue()->obtenirConteneur().size() == 2 &&
                    martine.obtenirCatalogue()->obtenirConteneur().find(chaussures.obtenirReference())->second->obtenirNom() == "chaussures" && // normal
                    martine.obtenirCatalogue()->obtenirConteneur().find(violoncelle.obtenirReference())->second->obtenirNom() == "violoncelle"); // enchères
	// TEST 29
    tests.push_back(mina.obtenirCatalogue()->obtenirConteneur().size() == 1 &&
                    mina.obtenirCatalogue()->obtenirConteneur().find(montre.obtenirReference())->second->obtenirNom() == "montre"); // soldé
    // TEST 30 : modifier le fournisseur d'un produit doit ajouter le produit au nouveau fournisseur
    martine.ajouterProduit(&montre);
    tests.push_back(martine.obtenirCatalogue()->obtenirConteneur().size() == 3 &&
                    martine.obtenirCatalogue()->obtenirConteneur().find(chaussures.obtenirReference())->second->obtenirNom() == "chaussures" &&
                    martine.obtenirCatalogue()->obtenirConteneur().find(violoncelle.obtenirReference())->second->obtenirNom() == "violoncelle" &&
                    martine.obtenirCatalogue()->obtenirConteneur().find(montre.obtenirReference())->second->obtenirNom() == "montre");
    // TEST 31 : modifier le fournisseur d'un produit doit retirer le produit du catalogue précédent
    tests.push_back(mina.obtenirCatalogue()->obtenirConteneur().size() == 0);
    // TEST 32 : enlever un produit doit mettre l'attribut fournisseur à jour
    martine.enleverProduit(&montre);
    tests.push_back(montre.obtenirFournisseur() == nullptr);
    // TEST 33 : enlever un produit doit le retirer du catalogue du fournisseur
    tests.push_back(martine.obtenirCatalogue()->obtenirConteneur().size() == 2 &&
                    martine.obtenirCatalogue()->obtenirConteneur().find(chaussures.obtenirReference())->second->obtenirNom() == "chaussures" &&
                    martine.obtenirCatalogue()->obtenirConteneur().find(violoncelle.obtenirReference())->second->obtenirNom() == "violoncelle");
    // TEST 34 : TODO : enlever un produit une deuxième fois ne doit rien faire
    martine.enleverProduit(&montre);
    tests.push_back(martine.obtenirCatalogue()->obtenirConteneur().size() == 2 &&
                    martine.obtenirCatalogue()->obtenirConteneur().find(chaussures.obtenirReference())->second->obtenirNom() == "chaussures" &&
                    martine.obtenirCatalogue()->obtenirConteneur().find(violoncelle.obtenirReference())->second->obtenirNom() == "violoncelle");

    // TEST 35 : réinitialiser doit vider le panier de tous les clients
    poly.reinitialiser();
    tests.push_back(gaspard.obtenirPanier()->obtenirConteneur().size() == 0 &&
                    ratus.obtenirPanier()->obtenirConteneur().size() == 0 &&
                    julie.obtenirPanier()->obtenirConteneur().size() == 0 &&
                    marou.obtenirPanier()->obtenirConteneur().size() == 0 &&
                    rick.obtenirPanier()->obtenirConteneur().size() == 0);
    // TEST 36 : réinitialiser doit mettre à jour l'attribut encherisseur_ quand nécessaire
    tests.push_back(violoncelle.obtenirEncherisseur() == nullptr);
    // TEST 37 : réinitialiser doit remettre les produits aux enchères à leur prix intial
    tests.push_back(violoncelle.obtenirPrix() == violoncelle.obtenirPrixInitial());
    // TEST 38 : réinitialiser doit vider le catalogue de tous les fournisseurs
    tests.push_back(martine.obtenirCatalogue()->obtenirConteneur().size() == 0 &&
                    samuel.obtenirCatalogue()->obtenirConteneur().size() == 0 &&
                    mina.obtenirCatalogue()->obtenirConteneur().size() == 0);
    // TEST 39 : réinitialiser doit mettre à jour l'attribut fournisseur_ quand nécessaire
    tests.push_back(stylo.obtenirFournisseur() == nullptr &&
                    sculpture.obtenirFournisseur() == nullptr &&
                    nem.obtenirFournisseur() == nullptr);

    // TEST 40 : le chiffre d'affaires devrait être nul après une réinitialisation
    tests.push_back(poly.obtenirChiffreAffaires() == 0.0);
    // TEST 41 : le total à payer des clients normaux doit sommer les prix dans le panier
    gaspard.ajouterProduit(&chaussures);       // 40
    gaspard.ajouterProduit(&montre);           // 100 - 30
    poly.encherir(&gaspard, &violoncelle, 20000); // 20000
    tests.push_back(gaspard.obtenirTotalAPayer() == 20110.0);
    // TEST 42 : le total à payer des clients premiums doit prendre ne compte la réduction
    julie.ajouterProduit(&chaussures);       // 35
    julie.ajouterProduit(&montre);           // 100 - 30 - 5
    poly.encherir(&julie, &violoncelle, 21000); // 21000 - 5
    tests.push_back(julie.obtenirTotalAPayer() == 21095.0);
    // TEST 43 : la réduction ne doit pas induire des prix négatifs
    julie.ajouterProduit(&nem); // 0
    tests.push_back(julie.obtenirTotalAPayer() == 21095.0);
    // TEST 44 : la surenchère doit actualiser le prix à payer pour l'ancien encherisseur
    tests.push_back(gaspard.obtenirTotalAPayer() == 110.0);
    // TEST 45 : le total à payer des fournisseurs doit être nul
    samuel.ajouterProduit(&chaussures);
    samuel.ajouterProduit(&montre);
    tests.push_back(samuel.obtenirTotalAPayer() == 0.0);
    // TEST 46 : le chiffre d'affaires doit additionner les totaux à payer
    tests.push_back(poly.obtenirChiffreAffaires() == 110.0 + 21095.0);
    
    // TEST 47 : un usager ne peut pas être ajouté deux fois au gestionnaire
    tests.push_back(poly.obtenirConteneur().size() == 8);
    poly.ajouter(&martine);
	// TEST 48 :
    tests.push_back(poly.obtenirConteneur().size() == 8);

	// TEST 49 : trouver le produit le plus chère doit fonctionner selon les test suivants
	tests.push_back(gaspard.trouverProduitPlusCher()->obtenirReference() == 6 &&
					samuel.trouverProduitPlusCher()->obtenirReference() == 6 &&
					ratus.trouverProduitPlusCher() == nullptr);

	// TEST 50 : diminuer le prix des produits doit mettre a jour tous les produits du fournisseur
	samuel.DiminuerPrix(10);
	//cout << samuel.obtenirCatalogue()->obtenirConteneur().find(6)->second->obtenirPrix() << endl;
	tests.push_back(samuel.obtenirCatalogue()->obtenirConteneur().find(6)->second->obtenirPrix() == 63.0 &&
					samuel.obtenirCatalogue()->obtenirConteneur().find(6)->second->Produit::obtenirPrix() == 90.0 &&
					samuel.obtenirCatalogue()->obtenirConteneur().find(1)->second->obtenirPrix() == 36);

	// TEST 51 : obtenir un vector avec des produit qui ont des prix comprix entre 200 et 2000
	vector<pair<int, Produit*>> intervalleProduit = julie.obtenirPanier()->obtenirProduitsEntre(20, 2000);
	/*for (int i = 0; i < intervalleProduit.size(); i++) {
		cout << "asdfljshfgkjsh" << endl;
		intervalleProduit[i].second->afficher();
	}*/
	tests.push_back(intervalleProduit.size() == 2 &&
		intervalleProduit[0].second->obtenirPrix() >= 20.0 &&
		intervalleProduit[intervalleProduit.size() - 1].second->obtenirPrix() <= 2000.0);

	// TEST 52 : obtenir un produit avec un prix inférieur ou égal à 200
	tests.push_back(julie.obtenirPanier()->obtenirProduitSuivant(&montre)->obtenirNom() == "nem crevettes" &&
					julie.obtenirPanier()->obtenirProduitSuivant(&montre)->obtenirReference() > 6 &&
					julie.obtenirPanier()->obtenirProduitSuivant(&montre) == &nem);

    // fonctions d'affichage
    gaspard.afficherPanier();
    julie.afficherPanier();
    ratus.afficherPanier();
    martine.afficherCatalogue();
    samuel.afficherCatalogue();
    mina.afficherCatalogue();
    poly.afficherProfils();

    cout << "TESTS" << endl;
    for (unsigned int i = 0; i < tests.size(); i++)
    {
        cout << "\tTest " << setfill('0') << setw(2) << i + 1 << "... ";
        if (tests[i])
            cout << "OK!" << endl;
        else
            cout << "ECHEC" << endl;
    }
    return 0;
}
