#include "Mission.h"
#include "Map.h"
#include "Materials.h"
#include "Planet.h"
#include "Status.h"
#include "Suit.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

Status::Status(){
    myHealth = 100;
   // suitHealth = 100;
    myFuel = 200000;
}
int Status::getHealth(){
    return myHealth;
}
// int Status::getSuitHealth(){
//     return suitHealth;
// }
int Status::getFuel(){
    return myFuel;
}
int Status::getMyFuelCapacity(){
    return myFuelCapacity;
}
void Status::setHealth(int hpGained, int hpLost){
    myHealth += hpGained;
    myHealth -= hpLost;
}
// void Status::setSuitHealth(int suitUp, int suitDown){
//     suitHealth += suitUp;
//     suitHealth -= suitDown;
// }
void Status::setFuel(int fuelGained, int fuelLost){
    myFuel += fuelGained;
    myFuel -= fuelLost;
}