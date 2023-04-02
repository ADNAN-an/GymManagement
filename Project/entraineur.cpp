#include "entraineur.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
using namespace std;

std::vector<Entraineur> listeEntraineurs;

// Constructeur
Entraineur::Entraineur(int id, string nom, string telephone, string dateNaissance, string dateEmbauche, int salaire, int prixHeure, string typeContrat) :
    Personne(id, nom, telephone, dateNaissance) {
    this->dateEmbauche = dateEmbauche;
    this->salaire = salaire;
    this->prixHeure = prixHeure;
    this->typeContrat = typeContrat;
}

Entraineur::Entraineur() {
    dateEmbauche = "";
    salaire = 0;
    prixHeure = 0;
    typeContrat = "";
}

//Ajouter un entraineur
void Entraineur::ajouterEntraineur() {
    int id;
    string nom, telephone, dateNaissance, dateEmbauche;
    int salaire=0;
    int prixHeure=0;
    int nbrE=0;
    string typeContrat; //permanent ou vacataire
    cout << "\n\n===========================================================================================\n";
    cout << "\n\n\t\t\t\tAJOUT D'UN ENTRAINEUR:";
    cout << "\n\n\n==========================================================================================\n\n";
    // Demander les informations de l'entraineur
    cout << "\n\tSaisir le nombre d'entraineur a ajoute\t";
    cin >> nbrE;

    for(int i=0;i<nbrE;i++){
        system("CLS");
    cout << "\n\tEntrez l'identifiant de l'entraineur :\t";
    cin >> id;
    cout << "\n\tEntrez le nom de l'entraineur :\t";
    cin >> nom;
    cout << "\n\tEntrez le numero de telephone de l'entraineur :\t";
    cin >> telephone;
    cout << "\n\tEntrez la date de naissance de l'entraineur (JJ/MM/AAAA) :\t";
    cin >> dateNaissance;
    cout << "\n\tEntrez le statut de l'entraineur (permanent ou vacataire) :\t";
    cin >> typeContrat;
    if (typeContrat == "permanent" || typeContrat == "PERMANENT") {
        cout << "\n\tEntrez la date d'embauche de l'entraineur (JJ/MM/AAAA) :\t";
        cin >> dateEmbauche;
        cout << "\n\tEntrez le salaire de l'entraineur :\t";
        cin >> salaire;
    }
    else if (typeContrat == "vacataire") {
        cout << "\n\tEntrez le prix de l'heure de l'entraineur :\t";
        cin >> prixHeure;
    }
    else {
        cout << "\n\tEntrez un statut valide (permanent/vacataire)\t";
        cin >> typeContrat;
    }
    printf("\n\n =================================================================================\n\n");
    cout << "\n\tL'entraineur  " << nom << " a ete cree avec success \t\n";
    printf("\n =================================================================================\n\n");
    // Créer l'objet entraineur
    Entraineur nouvelEntraineur(id, nom, telephone, dateNaissance, dateEmbauche, salaire, prixHeure, typeContrat);

    // Ajouter l'entraineur à la liste des entraineurs
    listeEntraineurs.push_back(nouvelEntraineur);

    // Stocker les informations de l'adhérent dans un fichier
    ofstream fichierEntraineurs("listeEntraineurs.txt", ios::app);
    if (fichierEntraineurs) {
        fichierEntraineurs << nouvelEntraineur.getId() << "," << nouvelEntraineur.getNom() << "," << nouvelEntraineur.getTelephone() << "," << nouvelEntraineur.getDateNaissance() << "," << nouvelEntraineur.getTypeContrat() << endl;
    }
    fichierEntraineurs.close();
}
    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}

//Afficher tous les entraineurs de la liste
void Entraineur::afficherEntraineurs() {
    if (listeEntraineurs.size() == 0) {
        cout << "Il n'y a pas encore d'entraineurs enregistres." << endl;
    }
    else {
        system("CLS");
        cout << "\n\n==========================================================================================================\n\n";
        cout << "\n\t\t\tTOUT LES ENTRAINEURS PERMANENTS DU CLUB:";
        cout << "\n\n\n=========================================================================================================\n\n";

        cout << "ID\tNOM\t\tTelephone\t\tDate Naissance\t\tDate d'embauche\t\tSalaire\n"; 
        cout << "\n==========================================================================================================\n\n";
        for (Entraineur entraineur : listeEntraineurs) {
            if(entraineur.getTypeContrat() == "permanent" || entraineur.getTypeContrat() == "PERMANENT"){
            cout << entraineur.getId()<<"\t";
            cout << entraineur.getNom()<<"\t\t";
            cout << entraineur.getTelephone()<<"\t\t\t";
            cout << entraineur.getDateNaissance() << "\t\t\t";
            cout << entraineur.getDateEmbauche() << "\t";
            cout << entraineur.getSalaire() << "dh" << "\t" << endl;;
            }
         }
        cout << "\n\n==========================================================================================================\n\n";
        cout << "\n\t\t\tTOUT LES ENTRAINEURS VACATAIRES DU CLUB:";
        cout << "\n\n\n=========================================================================================================\n\n";
        cout << "ID\tNOM\t\tTelephone\t\tDate Naissance\t\t\tPrix/H\n";
        cout << "\n==========================================================================================================\n\n";
        for (Entraineur entraineur : listeEntraineurs) {
            if (entraineur.getTypeContrat() == "vacataire" || entraineur.getTypeContrat() == "VACATAIRE") {
                cout << entraineur.getId() << "\t";
                cout << entraineur.getNom() << "\t\t";
                cout << entraineur.getTelephone() << "\t\t\t";
                cout << entraineur.getDateNaissance() << "\t\t\t";
                cout << entraineur.getPrixHeure() << "dh" << "\t" << endl;;
            }
        }
    }
    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}

//Afficher Entraineur par ID
void Entraineur::afficherEntraineurParId() {
    int id;
    system("CLS");
    cout << "\n\tSaisir l'ID de l'entraineur a affiche:\t";
    cin >> id;
    system("CLS");
    if (listeEntraineurs.size() == 0) {
        cout << "\n\t Aucun entraineur enregistre\t";
    }
    for (unsigned int i = 0; i < listeEntraineurs.size(); i++) {
        cout << "\n\n===========================================================================================\n\n";
        cout << "\n\t\t\t\tENTRAINEUR AVEC L'ID :"<< id;
        cout << "\n\n\n==========================================================================================\n\n";
        if (listeEntraineurs[i].getId() == id) {
            cout << "\n\tId : \t" << listeEntraineurs[i].getId() << endl;
            cout << "\n\tNom :\t " << listeEntraineurs[i].getNom() << endl;
            cout << "\n\tTelephone :\t " << listeEntraineurs[i].getTelephone() << endl;
            cout << "\n\tDate de naissance :\t " << listeEntraineurs[i].getDateNaissance() << endl;
            cout << "\n\tType de contrat :\t " << listeEntraineurs[i].getTypeContrat() << endl;
            if (listeEntraineurs[i].getTypeContrat() == "permanent") {
                cout << "\n\tDate d'embauche : \t" << listeEntraineurs[i].getDateEmbauche() << endl;
                cout << "\n\tSalaire :\t " << listeEntraineurs[i].getSalaire() <<"dh" << endl;
            }
            else if (listeEntraineurs[i].getTypeContrat() == "vacataire") {
                cout << "\n\tPrix de l'heure :\t " <<listeEntraineurs[i].getPrixHeure()<< "dh" << endl;
            }
        }
        else {
            cout << "\n\t Aucun entraineur avec l'ID" << id;
        }
    }
    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}
void Entraineur::rechercherEntraineur() {
    int id;
    system("CLS");
    cout << "\n\n===========================================================================================\n\n";
    cout << "\n\t\t\t\RECHERCHE D'UN ENTRAINEUR:";
    cout << "\n\n\n==========================================================================================\n\n";
    cout << "\n\tSaisir l'ID de l'entraineur a rechercher\t";
    cin >> id;
    for (auto e : listeEntraineurs) {
        if (e.getId() == id) {
            cout << "\n\tEntraineur trouve\t"<< endl;
            cout << "\n\tInformations de l'entraineur:\t" << endl;
            cout << "\\tId :\t " << e.getId() << endl;
            cout << "\n\tNom : \t" << e.getNom() << endl;
            cout << "\n\tTelephone : \t" << e.getTelephone() << endl;
            cout << "\n\tDate de naissance :\t " << e.getDateNaissance() << endl;
            cout << "\n\tDate d'embauche :\t" << e.getDateEmbauche() << endl;
            cout << "\n\tType de contrat :\t" << e.getTypeContrat() << endl;
            if (e.getTypeContrat() == "permanent" || e.getTypeContrat() == "PERMANENT") {
                cout << "\n\tDate d'embauche :\t" << e.getDateEmbauche() << endl;
                cout << "\n\tSalaire :\t" << e.getSalaire() << endl;
            }
            else if (e.getTypeContrat() == "vacataire" || e.getTypeContrat() == "VACATAIRE") {
                cout << "\n\tPrix de l'heure :\t" << e.getPrixHeure() << endl;
            }
            return;
        }
    }
    cout << "\n\tL'entraineur n'existe pas\t" << endl;

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}

void Entraineur::supprimerEntraineur() {
    int id;
    system("CLS");
    cout << "\n\n===========================================================================================\n\n";
    cout << "\n\t\t\t\tSUPRESSION D'UN ENTRAINEUR:";
    cout << "\n\n\n==========================================================================================\n\n";
    cout << "\n\tSaisir l'ID de l'entraineur a supprimer\t";
    cin >> id;
    for (unsigned int i = 0; i < listeEntraineurs.size(); i++) {
        if (listeEntraineurs[i].getId() == id) {
            listeEntraineurs.erase(listeEntraineurs.begin() + i);
            cout << "\n\tL'entraineur a été supprimé.\t" << endl;

        }
    }
    system("CLS");
    cout << "\n\tL'entraineur n'existe pas.\t" << endl;

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}

void Entraineur::modifierEntraineur() {
    int id;
    system("CLS");
    cout << "\n\n===========================================================================================\n\n";
    cout << "\n\t\t\t\tMODIFICATION D'UN ENTRAINEUR:";
    cout << "\n\n\n==========================================================================================\n\n";
    cout << "\n\tSaisir l'ID de l'entraineur a modifier :\t ";
    cin >> id;
    for (unsigned int i = 0; i < listeEntraineurs.size(); i++) {
        if (listeEntraineurs[i].getId() == id) {
            // Demande à l'utilisateur les nouvelles informations de l'entraîneur
            cout << "\n\tEntrez le nouveau nom : \t";
            string nom;
            cin >> nom;
            listeEntraineurs[i].setNom(nom);

            cout << "\n\tEntrez le nouveau numero de telephone : \t";
            string telephone;
            cin >> telephone;
            listeEntraineurs[i].setTelephone(telephone);

            cout << "\n\tEntrez la nouvelle date de naissance (JJ/MM/AAAA) : \t";
            string dateNaissance;
            cin >> dateNaissance;
            listeEntraineurs[i].setDateNaissance(dateNaissance);

            cout << "\n\tEntrez la nouvelle date d'embauche (JJ/MM/AAAA) :\t ";
            string dateEmbauche;
            cin >> dateEmbauche;
            listeEntraineurs[i].setDateEmbauche(dateEmbauche);

            // Modification du contrat
            cout << "\n\tEntrez le nouveau type de contrat (Vacataire/Permanent) : \t";
            string typeContrat;
            cin >> typeContrat;
            listeEntraineurs[i].setTypeContrat(typeContrat);

            if (typeContrat == "Vacataire" || typeContrat == "VACATAIRE") {
                cout << "\n\tEntrez le nouveau prix par heure : \t";
                int prixParHeure;
                cin >> prixParHeure;
                listeEntraineurs[i].setPrixHeure(prixParHeure);
            }
            else if (typeContrat == "Permanent" || typeContrat == "PERMANENT") {
                cout << "\n\tEntrez le nouveau salaire : \t";
                int salaire;
                cin >> salaire;
                listeEntraineurs[i].setSalaire(salaire);
            }
            cout << "\n\n ========================================================================================\n";
            cout << "\n\tModification terminee\t"<< endl;
            cout << "\n\n ========================================================================================\n";
            return;
        }
    }
    cout << "\n\n ========================================================================================\n";
    cout << "\n\tL'entraineur n'existe pas\t"<< endl;
    cout << "\n\n ========================================================================================\n";

    cout << "Appuyez sur Entree pour revenir au menu principale:";
    getchar();
}
