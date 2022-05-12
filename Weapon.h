#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>

using namespace std;


class Weapon{
    public:
    Weapon();
    Weapon(string, int, int);
    string getWeaponName();
    int getWeaponType();
    int getWeaponCost();
    void setWeaponName(string);
    void setWeaponType(int);
    void setWeaponCost(int);

    private:
    string weaponName;
    int weaponType;
    int weaponCost;
};


#endif