#include "Mission.h"
#include "Map.h"
#include "Materials.h"
#include "Planet.h"
#include "Status.h"
#include "Weapon.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

    Weapon::Weapon(){
        
    }
    Weapon::Weapon(string wepName, int wepType, int wepCost){
        weaponName = wepName;
        weaponType = wepType;
        weaponCost = wepCost;
    }
    string Weapon::getWeaponName(){
        return weaponName;
    }
    int Weapon::getWeaponType(){
        return weaponType;
    }
    int Weapon::getWeaponCost(){
        return weaponCost;
    }
    void Weapon::setWeaponName(string wepName){
        weaponName = wepName;
    }
    void Weapon::setWeaponType(int wepType){
        weaponType = wepType;
    }
    void Weapon::setWeaponCost(int wepCost){
        weaponCost = wepCost;
    }

