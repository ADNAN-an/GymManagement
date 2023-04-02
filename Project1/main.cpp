#include <iostream>
#include "personne.h"
#include "adherent.h"
#include "sport.h"
#include "cotisation.h"
#include "entraineur.h"
#include "equipement.h"
#include "seance.h"
#include "equipe.h"
#include <cstdio>

using namespace std;


void gestionAdherents() {
    int choice;
    Adherent adherent;
    system("cls");
    cout << "\n\n=============================================================\n\n";
    cout << "\n\n\tGESTION DES ADHERENTS:";
    cout << "\n\n\t1. CREE UN ADHERENT";
    cout << "\n\t2. AFFICHER TOUS LES ADHERENTS";
    cout << "\n\t3. RECHERCHER UN ADHERENT";
    cout << "\n\t4. MODIFIER UN ADHERENT";
    cout << "\n\t5. SUPPRIMER UN ADHERENT";
    cout << "\n\t6. RETOUR";
    cout << "\n\n=============================================================\n\n";
    cout << ("\n\n\tVOTRE CHOIX:\t");
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        adherent.inscription();
        getchar();
        getchar();
        break;

    case 2:
        system("cls");
        adherent.afficherAdherent();
        getchar();
        break;
    case 3:
        system("cls");
        adherent.rechercherAdherent();
        getchar();
        break;

    case 4:
        system("cls");
        adherent.modifierAdherent();
        getchar();
        break;

    case 5:
        system("cls");
        adherent.supprimerAdherent();
        getchar();
        break;

    case 6:
        break;

    default:
        cout << "\n\n=============================================================\n\n";
        cout << "\n\n\tVeuillez saisir un chiffre parmi les choix" << endl;
    }
}

void gestionEntraineurs() {
    int choice;
    Entraineur entraineur;
    system("cls");
    cout << "\n\n=============================================================\n\n";
    cout << "\n\n\tGESTION DES ENTRAINEURS:";
    cout << "\n\n\t1. CREER UN ENTRAINEUR";
    cout << "\n\t2. AFFICHER TOUS LES ENTRAINEURS";
    cout << "\n\t3. AFFICHER UN ENTRAINEUR PAR ID";
    cout << "\n\t4. RECHERCHE UN ENTRAINEUR";
    cout << "\n\t5. MODIFIER UN ENTRAINEUR";
    cout << "\n\t6. SUPPRIMER UN ENTRAINEUR";
    cout << "\n\t7. RETOUR";
    cout << "\n\n=============================================================\n\n";
    cout << ("\n\n\tVOTRE CHOIX:\t");
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        entraineur.ajouterEntraineur();
        getchar();
        getchar();
        break;
    case 2:
        system("cls");
        entraineur.afficherEntraineurs();
        getchar();
        getchar();
        break;
    case 3:
        system("cls");
        entraineur.afficherEntraineurParId();
        getchar();
        getchar();
        break;
    case 4:
        system("cls");
        entraineur.rechercherEntraineur();
        getchar();
        getchar();
        break;
    case 5:
        system("cls");
        entraineur.modifierEntraineur();
        getchar();
        getchar();
        break;
    case 6:
        system("cls");
        entraineur.supprimerEntraineur();
        getchar();
        getchar();
        break;
    case 7:
        break;

    default:
        cout << "\n\n=============================================================\n\n";
        cout << "\n\n\tVeuillez saisir un chiffre parmi les choix" << endl;
    }
}

void gestionSeances() {
    int choice;
    Seance seance;
    system("cls");
    cout << "\n\n=============================================================\n\n";
    cout << "\n\n\tGESTION DES SCEANCES:";
    cout << "\n\n\t1. PLANIFIER UNE SCEANCE";
    cout << "\n\t2. MODIFIER UNE SCEANCE";
    cout << "\n\t3. SUPPRIMER UNE SCEANCE";
    cout << "\n\t4. AFFICHER LES SCEANCES";
    cout << "\n\t5. RETOUR";
    cout << "\n\n=============================================================\n\n";
    cout << ("\n\n\tVOTRE CHOIX:\t");
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        seance.ajouterSeance();
        getchar();
        getchar();
        break;
    case 2:
        system("cls");
        seance.modifierSeance();
        getchar();
        getchar();
        break;
    case 3:
        system("cls");
        seance.supprimerSeance();
        getchar();
        getchar();
        break;

    case 4:
        system("cls");
        seance.afficherSeance();
        getchar();
        getchar();
        break;

    case 5:
        break;

    default:
        cout << "\n\n=============================================================\n\n";
        cout << "\n\n\tVeuillez saisir un chiffre parmi les choix" << endl;
    }

}

void gestionEquipements()
{
    int choice;
    Equipement equipement;
    system("cls");
    cout << "\n\n=============================================================\n\n";
    cout << "\n\n\tGESTION DES EQUIPEMENTS:";
    cout << "\n\n\t1. AJOUTER UN NOUVEl EQUIPEMENT";
    cout << "\n\t2. AFFICHER TOUS LES EQUIPEMENTS";
    cout << "\n\t3. AFFICHER UN EQUIPEMENT PAR REFERENCE";
    cout << "\n\t4. MODIFIER UN EQUIPEMENT";
    cout << "\n\t5. SUPPRIMER UN EQUIPEMENT";
    cout << "\n\t6. RETOUR";
    cout << "\n\n=============================================================\n\n";
    cout << ("\n\n\tVOTRE CHOIX:\t");
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        equipement.ajouterEquipement();
        getchar();
        getchar();
        break;
    case 2:
        system("cls");
        equipement.afficherEquipements();
        getchar();
        getchar();
        break;

    case 3:
        system("cls");
        equipement.afficherEquipementParRef();
        getchar();
        getchar();
        break;
    case 4:
        system("cls");
        equipement.modifierEquipement();
        getchar();
        getchar();
        break;
    case 5:
        system("cls");
        equipement.supprimerEquipement();
        getchar();
        getchar();
        break;
    case 6:
        break;

    default:
        cout << "\n\n=============================================================\n\n";
        cout << "\n\n\tVeuillez saisir un chiffre parmi les choix" << endl;
    }


}
void gestionEquipes()
{
    int choice;
    Equipe equipe;
    system("cls");
    cout << "\n\n=============================================================\n\n";
    cout << "\n\n\tGESTION DES EQUIPES:";
    cout << "\n\n\t1. CREER UNE EQUIPE";
    cout << "\n\t2. AFFICHER UNE EQUIPE";
    cout << "\n\t3. MODIFIER UNE EQUIPE";
    cout << "\n\t4. SUPPRIMER UNE SCEANCE";
    cout << "\n\t5. RETOUR";
    cout << "\n\n=============================================================\n\n";
    cout << ("\n\n\tVOTRE CHOIX:\t");
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        equipe.ajouterEquipe();
        getchar();
        getchar();
        break;
    case 2:
        system("cls");
        equipe.afficherEquipes();
        getchar();
        getchar();
        break;
    case 3:
        system("cls");
        equipe.modifierEquipe();
        getchar();
        getchar();
        break;

    case 4:
        system("cls");
        equipe.supprimerEquipe();
        getchar();
        getchar();
        break;
    case 5:
        break;

    default:
        cout << "\n\n=============================================================\n\n";
        cout << "\n\n\tVeuillez saisir un chiffre parmi les choix " << endl;
    }

}
void main_menu() {
    int choice;
    cout << "\n=============================================================\n";
    cout << "\n\n\tSYSTEME DE GESTION DU CLUB:";
    cout << "\n\n\t1. GESTION DES MEMBRES";
    cout << "\n\t2. GESTION DES ENTRAINEURS";
    cout << "\n\t3. GESTION DES SCEANCES";
    cout << "\n\t4. GESTION DES EQUIPEMENTS";
    cout << "\n\t5. GESTION DES EQUIPES";
    cout << "\n\t6. QUITTER";
    cout << "\n\n=============================================================\n\n";

    cout << ("\n\n\tVOTRE CHOIX:\t");
    cin >> choice;

    switch (choice)
    {
    case 1:
        gestionAdherents();
        system("cls");
        main_menu();

    case 2:
        gestionEntraineurs();
        system("cls");
        main_menu();
        break;

    case 3:
        gestionSeances();
        system("cls");
        main_menu();
        break;

    case 4:
        gestionEquipements();
        system("cls");
        main_menu();
        break;
    case 5:
        gestionEquipes();
        system("cls");
        main_menu();
        break;

    case 6:
        //Quitter Le Programme
        break;

    default:
        cout << "Veuillez saisir un chiffre parmi les choix " << endl;
    }
}
int main() {
   
    main_menu();
 
	return 0;
}