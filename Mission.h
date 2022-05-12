#ifndef MISSION_H
#define MISSION_H

class Mission{
public:
Mission();
Mission(int,int,int,int);
int getMyMoney();
int getPlanetsVisited();
int getHumansSaved();
int getHumansPerished();
int getHumanLives();
void setMyMoney(int, int);
void setPlanetsVisited(int);
void setHumansSaved(int);
void setHumansPerished(int);
private:
int myMoney;
int planetsVisited;
int humansSaved;
int humansPerished;
};


#endif