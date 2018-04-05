/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

// TODO : Créer la classe GestionnaireGenerique

// TODO : Méthodes :
/*
- ajouter()
- supprime()
- obtenirConteneur()
- pourChaqueElement()
*/
template< typename A, typename C, typename S, typename T >
class GestionnaireGenerique {
public:
	C obtenirConteneur() const { return conteneur_; };
	void ajouter(T* t) {
		A add(conteneur_);
		conteneur_ = add(t);
	};
	void supprimer(T* t) {
		S del(conteneur_);
		conteneur_ = del(t);
	};

	template<typename Predicate>
	void pourChaqueElement(Predicate predicate) {
		for_each(conteneur_.begin(), conteneur.end(), predicate);
	};
protected:
	C conteneur_;
};