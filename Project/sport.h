
#include <string>

class Sport {
protected:
    int id;
    std::string nomSport;

public:
    Sport(int id, std::string nomSport);

    int getId() { return id; }
    std::string getNom() { return nomSport; }

    void setId(int id) { this->id = id; }
    void setNom(std::string nomSport) { this->nomSport = nomSport; }
};
