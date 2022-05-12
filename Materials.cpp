#include "Materials.h"
#include <iostream>
#include <string>

using namespace std;
Materials::Materials(){
numMedKits = 0;
numTranslators = 0;
}
int Materials::getMedKits(){
    return numMedKits;
}
int Materials::getTranslators(){
    return numTranslators;
}
void Materials::setMedKits(int numKitsGained, int numKitsLost){
    numMedKits += numKitsGained;
    numMedKits -= numKitsLost;
}
void Materials::setTranslators(int numTrans){
    numTranslators += numTrans;
}
