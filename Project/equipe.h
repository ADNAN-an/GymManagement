#pragma once
#include <string>
#include <vector>

class Equipe {
private:
    int id;
    std::string nom;
    int nbrJoueurs;// liste des identifiants des joueurs de l'équipe
    int entraineur; // identifiant de l'entraineur de l'équipe

public:
    Equipe(int id, std::string nom, int entraineur, int nbrJoueurs);
    Equipe(); // constructeur par défaut
    int getID();
    std::string getNom();
    int getnbrJoueurs();
    int getEntraineur();
    void setID(int id);
    void setNom(std::string nom);
    void setnbrJoueurs(int nbrJoueurs);
    void setEntraineur(int entraineur);
    void ajouterEquipe(); // méthode pour ajouter une équipe
    void modifierEquipe(); 
    void supprimerEquipe();
    void afficherEquipes();
};

