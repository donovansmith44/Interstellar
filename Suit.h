#ifndef SUIT_H
#define SUIT_H
#include <iostream>
#include <string>

using namespace std;

class Suit{
public:
Suit();
int getSuitHealth();
int getSuitGrade();
int getSuitCost();
void setSuitHealth(int, int, int);
void setSuitGrade(int);
void setSuitCost(int);

private:
int suitHealth;
int suitGrade;
int suitCost;
};
#endif