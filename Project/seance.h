#pragma once
#include <string>

class Seance {
protected:
	int id;
	std::string nom;
	std::string salle;
	std::string heure;
	std::string jour;
	int idcoach;
	std::string namecoach;

public:
	// Constructeur
	Seance(int id,std::string nom, std::string salle, std::string heure, std::string jour, int idcoach, std::string namecoach);
	Seance();
	// Accesseurs (getters)
	int getID();
	std::string getNom();
	std::string getSalle();
	std::string getHeure();
	std::string getJour();
	int getIdCoach();
	std::string getNameCoach();

	// Mutateurs (setters)
	void setID(int id);
	void setNom(std::string nom);
	void setSalle(std::string salle);
	void setHeure(std::string heure);
	void setJour(std::string jour);
	void setIdCoach(int idcoach);
	void setNameCoach(std::string namecoach);

	// Autres méthodes
	void ajouterSeance();
	void supprimerSeance();
	void afficherSeance();
	void modifierSeance();
};

