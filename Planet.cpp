#include "Mission.h"
#include "Map.h"
#include "Materials.h"
#include "Planet.h"
#include "Status.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


    Planet::Planet(){
        numVisited = 0;
        planetName = "";
        planetNumber = "";
        planetWord = "";

    }
    int Planet::getNumVisited(){
        return numVisited;
    }
    double Planet::getPlanetRadius(){
        return planetRadius;
    }
    double Planet::getCarryingCapacity(){
        return planetRadius * 615;
    }
    int Planet::getFuelRequired(){
        return fuelRequired;
    }
    string Planet::getPlanetName(){
        return planetName;
    }
    string Planet::getPlanetWord(){
        return planetWord;
    }
    string Planet::getPlanetNumber(){
        return planetNumber;
    }
    void Planet::setNumVisited(){
        
    }
    void Planet::genPlanetRadius(){
        srand(time(NULL)); //this is the seed
        planetRadius = 1 + (float((rand() % 15)))/2; //generates a random number between 1 and 8 in intervals of .5
    }
    void Planet::setCarringCapacity(double rad){
        carryingCapacity = rad * 615;
    }
    void Planet::genPlanetName(){
        char temp;
        
        srand(time(NULL)); //this is the seed
        
        //gen 6 character string with characters between 0-9 or capital letters
        for (int i = 0; i < 6; i++)
        {
            bool which = float((rand() % 2)); //generates either 0 or 1. Allows us to pick a capital letter or number (0-9) with equal probability

            if (which)
            {
                temp = 65 + float((rand() % 26)); //generates a random number between 65 and 90
            }
            else{
                temp = 48 + float((rand() % 10)); //generates a random number between 48 and 57
            }
            planetNumber += temp;
        }

        //pick a random four letter word
        srand(time(NULL)); //this is the seed

        ifstream file;
        string line;

        file.open("four_letter_words.txt");

        int n = 1 + float(rand()%3125); //generate a number between 1 and 3125
        int k = 1;
        while (getline(file, line))
        {
            if (k == n) //if we are on the nth (random number) line
            {
                planetWord = line; //save this word
            }
            k++;   
        }

        planetName = planetNumber + planetWord;
        numVisited++; //each time a planet is generated, increment the number of visited planets
    }
    void Planet::setPlanetName(string name){
        planetName = name;
    }
    void Planet::clearPlanetName(){
        planetNumber = "";
        planetWord = "";
    }
    