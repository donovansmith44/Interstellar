#ifndef MATERIALS_H
#define MATERIALS_H

class Materials{
public:
Materials();
int getMedKits();
int getTranslators();
void setMedKits(int, int);
void setTranslators(int);

private:
int numMedKits;
int numTranslators;

};

#endif