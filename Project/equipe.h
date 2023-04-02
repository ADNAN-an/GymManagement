#pragma once
#include <string>
#include <vector>

class Equipe {
private:
    int id;
    std::string nom;
    int nbrJoueurs;// liste des identifiants des joueurs de l'�quipe
    int entraineur; // identifiant de l'entraineur de l'�quipe

public:
    Equipe(int id, std::string nom, int entraineur, int nbrJoueurs);
    Equipe(); // constructeur par d�faut
    int getID();
    std::string getNom();
    int getnbrJoueurs();
    int getEntraineur();
    void setID(int id);
    void setNom(std::string nom);
    void setnbrJoueurs(int nbrJoueurs);
    void setEntraineur(int entraineur);
    void ajouterEquipe(); // m�thode pour ajouter une �quipe
    void modifierEquipe(); 
    void supprimerEquipe();
    void afficherEquipes();
};

