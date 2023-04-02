#pragma once
#include <string>

class Equipement
{
protected:
    int reference;
    std::string libelle;
    std::string dateAchat;
    double prixAchat;
public:
    // Constructeur
    Equipement(int reference, std::string libelle, std::string dateAchat, double prixAchat);
    Equipement();
    // Accesseurs (getters)
    int getReference();
    std::string getLibelle();
    std::string getDateAchat();
    double getPrixAchat();

    // Mutateurs (setters)
    void setReference(int reference);
    void setLibelle(std::string libelle);
    void setDateAchat(std::string dateAchat);
    void setPrixAchat(double prixAchat);

    // Autres Methodes 
    void ajouterEquipement();
    void modifierEquipement();
    void afficherEquipements();
    void afficherEquipementParRef();
    void supprimerEquipement();
};

