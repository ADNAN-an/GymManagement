#include "adherent.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
using namespace std;

std::vector<Adherent> listeAdherents;

// Constructeur
Adherent::Adherent(int id, string nom, string telephone, string dateNaissance, string dateAdhesion, vector<Sport> listeSports, Cotisation cotisation) :Personne(id, nom, telephone, dateNaissance) {
    this->dateAdhesion = dateAdhesion;
    this->listeSports = listeSports;
    this->cotisation = cotisation;
}

Adherent::Adherent() {
    // Initialiser les variables membres avec des valeurs par défaut
    dateAdhesion = "";
    listeSports = {};
    cotisation = Cotisation();
}

// Accesseurs (getters)
std::string Adherent::getDateAdhesion() { return dateAdhesion; }
std::vector<Sport> Adherent::getListeSports() { return listeSports; }
Cotisation Adherent::getCotisation() { return cotisation; }

// Mutateurs (setters)
void Adherent::setDateAdhesion(std::string dateAdhesion) { this->dateAdhesion = dateAdhesion; }
void Adherent::setCotisation(Cotisation cotisation) { this->cotisation = cotisation; }
void Adherent::setListeSports(Sport sport) { this->listeSports.push_back(sport); }

//Inscription des nouveaux adherents
void Adherent::inscription() {
    int id;
    string nom, telephone, dateNaissance, dateAdhesion, typeCotisation;
    vector<Sport> listeSports;
    int montant;
    string dateEcheance;
    int nbrA;
    system("CLS");
    cout << "\n\n===========================================================================================\n";
    cout << "\n\n\t\t\t\tINSCRIPTION:";
    cout << "\n\n\n==========================================================================================\n\n";
    // Demander les informations de l'adhérent
    cout << "\n\tSaisir le nombre d'adherents a ajouter\t";
    cin >> nbrA;

    cotisation.mode_payement();
    // Demander les informations de cotisation
    typeCotisation = cotisation.getTypeCotisation();
    montant = cotisation.getMontant();
    dateEcheance = cotisation.getDateEcheance();
    for (int i = 0; i < nbrA; i++) {
        cout << "\n\tEntrez l'identifiant de l'adherent :\t";
        cin >> id;
        cout << "\n\tEntrez le nom de l'adherent :\t";
        cin >> nom;
        cout << "\n\tEntrez le numero de telephone de l'adherent :\t";
        cin >> telephone;
        cout << "\n\tEntrez la date de naissance de l'adherent (JJ/MM/AAAA) :\t";
        cin >> dateNaissance;
        cout << "\n\tEntrez la date d'adhesion de l'adherent (JJ/MM/AAAA) :\t";
        cin >> dateAdhesion;

        // Demander les sports pratiqués par l'adhérent
        int nbSports;
        cout << "\n\tEntrez le nombre de sports pratiques par l'adherent :\t";
        cin >> nbSports;
        for (int i = 0; i < nbSports; i++) {
            int idSport;
            string nomSport;
            cout << "\n\tEntrez l'identifiant du sport :\t";
            cin >> idSport;
            cout << "\n\tEntrez le nom du sport :\t";
            cin >> nomSport;
            Sport sport(idSport, nomSport);
            listeSports.push_back(sport);
        }
        cout<<"\n\n =================================================================================\n\n";
        cout << "\n\tLe membre  " << nom << " a ete cree avec success:" << "\t\n";
        cout<<"\n =================================================================================\n\n";

        Cotisation cotisation(typeCotisation, montant, dateEcheance);

        // Créer l'objet adhérent
        Adherent nouvelAdherent(id, nom, telephone, dateNaissance, dateAdhesion, listeSports, cotisation);

        // Ajouter l'adhérent à la liste des adhérents
        listeAdherents.push_back(nouvelAdherent);


        // Stocker les informations de l'adhérent dans un fichier
        ofstream fichierAdherents("listeAdherents.txt", ios::app);
        if (fichierAdherents) {
            fichierAdherents << nouvelAdherent.getId() << "," << nouvelAdherent.getNom() << "," << nouvelAdherent.getTelephone() << "," << nouvelAdherent.getDateNaissance() << "," << nouvelAdherent.getDateAdhesion() << endl;
        }
        fichierAdherents.close();


    }
    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}

void Adherent::rechercherAdherent() {
    int id;
    system("CLS");
    cout << "\n\n===========================================================================================\n\n";
    cout << "\n\n\t\t\t\tRECHERCHE D'UN MEMBRE:";
    cout << "\n\n\n==========================================================================================\n\n";
    cout << "Saisir l'ID de l'adherent a rechercher";
    cin >> id;
    for (auto a : listeAdherents) {
        if (a.getId() == id) {
            cout << "Adherent trouve" << endl;
            cout << "Informations de l'adhérent:" << endl;
            cout << "Id : " << a.getId() << endl;
            cout << "Nom : " << a.getNom() << endl;
            cout << "Telephone : " << a.getTelephone() << endl;
            cout << "Date de naissance : " << a.getDateNaissance() << endl;
            cout << "Date d'adhesion : " << a.getDateAdhesion() << endl;
            cout << "Liste des sports : ";
            for (unsigned int i = 0; i < a.getListeSports().size(); i++) {
                cout << a.getListeSports()[i].getNom() << " ";
            }
            cout << endl;
            cout << "Cotisation : " << a.getCotisation().getMontant() << " dh," << " de type ," << a.getCotisation().getTypeCotisation() << " echeance au " << a.getCotisation().getDateEcheance() << endl;
            return;
        }
    }
    cout << "\n\tL'adherent n'existe pas\t" << endl;

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}
//Modifier les adherents
void Adherent::modifierAdherent() {
    int id;
    system("CLS");
    cout << "\n\n===========================================================================================\n\n";
    cout << "\n\n\t\t\t\tMODIFICATION D'UN MEMBRE:";
    cout << "\n\n\n==========================================================================================\n\n";
    cout << "Saisir l'ID de l'adherent a modifier";
    cin >> id;
    for (unsigned int i = 0; i < listeAdherents.size(); i++) {
        if (listeAdherents[i].getId() == id) {
            cout << "\n\t" << listeAdherents[i].getId() << "\t" << listeAdherents[i].getNom() << "\t" << listeAdherents[i].getTelephone() << "\t" << listeAdherents[i].getDateNaissance() << "\t";
            cout << "\n\n";
            // Demande à l'utilisateur les nouvelles informations de l'adhérent
            cout << "\n\tEntrez le nouveau nom : \t";
            string nom;
            cin >> nom;
            listeAdherents[i].setNom(nom);

            cout << "\n\tEntrez le nouveau numero de telephone : \t";
            string telephone;
            cin >> telephone;
            listeAdherents[i].setTelephone(telephone);

            cout << "\n\tEntrez la nouvelle date de naissance (JJ/MM/AAAA): \t";
            string dateNaissance;
            cin >> dateNaissance;
            listeAdherents[i].setDateNaissance(dateNaissance);

            cout << "\n\tEntrez la nouvelle date d'adhesion (JJ/MM/AAAA): \t";
            string dateAdhesion;
            cin >> dateAdhesion;
            listeAdherents[i].setDateAdhesion(dateAdhesion);
           
        }
    }

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}

//Afficher les adherents par ID
void Adherent::afficherAdherent() {
    int id;
    system("CLS");
    cout << "Saisir l'ID de l'adherent a afficher";
    cin >> id;
    for (unsigned int i = 0; i < listeAdherents.size(); i++) {
        cout << "\n\n===========================================================================================\n\n";
        cout << "\n\t\t\t\ADHERENT AVEC L'ID :" << id;
        cout << "\n\n\n==========================================================================================\n\n";
        if (listeAdherents[i].getId() == id) {
            cout << "\n\tId : \t" << listeAdherents[i].getId() << endl;
            cout << "\n\tNom :\t" << listeAdherents[i].getNom() << endl;
            cout << "\n\tTelephone :\t" << listeAdherents[i].getTelephone() << endl;
            cout << "\n\tDate de naissance :\t" << listeAdherents[i].getDateNaissance() << endl;
            cout << "\n\tDate d'adhesion : \t" << listeAdherents[i].getDateAdhesion() << endl;
            cout << "\n\tListe des sports : \t";
            for (unsigned int j = 0; j < listeAdherents[i].getListeSports().size(); j++) {
                cout << listeAdherents[i].getListeSports()[j].getNom() << " ";
            }
            cout << endl;
            cout << "\n\tCotisation : " << listeAdherents[i].getCotisation().getMontant() << " dh," << "de type " << listeAdherents[i].getCotisation().getTypeCotisation() << " echeance au " << listeAdherents[i].getCotisation().getDateEcheance() << "\t"<< endl;
        }
    }
    cout << "\n\tL'adherent n'existe pas.\t" << endl;

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}


// Supprimer adhérent
void Adherent::supprimerAdherent() {
    int id;
    system("CLS");
    cout << "\n\n===========================================================================================\n\n";
    cout << "\n\n\t\t\t\tSUPRESSION D'UN ADHERENT:";
    cout << "\n\n\n==========================================================================================\n\n";
    cout << "\n\t Saisir l'ID de l'adherent a supprimer : \t";
    cin >> id;
    for (unsigned int i = 0; i < listeAdherents.size(); i++) {
        if (listeAdherents[i].getId() == id) {
            listeAdherents.erase(listeAdherents.begin() + i);
           system("cls");
        printf("\n\n =================================================================================\n\n");
        cout << "\n\t\tL'adherent  a ete supprime avec success!!\t\n";
        printf("\n =================================================================================\n\n");   
        }
    }
    system("CLS");
    cout << "\tL'adherent n'existe pas." << endl;

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}
