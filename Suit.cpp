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

Suit::Suit(){
suitHealth = 100;
suitGrade = 1;
}
int Suit::getSuitHealth(){
    return suitHealth;
}
int Suit::getSuitGrade(){
    return suitGrade;
}
int Suit::getSuitCost(){
    return suitCost;
}
void Suit::setSuitHealth(int base, int scale, int grade){
    suitHealth -= (base - scale * grade);
}
void Suit::setSuitGrade(int newGrade){
    suitGrade = newGrade;
}
void Suit::setSuitCost(int grade){
    suitCost = 5000 * grade - 5000;
}