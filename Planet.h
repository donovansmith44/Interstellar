#include <iostream>
#include <string>
#ifndef PLANET_H
#define PLANET_H

using namespace std;

class Planet{
    public:
    Planet();
    int getNumVisited();
    double getPlanetRadius();
    double getCarryingCapacity();
    int getFuelRequired();
    string getPlanetName();
    string getPlanetWord();
    string getPlanetNumber();
    void setNumVisited();
    void genPlanetRadius();
    void setCarringCapacity(double);
    void genPlanetName();
    void setFuelRequired();
    void clearPlanetName();
    void clearPlanet();
    void setPlanetName(string);

    private:
    int numVisited;
    double planetRadius;
    double carryingCapacity;
    int fuelRequired;
    string planetName;
    string planetWord;
    string planetNumber;
};

#endif