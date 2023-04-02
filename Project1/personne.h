#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>

class Personne {
protected:
    int id;
    std::string nom;
    std::string telephone;
    std::string dateNaissance;

public:
    // Constructeur
    Personne(int id, std::string nom, std::string telephone, std::string dateNaissance);
    Personne();
    // Accesseurs (getters)
    int getId();
    std::string getNom();
    std::string getTelephone();
    std::string getDateNaissance();

    // Mutateurs (setters)
    void setNom(std::string nom);
    void setTelephone(std::string telephone);
    void setDateNaissance(std::string dateNaissance);
};

#endif