#include "Mission.h"
#include "Map.h"
#include "Materials.h"
#include "Planet.h"
#include "Status.h"
#include "Weapon.h"
#include "Suit.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

Mission::Mission(){
    myMoney = 100000;
    planetsVisited = 0;
    humansSaved = 0;
    humansPerished = 0;
    //humanLives = 8000;
}

int Mission::getMyMoney(){
    return myMoney;
}
int Mission::getPlanetsVisited(){
    return planetsVisited;
}
int Mission::getHumansSaved(){
    return humansSaved;
}
int Mission::getHumansPerished(){
    return humansPerished;
}

void Mission::setMyMoney(int moneyGained, int moneyLost){
    myMoney += moneyGained;
    myMoney -= moneyLost;
}
void Mission::setPlanetsVisited(int planets){
    planetsVisited += planets;
}
void Mission::setHumansSaved(int saved){
    humansSaved += saved;
}
void Mission::setHumansPerished(int dead){
    humansPerished += dead;
}
