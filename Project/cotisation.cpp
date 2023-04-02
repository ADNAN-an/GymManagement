#include "cotisation.h"
#include <iostream>

Cotisation::Cotisation(std::string typeCotisation ,int montant, std::string dateEcheance) {
    this->typeCotisation = typeCotisation;
    this->montant = montant;
    this->dateEcheance = dateEcheance;
}

int Cotisation::getMontant() {
    return montant;
}

void Cotisation::setMontant(int montant) {
    this->montant = montant;
}

std::string Cotisation::getDateEcheance() {
    return dateEcheance;
}

void Cotisation::setDateEcheance(std::string dateEcheance) {
    this->dateEcheance = dateEcheance;
}

std::string Cotisation::getTypeCotisation() {
    return typeCotisation;
}

void Cotisation::setTypeCotisation(std::string typeCotisation) {
    this->typeCotisation = typeCotisation;
}

void Cotisation::mode_payement() {
    int choix;
    std::string typeCotisation;
    std::string dateEcheance;

    std::cout << "\n =============================================================\n";
    std::cout << "\n\n\t\tMethodes de payements et promotions\n\n";
    std::cout << "\n\t 1- Cotisation trimestrielle : 1000Dh";
    std::cout << "\n\t 2- Cotisation mensuelle : 400Dh";
    std::cout << "\n\t 3- Cotisation annuelle : 4000Dh\n";
    std::cout << "\n =============================================================\n\n";
    std::cout << "Choisissez un type de cotisation (Tapez le num) : ";
    std::cin >> choix;

    switch (choix) {
    case 1:
        montant = 1000;
        dateEcheance = "3 mois";
        typeCotisation = "Trimistrielle";
        system("CLS");
        break;
    case 2:
        montant = 400;
        dateEcheance = "1 mois";
        typeCotisation = "Mensuelle";
        system("CLS");
        break;
    case 3:
        montant = 4000;
        dateEcheance = "1 an";
        typeCotisation = "Annuelle";
        system("CLS");
        break;
    default:
        std::cout << "Choix non valide, veuillez réessayer." << std::endl;
        mode_payement();
        break;
    }
    setMontant(montant);
    setDateEcheance(dateEcheance);
    setTypeCotisation(typeCotisation);
}