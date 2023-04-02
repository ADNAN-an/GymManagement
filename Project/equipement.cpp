#include "equipement.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

std::vector<Equipement> listeEquipements;

// Constructeur
Equipement::Equipement(int reference, string libelle, string dateAchat, double prixAchat) {
    this->reference = reference;
    this->libelle = libelle;
    this->dateAchat = dateAchat;
    this->prixAchat = prixAchat;
}

// Initialiser les variables membres avec des valeurs par défaut
Equipement::Equipement() {
    reference = 0;
    libelle = "";
    dateAchat = "";
    prixAchat = 0;
}
// Accesseurs (getters)
int Equipement::getReference() { return reference; }
string Equipement::getLibelle() { return libelle; }
string Equipement::getDateAchat() { return dateAchat; }
double Equipement::getPrixAchat() { return prixAchat; }

// Mutateurs (setters)
void Equipement::setReference(int reference) { this->reference = reference; }
void Equipement::setLibelle(string libelle) { this->libelle = libelle; }
void Equipement::setDateAchat(string dateAchat) { this->dateAchat = dateAchat; }
void Equipement::setPrixAchat(double prixAchat) { this->prixAchat = prixAchat; }

void Equipement::ajouterEquipement() {
    int reference;
    string libelle;
    string dateAchat;
    double prixAchat;
    system("CLS");
    cout << "\n\n===========================================================================================\n";
    cout << "\n\n\t\t\t\tAJOUT D'UN EQUIPEMENT:";
    cout << "\n\n\n==========================================================================================\n\n";
    cout << "\n\tEntrez l'identifiant de l'equipement : \t";
    cin >> reference;
    cout << "\n\tEntrez le libelle de l'equipement : \t";
    cin >> libelle;
    cout << "\n\tEntrez la date d'achat de l'equipement :\t ";
    cin >> dateAchat;
    cout << "\n\tEntrez le prix d'achat de l'equipement :\t ";
    cin >> prixAchat;
    Equipement nouvelEquipement(reference, libelle, dateAchat, prixAchat);
    listeEquipements.push_back(nouvelEquipement);
    // Stocker les informations de l'équipement dans un fichier
    ofstream fichierEquipements("listeEquipements.txt", ios::app);
    if (fichierEquipements) {
        fichierEquipements << nouvelEquipement.getReference() << "," << nouvelEquipement.getLibelle() << "," << nouvelEquipement.getDateAchat() << "," << nouvelEquipement.getPrixAchat() << endl;
    }
    fichierEquipements.close();
    cout << "\n\n ========================================================================================\n";
    cout << "\n\t\t\tEquipement ajoute avec succes.\t" << endl;
    cout << "\n ========================================================================================\n\n";

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}

void Equipement::modifierEquipement() {
    int reference;
    system("CLS");
    cout << "\n\n===========================================================================================\n";
    cout << "\n\n\t\t\t\MOODIFICATION D'UN EQUIPEMENT:";
    cout << "\n\n\n==========================================================================================\n\n";
    cout << "\n\tEntrez la reference de l'equipement a modifier :\t";
    cin >> reference;
    for (int i = 0; i < listeEquipements.size(); i++) {
        if (listeEquipements[i].getReference() == reference) {
            // Demander à l'utilisateur les nouvelles valeurs
            string libelle;
            string dateAchat;
            double prixAchat;
            cout << "\n\tEntrez le nouveau libelle de l'equipement :\t ";
            cin >> libelle;
            cout << "\n\tEntrez la nouvelle date d'achat de l'equipement :\t ";
            cin >> dateAchat;
            cout << "\n\tEntrez le nouveau prix d'achat de l'equipement :\t ";
            cin >> prixAchat;
            // Modifier l'équipement
            listeEquipements[i].setLibelle(libelle);
            listeEquipements[i].setDateAchat(dateAchat);
            listeEquipements[i].setPrixAchat(prixAchat);
            // Stocker les modifications dans le fichier
            ofstream fichierEquipements("listeEquipements.txt");
            if (fichierEquipements) {
                for (int j = 0; j < listeEquipements.size(); j++) {
                    fichierEquipements << listeEquipements[j].getReference() << "," << listeEquipements[j].getLibelle() << "," << listeEquipements[j].getDateAchat() << "," << listeEquipements[j].getPrixAchat() << endl;
                }
            }
            fichierEquipements.close();
            cout << "\n\n ========================================================================================\n";
            cout << "\n\t\t\tEquipement modifie avec succes.\t" << endl;
            cout<<"\n ========================================================================================\n\n";
            return;
        }
    }
    cout << "\n\n ========================================================================================\n";
    cout << "\n\t\tAucun equipement trouve avec cette reference.\t" << endl;
    cout<<"\n ========================================================================================\n\n";

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}

void Equipement::afficherEquipements() {
    system("CLS");

    if (listeEquipements.size() > 0) {
        cout << "\n\n==========================================================================================================\n\n";
        cout << "\n\t\t\tLISTE DES EQUIPEMENTS DU CLUB:";
        cout << "\n\n\n=========================================================================================================\n\n";

        cout << "REFERENCE\tLIBELLE\t\tDATE D'ACHAT\t\tPRIX D'ACHAT\t\n";
        cout << "\n==========================================================================================================\n\n";
        for (int i = 0; i < listeEquipements.size(); i++) {
            cout << listeEquipements[i].getReference()<<"\t\t";
            cout << listeEquipements[i].getLibelle()<< "\t\t";
            cout << listeEquipements[i].getDateAchat() << "\t\t\t";
            cout << listeEquipements[i].getPrixAchat()<<"dh"<< "\t" << endl;
        }
    }
    else {
        printf("\n\n ========================================================================================\n");
        cout << "\n\t\t\tAucun equipement n'a ete enregistre." << endl;
        printf("\n ========================================================================================\n\n");
    }

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}

void Equipement::afficherEquipementParRef() {
    system("CLS");
    int reference;
    cout << "\n\tSaisir la reference d'equipement a afficher:\t";
    cin >> reference;
    for (int i = 0; i < listeEquipements.size(); i++) {
        if (listeEquipements[i].getReference() == reference) {
            cout << "\n\n\n=========================================================================================================\n\n";
            cout << "REFERENCE\tLIBELLE\t\tDATE D'ACHAT\t\tPRIX D'ACHAT\t\n";
            cout << "\n==========================================================================================================\n\n";
            cout <<  listeEquipements[i].getReference() << "\t\t";
            cout <<  listeEquipements[i].getLibelle() << "\t\t";
            cout <<  listeEquipements[i].getDateAchat() << "\t\t\t";
            cout <<  listeEquipements[i].getPrixAchat() << "dh" << "\t" << endl;
            return;
        }
    }
    cout<<"\n\n ========================================================================================\n";
    cout << "\n\t\t\tAucun equipement trouve avec cet identifiant." << endl;
    cout<<"\n ========================================================================================\n\n";

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}

void Equipement::supprimerEquipement() {
    system("CLS");
    int reference;
    cout << "\n\n===========================================================================================\n\n";
    cout << "\n\n\t\t\tSUPRESSION D'UN EQUIPEMENT:";
    cout << "\n\n\n==========================================================================================\n\n";
    cout << "\n\tSaisir la reference d'equipement a supprimer:\t";
    cin >> reference;
    for (int i = 0; i < listeEquipements.size(); i++) {
        if (listeEquipements[i].getReference() == reference) {
            listeEquipements.erase(listeEquipements.begin() + i);
            system("cls");
            cout << "\n\n ========================================================================================\n";
            cout << "\t\tL'equipement avec la reference " << reference << " a ete supprime.\n" << endl;
            cout << "\n ========================================================================================\n\n";
            return;
        }
    }
    system("CLS");
    cout << "\tAucun equipement avec la reference " << reference << " n'a ete trouve." << endl;

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}