#include "personne.h"

// Constructeur

Personne::Personne(int id, std::string nom, std::string telephone, std::string dateNaissance) {
    this->id = id;
    this->nom = nom;
    this->telephone = telephone;
    this->dateNaissance = dateNaissance;
}
Personne::Personne() {
    id = 0;
    nom = "";
    telephone = "";
    dateNaissance = "";
}
// Accesseurs (getters)
int Personne::getId() { return id; }
std::string Personne::getNom() { return nom; }
std::string Personne::getTelephone() { return telephone; }
std::string Personne::getDateNaissance() { return dateNaissance; }

// Mutateurs (setters)
void Personne::setNom(std::string nom) { this->nom = nom; }
void Personne::setTelephone(std::string telephone) { this->telephone = telephone; }
void Personne::setDateNaissance(std::string dateNaissance) { this->dateNaissance = dateNaissance; }
