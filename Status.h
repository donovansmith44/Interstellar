#ifndef STATUS_H
#define STATUS_H

class Status{
public:
Status();
int getHealth();
//int getSuitHealth();
int getFuel();
int getMyFuelCapacity();
void setHealth(int, int);
void setSuitHealth(int, int);
void setFuel(int, int);

private:
int myHealth;
//int suitHealth;
int myFuel;
const static int myFuelCapacity = 400000;
};


#endif