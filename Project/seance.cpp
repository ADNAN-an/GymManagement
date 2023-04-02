#include "seance.h"
#include <iostream>
#include <vector>
#include <fstream>
 
std::vector<Seance> listeSeances;
using namespace std;

Seance::Seance(int id,string nom, string salle, string heure, string jour, int idcoach, string namecoach) {
    this-> id = id;
	this->nom = nom;
	this->salle = salle;
	this->heure = heure;
	this->jour = jour;
	this->idcoach = idcoach;
	this->namecoach = namecoach;
}

Seance::Seance() {
    id = 0;
    nom = "";
    salle = "";
    heure = "";
    jour = "";
    idcoach = 0;
    namecoach = "";
}

int Seance::getID() { return id; }
string Seance::getNom() { return nom; }
string Seance::getSalle() { return salle; }
string Seance::getHeure() { return heure; }
string Seance::getJour() { return jour; }
int Seance::getIdCoach() { return idcoach; }
string Seance::getNameCoach() { return namecoach; }

void Seance::setID(int id) { this->id = id; }
void Seance::setNom(string nom) { this->nom = nom; }
void Seance::setSalle(string salle) { this->salle = salle; }
void Seance::setHeure(string heure) { this->heure = heure; }
void Seance::setJour(string jour) { this->jour = jour; }
void Seance::setIdCoach(int idcoach) { this->idcoach = idcoach; }
void Seance::setNameCoach(string namecoach) { this->namecoach = namecoach; }

void Seance::ajouterSeance() {
    int id;
    string nom;
    string salle;
    string heure;
    string jour;
    int idcoach;
    string namecoach;
    system("CLS");
    cout << "\n\n===========================================================================================\n";
    cout << "\n\n\t\t\tPLANIFICATION D'UNE SEANCE D'ENTRAINEMENT:";
    cout << "\n\n\n==========================================================================================\n\n";
    cout << "\n\tEntrez l'id de la seance :\t ";
    cin >> id;
    cout << "\n\tEntrez le nom de la seance :\t ";
    cin >> nom;
    cout << "\n\tEntrez la salle ou aura lieu la seance : \t";
    cin >> salle;
    cout << "\n\tEntrez l'heure de debut de la seance (format hh:mm) :\t ";
    cin >> heure;
    cout << "\n\tEntrez le jour de la seance (format jj/mm/aaaa) : \t";
    cin >> jour;
    cout << "\n\tEntrez l'identifiant de l'entraineur encadrant : \t";
    cin >> idcoach;
    cout << "\n\tEntrez le nom de l'entraineur encadrant :\t ";
    cin >> namecoach;
    Seance nouvelleSeance(id,nom, salle, heure, jour, idcoach, namecoach);
    listeSeances.push_back(nouvelleSeance);
    // Stocker les informations de la séance dans un fichier
    ofstream fichierSeances("listeSeances.txt", ios::app);
    if (fichierSeances) {
        fichierSeances << nouvelleSeance.getID() << "," << nouvelleSeance.getNom() << "," << nouvelleSeance.getSalle() << "," << nouvelleSeance.getHeure() << "," << nouvelleSeance.getJour() << "," << nouvelleSeance.getIdCoach() << "," << nouvelleSeance.getNameCoach() << endl;
    }
    fichierSeances.close();
    cout << "\n\n ========================================================================================\n";
    cout << "\n\t\t\tSeance ajoutee avec succes.\t" << endl;
    cout << "\n ========================================================================================\n";
}

void Seance::modifierSeance() {
    int id;
    string nom;
    string salle;
    string heure;
    string jour;
    int idcoach;
    string namecoach;
    system("CLS");
    cout << "\n\n===========================================================================================\n\n";
    cout << "\n\t\t\tMODIFICATION D'UNE SEANCE D'ENTRAINEMENT:";
    cout << "\n\n\n==========================================================================================\n\n";
    cout << "\n\tEntrez l'ID de la seance a modifier :\t ";
    cin >> id;
    for (int i = 0; i < listeSeances.size(); i++) {
        if (listeSeances[i].getID() == id) {
            cout << "\n\tEntrez le nouveau nom de la seance :\t ";
            cin >> nom;
            listeSeances[i].setNom(nom);
            cout << "\n\tEntrez la nouvelle salle de la seance :\t ";
            cin >> salle;
            listeSeances[i].setSalle(salle);
            cout << "\n\tEntrez la nouvelle heure de la seance :\t ";
            cin >> heure;
            listeSeances[i].setHeure(heure);
            cout << "\n\tEntrez le nouveau jour de la seance : \t";
            cin >> jour;
            listeSeances[i].setJour(jour);
            cout << "\n\tEntrez l'ID du nouveau coach : \t";
            cin >> idcoach;
            listeSeances[i].setIdCoach(idcoach);
            cout << "\n\tEntrez le nom du nouveau coach : \t";
            cin >> namecoach;
            listeSeances[i].setNameCoach(namecoach);
            cout << "\n\n ========================================================================================\n";
            cout << "\n\t\tLa séance a ete modifiee avec succes.\t" << endl;
            cout << "\n ========================================================================================\n";
            return;
        }
    }
    cout<<"\n\n ========================================================================================\n";
    cout << "\n\t\tAucune seance trouvee avec l'ID specifie.\t" << endl;
    cout<<"\n ========================================================================================\n";
}

void Seance::afficherSeance() {
    system("CLS");

    if (listeSeances.size() > 0) {
        cout << "\n\n==========================================================================================================\n\n";
        cout << "\n\t\t\tLISTE DES SEANCES DU CLUB:";
        cout << "\n\n\n=========================================================================================================\n\n";

        cout << "NOM\t\tSALLE\t\tHEURE\t\tJOUR\t\tID COACH\t\tNOM COACH\t\n";
        cout << "\n==========================================================================================================\n\n";
        for (int i = 0; i < listeSeances.size(); i++) {
            cout << listeSeances[i].getNom() << "\t\t";
            cout << listeSeances[i].getSalle() << "\t\t";
            cout << listeSeances[i].getHeure() << "\t\t";
            cout << listeSeances[i].getJour() << "\t\t";
            cout << listeSeances[i].getIdCoach() << "\t\t\t";
            cout << listeSeances[i].getNameCoach() << "\t" << endl;
        }
    }
    else {
        printf("\n\n ========================================================================================\n");
        cout << "\n\t\t\tAucune séance n'a été enregistrée." << endl;
        printf("\n ========================================================================================\n\n");
    }
}

void Seance::supprimerSeance() {
    system("CLS");
    int id;
    cout << "\n\n===========================================================================================\n\n";
    cout << "\n\n\t\t\tSUPRESSION D'UNE SEANCE D'ENTRAINEMENT:";
    cout << "\n\n\n==========================================================================================\n";
    cout << "\n\tSaisir l'identifiant de la seance a supprimer:\t";
    cin >> id;
    for (int i = 0; i < listeSeances.size(); i++) {
        if (listeSeances[i].getID() == id) {
            listeSeances.erase(listeSeances.begin() + i);
            system("cls");
            cout << "\n\n ========================================================================================\n";
            cout << "\t\tLa seance avec l'identifiant " << id << " a ete supprimee.\n" << endl;
            cout << "\n ========================================================================================\n\n";
            return;
        }
    }
    system("CLS");
    cout << "\tAucune seance avec l'identifiant " << id << " n'a ete trouvee." << endl;
}
