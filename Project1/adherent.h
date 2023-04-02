#ifndef ADHERENT_H
#define ADHERENT_H

#include <vector>
#include <string>
#include "personne.h"
#include "sport.h"
#include "cotisation.h"

class Adherent : public Personne {
private:
    std::string dateAdhesion;
    std::vector<Sport> listeSports;
    Cotisation cotisation;

public:
    // Constructeur
    Adherent(int id, std::string nom, std::string telephone, std::string dateNaissance, std::string dateAdhesion, std::vector<Sport> listeSports, Cotisation cotisation);

    // Accesseurs (getters)
    std::string getDateAdhesion();
    std::vector<Sport> getListeSports();
    Cotisation getCotisation();
    Adherent();
    // Mutateurs (setters)
    void setDateAdhesion(std::string dateAdhesion);
    void setCotisation(Cotisation cotisation);
    void setListeSports(Sport sport);

    // Autres méthodes
    void inscription();
    void rechercherAdherent();
    void modifierAdherent();
    void afficherAdherent();
    void supprimerAdherent();
};

#endif
