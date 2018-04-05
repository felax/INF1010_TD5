/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include<map>
#include<algorithm>
#include<set>

// TODO : Créer le FoncteurEgal
template< typename T >
class FoncteurEgal {
public:
	FoncteurEgal(T* t) : t_(t) {};
	bool operator() (pair<int, T*> pair) const {
		if (*pair.second == *t_)
			return true;
		else
			return false;
	};
private:
	T* t_;
};


// TODO : Créer le FoncteurGenerateurId
/*
Attributs :
- id_;
Méthodes :
- operator(); Incrémenter id_ à chaque appel
*/
class FoncteurGenerateurId {
public:
	FoncteurGenerateurId() : id_(0) {};
	void operator() () {
		id_++;
	};
private:
	int id_;
};

// TODO : Créer le FoncteurDiminuerPourcent
/*
Attributs :
- pourcentage_;
Méthodes :
- operator(); Calule le nouveau prix du Produit de la pair passé en paramètre et le modifie
*/
class FoncteurDiminuerPourcent {
public:
	FoncteurDiminuerPourcent(int pourcentage) : pourcentage_(pourcentage) {};
	void operator() (pair<int, Produit*> pair) const {
		double tempPrix = pair.second->obtenirPrix;
		tempPrix *= 1 - (pourcentage_ / 100);
		pair.second->modifierPrix(tempPrix);
	};
private:
	int pourcentage_;
};

// TODO : Créer le FoncteurIntervalle
/*
Attributs :
- borneInf_;
- borneSup_;
Méthodes :
- operator(); Vérifie que le Produit associé à la pair passé en paramètre est compris entre les bornes borneInf_ et borneSup_ (retourne un booléen)
*/
class FoncteurIntervalle {
public:
	FoncteurIntervalle(double inf, double sup) : borneInf_(inf), borneSup_(sup) {};
	bool operator() (pair<int, Produit*> pair) const {
		if (pair.second->obtenirPrix <= borneSup_ && pair.second->obtenirPrix >= borneInf_)
			return true;
		else
			return false;
	};
private:
	double borneInf_, borneSup_;
};

// TODO : Créer le Foncteur AjouterProduit
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Ajoute dans la multimap la pair passé par paramètre et retourne la multimap_;
*/

class AjouterProduit {
public:
	AjouterProduit(multimap<int, Produit*>& multimap) : multimap_(multimap) {};
	multimap<int, Produit*>& operator() (Produit* produit) {
		multimap_.insert(pair<int, Produit*>(produit->obtenirReference, produit));
		return multimap_;
	};
private:
	multimap<int, Produit*>& multimap_;
};

// TODO : Créer le Foncteur SupprimerProduit
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'élément.
*/
class SupprimerProduit {
public:
	SupprimerProduit(multimap<int, Produit*>& multimap) : multimap_(multimap) {};
	multimap<int, Produit*>& operator() (Produit* produit) {
		auto it = find_if(multimap_.begin(), multimap_.end(), FoncteurEgal<Produit>(produit));
		if (it != multimap_.end())
			multimap_.erase(it);
		return multimap_;
	};
private:
	multimap<int, Produit*>& multimap_;
}; 

//TODO : Créer le Foncteur AjouterUsager
/*
Attributs :
- &set;
Méthodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
class AjouterUsager {
public:
	AjouterUsager(set<Usager*>& set) : set_(set) {};
	set<Usager*>& operator() (Usager* usager) {
		set_.insert(usager);
		return set_;
	};
private:
	set<Usager*>& set_;
};

class SupprimerUsager {
public:
	SupprimerUsager(set<Usager*>& set) : set_(set) {};
	set<Usager*>& operator() (Usager* usager) {
		auto it = set_.find(usager);
		if (it != set_.end())
			set_.erase(it);
		return set_;
	};
private:
	set<Usager*>& set_;
};