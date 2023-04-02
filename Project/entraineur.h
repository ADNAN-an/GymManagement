#pragma once
#include <string>
#include "personne.h"
#include <fstream>
class Entraineur : public Personne {
private:
    std::string dateEmbauche;
    int salaire;
    int prixHeure;
    std::string typeContrat;

public:
    // Constructeur
    Entraineur(int id, std::string nom, std::string telephone, std::string dateNaissance, std::string dateEmbauche, int salaire, int prixHeure, std::string typeContrat);
    Entraineur();
    // Accesseurs (getters)
    std::string getDateEmbauche() { return dateEmbauche; }
    int getSalaire() { return salaire; }
    int getPrixHeure() { return prixHeure; }
    std::string getTypeContrat() { return typeContrat; }

    // Mutateurs (setters)
    void setDateEmbauche(std::string dateEmbauche) { this->dateEmbauche = dateEmbauche; }
    void setSalaire(int salaire) { this->salaire = salaire; }
    void setPrixHeure(int prixHeure) { this->prixHeure = prixHeure; }
    void setTypeContrat(std::string typeContrat) { this->typeContrat = typeContrat; }

    // Autres methodes
    void ajouterEntraineur();
    void afficherEntraineurs();
    void supprimerEntraineur();
    void rechercherEntraineur();
    void modifierEntraineur();
    void afficherEntraineurParId();
};