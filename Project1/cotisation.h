#ifndef COTISATION_HPP
#define COTISATION_HPP
#include <string>

class Cotisation {
protected:
    int montant;
    std::string dateEcheance;
    std::string typeCotisation;

public:
    Cotisation(std::string typeCotisation="" ,int montant = 0, std::string dateEcheance = "");
    int getMontant();
    void setMontant(int montant);
    std::string getDateEcheance();
    void setDateEcheance(std::string dateEcheance);
    std::string getTypeCotisation();
    void setTypeCotisation(std::string typeCotisation);
    void mode_payement();
};

#endif