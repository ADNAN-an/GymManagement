#include "equipe.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>

using namespace std;
std::vector<Equipe> listeEquipes;

// Constructeur
Equipe::Equipe(int id, string nom, int entraineur, int nbrJoueurs) {
    this->id = id;
    this->nom = nom;
    this->entraineur = entraineur;
    this->nbrJoueurs = nbrJoueurs;
}

Equipe::Equipe() {
    id = 0;
    nom = "";
    entraineur = 0;
    nbrJoueurs = 0;
} 

// Accesseurs (getters)
int Equipe::getID() { return id; }
string Equipe::getNom() { return nom; }
int Equipe::getEntraineur() { return entraineur; }
int Equipe::getnbrJoueurs() { return nbrJoueurs; }

// Mutateurs (setters)
void Equipe::setID(int id) { this->id = id; }
void Equipe::setNom(string nom) { this->nom = nom;; }
void Equipe::setEntraineur(int entraineur) { this->entraineur = entraineur; }
void Equipe::setnbrJoueurs(int nbrJoueurs) { this->nbrJoueurs = nbrJoueurs; }

// Ajouter une équipe
void Equipe::ajouterEquipe() {
    int id;
    string nom;
    int nbrJoueurs,entraineur;
    system("CLS");
    cout << "\n\n===========================================================================================\n";
    cout << "\n\n\t\t\tCREATION D'UNE EQUIPE:";
    cout << "\n\n\n==========================================================================================\n\n";
    // Demander les informations de l'équipe
    cout << "\n\tEntrez l'identifiant de l'equipe :\t";
    cin >> id;
    cout << "\n\tEntrez le nom de l'equipe :\t";
    cin >> nom;
    cout << "\n\tEntrez le nom de l'entraineur :\t";
    cin >> entraineur;
    cout << "\n\tEntrez le nombre de joueurs :\t";
    cin >> nbrJoueurs;

    cout<<"\n\n =================================================================================\n";
    cout << "\n\t\tL'equipe " << nom << " a ete cree avec succes \t\n";
    cout<<"\n =================================================================================\n\n";
    // Créer l'objet équipe
    Equipe nouvelleEquipe(id, nom, entraineur, nbrJoueurs);

    // Ajouter l'équipe à la liste des équipes
    listeEquipes.push_back(nouvelleEquipe);

    // Stocker les informations de l'équipe dans un fichier
    ofstream fichierEquipes("listeEquipes.txt", ios::app);
    fichierEquipes << nouvelleEquipe.getID() << "," << nouvelleEquipe.getNom() << "," << nouvelleEquipe.getEntraineur() << "," << nouvelleEquipe.getnbrJoueurs() << endl;
    fichierEquipes.close();
}
void Equipe::supprimerEquipe() {
    int id;
    system("CLS");
    cout << "\n\n===========================================================================================\n";
    cout << "\n\n\t\t\tSUPPRESSION D'UNE EQUIPE:";
    cout << "\n\n\n==========================================================================================\n\n";
    // Demander l'identifiant de l'équipe à supprimer
    cout << "\n\tEntrez l'identifiant de l'equipe a supprimer :\t";
    cin >> id;
    // Rechercher l'équipe dans la liste des équipes
    for (int i = 0; i < listeEquipes.size(); i++) {
        if (listeEquipes[i].getID() == id) {
            // Supprimer l'équipe de la liste des équipes
            listeEquipes.erase(listeEquipes.begin() + i);
            cout << "\n\n =================================================================================\n";
            cout << "\n\t\tL'equipe avec l'identifiant " << id << " a ete supprime avec succes \t\n";
            cout << "\n =================================================================================\n\n";
        }
    }
    system("CLS");
    cout << "\n\n ========================================================================================\n";
    cout << "\n\t\tAucune equipe trouve avec cet ID.\t" << endl;
    cout << "\n ========================================================================================\n\n";

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}
void Equipe::modifierEquipe() {
    int id;
    system("CLS");
    cout << "\n\n===========================================================================================\n";
    cout << "\n\n\t\t\tMODIFICATION D'UNE EQUIPE:";
    cout << "\n\n\n==========================================================================================\n\n";
    // Demander l'identifiant de l'équipe à modifier
    cout << "\n\tEntrez l'identifiant de l'equipe à modifier:\t";
    cin >> id;
    // Rechercher l'équipe dans la liste des équipes
    for (int i = 0; i < listeEquipes.size(); i++) {
        if (listeEquipes[i].getID() == id) {
            // Demander les nouvelles informations de l'équipe
            string nom;
            int entraineur;
            int nbrJoueurs;
            cout << "\n\tEntrez le nouveau nom de l'equipe :\t";
            cin >> nom;
            cout << "\n\tEntrez le nouveau nom de l'entraineur :\t";
            cin >> entraineur;
            cout << "\n\tEntrez le nouveau nombre de joueurs :\t";
            cin >> nbrJoueurs;
            // Modifier les informations de l'équipe
            listeEquipes[i].setNom(nom);
            listeEquipes[i].setEntraineur(entraineur);
            listeEquipes[i].setnbrJoueurs(nbrJoueurs);
            cout << "\n\n =================================================================================\n";
            cout << "\n\t\tL'equipe " << nom << "a ete modife avec succes.\t" << endl;
            cout << "\n ========================================================================================\n\n";
            return;
        }
    }
    cout << "\n\n ========================================================================================\n";
    cout << "\n\t\tAucune equipe trouve avec cet ID.\t" << endl;
    cout << "\n ========================================================================================\n\n";

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}

void Equipe::afficherEquipes() {
    system("CLS");
    cout << "\n\n===========================================================================================\n";
    cout << "\n\n\t\t\tLISTE DES EQUIPES:";
    cout << "\n\n\n==========================================================================================\n\n";
    // Vérifier si la liste des équipes est vide
    if (listeEquipes.size() == 0) {
        cout << "Aucune équipe trouvée." << endl;
    }
    else {
        // Afficher les informations de chaque équipe
        for (int i = 0; i < listeEquipes.size(); i++) {
            cout << "ID de l'équipe : " << listeEquipes[i].getID() << endl;
            cout << "Nom de l'équipe : " << listeEquipes[i].getNom() << endl;
            cout << "Entraineur : " << listeEquipes[i].getEntraineur() << endl;
            cout << "Nombre de joueurs : " << listeEquipes[i].getnbrJoueurs() << endl;
            cout << "------------------------------" << endl;
        }
    }
    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}