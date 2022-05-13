#include <iostream>
#include "Mission.h"
#include "Map.h"
#include "Materials.h"
#include "Planet.h"
#include "Status.h"
#include "Weapon.h"
#include "Suit.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int split(string inputString, char separator, string arr[], int size){

//initialize variables
int pieces = 0;
int count = 0;
int start = 0;
int end = 0;
int j = 0;

//if we have an empty string, return 0
if (inputString.empty()){
    return 0;
}

//count delimiters in string
for (int i = 0; i < inputString.size(); i++)
{
    if (inputString[i] == separator)
    {
        count++;
    }
}

//if we have no commas, return 1
if (count == 0)
{
    arr[0] = inputString;
    return 1;
}

//store strings in array
while (end < inputString.size() && j < size) //run this loop until the end of the array
{
    while (inputString[end] != separator && end < inputString.size()) //increment end until delimiter met
    {
        end++;
    }

    int len = end - start;

    arr[j] = inputString.substr(start, len); //store substring into array
    
    start = end + 1; //start is end + 1 because end will be at the position of a delimiter; we want to start at the next character
    end++; //increment end by one so that it will be at the place of the next character
    j++; //increment the position at which the substring is stored    
}

if (count > size)
{
    return -1;
}

return count+1;

}

void logBook(string name, Planet planet, vector<string> goodTraits, vector<string> badTraits, int assessment){
        cout << name << "'s Log Book page #" << planet.getNumVisited() << ": Planet " << planet.getPlanetName() << endl;
        cout << "Planet size (in diameter of 1000 kms): " << planet.getPlanetRadius() << endl;
        cout << "Planet's carrying capacity (in millions): " << planet.getCarryingCapacity() << endl;
        cout << "Habitable traits discovered: ";
        for (int i = 0; i < goodTraits.size(); i++)
        {
            cout << goodTraits[i];
            if (goodTraits.size() > 1 && i != goodTraits.size()-1) //only print space and comma if there's > 1 trait. don't print after the last trait
            {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "Non-habitable traits discovered: ";
        for (int i = 0; i < badTraits.size(); i++)//only print space and comma if there's > 1 trait. don't print after the last trait
        {
            cout << badTraits[i];
            if (badTraits.size() > 1 && i != goodTraits.size()-1)
            {
                cout << ", ";
            }
            
        }
        cout << endl;
        
        string habitability = "";

        cout << "Friendly alien assessment: ";
        if (assessment == 1)
        {
            cout << "habitable" << endl;
        }
        if (assessment == 0)
        {
            cout << "uninhabitable" << endl;
        }
        
}

vector<int> findFreeSpace(Map map, int row, int col){ //this function returns the coordinates of a place on the map guaranteed to be a free space
    
    vector<int> newCoord(2);
    srand(time(NULL)); //seed

    if (!map.isFreeSpace(row,col))
    {
        while (!map.isFreeSpace(row,col))
        {
            row = float(rand() % 13);
            col = float(rand() % 13);
        }       
    }
    newCoord[0] = row;
    newCoord[1] = col;
    return newCoord;
}

int buySuit(Mission yourMission, Suit yourSuit, int c1){
            cout << "Would you like to upgrade your spacesuit to any of these? The space suit health will be set to 100%." << endl;
            cout << "1. Space suit grade 2 is $5,000" << endl;
            cout << "2. Space suit grade 3 is $10,000" << endl;
            cout << "3. Space suit grade 4 is $15,000" << endl;
            cout << "4. Space suit grade 5 is $20,000" << endl;
            cin >> c1;
            
            if (((c1+1)-yourSuit.getSuitGrade()) * 5000 <= yourMission.getMyMoney()){ //if the user has enough money, they can purchase a suit upgrade
                switch (c1)
                {
                case 1:
                    yourMission.setMyMoney(0, ((2-yourSuit.getSuitGrade()) * 5000)); //this charges only based on the difference in suit grade.
                    yourSuit.setSuitGrade(2);
                    cout << "Your spacesuit is now a grade " << yourSuit.getSuitGrade() << "." << endl;
                    cout << "You have $" << yourMission.getMyMoney() << " left." << endl;
                    break;
                case 2:
                    yourMission.setMyMoney(0, (3-yourSuit.getSuitGrade()) * 5000); //this charges only based on the difference in suit grade.
                    yourSuit.setSuitGrade(3);
                    cout << "Your spacesuit is now a grade " << yourSuit.getSuitGrade() << "." << endl;
                    cout << "You have $" << yourMission.getMyMoney() << " left." << endl;
                    break;
                case 3:
                    yourMission.setMyMoney(0, (4-yourSuit.getSuitGrade()) * 5000); //this charges only based on the difference in suit grade.
                    yourSuit.setSuitGrade(4);
                    cout << "Your spacesuit is now a grade " << yourSuit.getSuitGrade() << "." << endl;
                    cout << "You have $" << yourMission.getMyMoney() << " left." << endl;
                    break;
                case 4:
                    yourMission.setMyMoney(0, (5-yourSuit.getSuitGrade()) * 5000); //this charges only based on the difference in suit grade.
                    yourSuit.setSuitGrade(5);
                    cout << "Your spacesuit is now a grade " << yourSuit.getSuitGrade() << "." << endl;
                    cout << "You have $" << yourMission.getMyMoney() << " left." << endl;
                    break;

                default:
                    break;
                }
             }
            else{
                cout << "You do not have enough money." << endl;
            }
               
            return yourSuit.getSuitGrade();
        }

int playRockPaperScissors(){
    srand(time(NULL));        

    int numGames = 0;
    int numWon = 0;

    for (size_t i = 0; i < 3; i++)
    {
    char yourRps;
    int npcRps = float(rand() % 3);
    cout << "Choose: rock(r), paper(p), or scissors(s)" << endl;
    cin >> yourRps;
    switch (npcRps)
    {
    case 0:
        cout << "The alien chose rock" << endl;
        if (yourRps == 'r')
        {
            cout << "You draw this round" << endl;
        }
        else if (yourRps == 'p'){
            cout << "You win this round" << endl;
            numWon++;
        }
        else if (yourRps == 's'){
            cout << "You lose this round" << endl;
        }
        break;
    case 1:
        cout << "The alien chose paper" << endl;
        if (yourRps == 'r')
        {
            cout << "You lost this round" << endl;
        }
        else if (yourRps == 'p'){
            cout << "You draw this round" << endl;
        }
        else if (yourRps == 's'){
            cout << "You win this round" << endl;
            numWon++;
        }
        break;
    case 2:
        cout << "The alien chose scissors" << endl;
        if (yourRps == 'r')
        {
            cout << "You win this round" << endl;
            numWon++;
        }
        else if (yourRps == 'p'){
            cout << "You lose this round" << endl;
        }
        else if (yourRps == 's'){
            cout << "You draw this round" << endl;
        }
        break;
    default:
        break;
    }
    numGames++;
    }
    return numWon;
}

int main(){
Mission myMission;
Status myStatus;
Materials myMaterials;
Suit mySuit;
ifstream file;
ofstream write;
string fileName = "crewmates.txt";
string temp = "tempCrew.txt";
string line = "";
string storeChar[2];
int charNum = 0;
char charChoice;
int charChoiceNum;
string charNames[10];
bool lola;
bool fighter;
bool millie;
bool chuck;
int alienClaim = -1;
int humanLives = 8000;
int accuratelyHabitable = 0;
int inaccuratelyHabitable = 0;

//clear write file if it was written to in a previous game
//soure for truncate: https://stackoverflow.com/questions/17032970/clear-data-inside-text-file-in-c
write.open("results.txt", ofstream::out | ofstream::trunc); 
write.close();

cout << "Please enter your name." << endl;
string playerName;
getline(cin, playerName);

cout << "Pick a crewmate to help you with your journey!" << endl;

int crewMembers = 0;
while (crewMembers <= 1) //character selection
{
/*
Character Selection Menu Algorithm
1. Using a split function, separate the character name from their abilities in an array
2. Print out the elements stored in the array for each character. This will be the character selection menu
3. Get user input for which character is desired
4. After one character is chosen, that character will be removed from the menu before the menu is printed again
*/

        file.open(fileName);

        while (getline(file, line))
        {
        split(line, ';', storeChar, 2);

        cout << charNum + 1 << ". ";

            for (int i = 0; i < 1; i++)
            {
                cout << storeChar[0] << endl;
                cout << "Ability: " << storeChar[1] << endl;

            }

        charNames[charNum] = storeChar[0]; //this array will hold the names of each character in order for future reference
        charNum++;
        line = "";
        }
        file.close();

        charNum = 0; //reset char num to zero so that the menu will start at one the next time a selection is made

        cin >> charChoice;
        //add characters
        if(charChoice == '1'){
            lola = true;
            charChoiceNum = 1;
        }
        else if(charChoice == '2'){
            fighter = true;
            charChoiceNum = 2;
        }
        else if(charChoice == '3'){
            millie = true;
            myStatus.setFuel(myStatus.getFuel(), 0); //if millie tycoon, double fuel
            charChoiceNum = 3;
        }
        else if(charChoice == '4'){
            chuck = true;
            charChoiceNum = 4;
        }

        if (crewMembers == 0) //only output this text after picking the first character
        {
            cout << "Great choice! " << charNames[charChoiceNum-1] << " will bring a lot to your team. Pick your last crewmate." << endl;
        }
        else
        {
            cout << "You have a very impressive crew. With your leadership, you will be sure to succeed." << endl;
        }

        if (charChoice == '1' || charChoice == '2' || charChoice == '3' || charChoice == '4')
        {
        crewMembers++;

        write.open(temp);
        file.open(fileName);

        while (getline(file, line))
        {
            split(line, ';', storeChar, 2);
            
            for (int i = 0; i < 1; i++)
            {
                if (storeChar[0] != charNames[charChoiceNum-1]) //delete the line at the selected character
                {
                    write << line << endl; //write all characters' info except for the selected one to a new txt file
                }
            }
            
            fileName = "tempCrew.txt"; //give filename the name of the file that will hold the names of the now available characters
            
        }
        
        file.close();
        write.close();
        }

        else
        {
        cout << "Invalid input." << endl;
        }

}

cout << endl;

/*
RESOURCE CENTER------------------------------------------------------------------------------------------------------------------------------
*/
fileName = "resource_center_info.txt";
file.open(fileName);

while (getline(file, line)) //print resource center info
{
    cout << line << endl;
}
file.close();

cout << "Hit enter when you have understood." << endl;

string s; 
cin.ignore(); //take enter as correct input
getline(cin, s);

int choice = 1; 
int choice2; 
int choice3;
vector<Weapon> weaponsHeld(2);
Weapon lightSaber("Light Saber", 1, 1000);
Weapon blaster("Blaster", 2, 2000);
Weapon beamGun("Beam Gun", 3, 5000);
int weaponSpaces = 2;
int weaponsOwned = 0;
int lightSabers = 0;
int blasters = 0;
int beamGuns = 0;
bool translator = false;
int fuelCost = 50000;

while (choice != 6)
{
    if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5){
        if (translator == false)
        {
        cout << "-------RESOURCE CENTER--------" << endl;
        cout << "Which item do you wish to buy?" << endl;
        cout << "1. Weapon" << endl;
        cout << "2. Translator" << endl;
        cout << "3. Space suit" << endl;
        cout << "4. Medical Kits" << endl;
        cout << "5. Fuel" << endl;
        cout << "6. Purchase and Leave" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
                while (choice2 != 4){
                cout << "Which weapon type do you wish to buy?" << endl;
                cout << "1. Light Saber" << endl;
                cout << "2. Blaster" << endl;
                cout << "3. Beam Gun" << endl;
                cout << "4. Go back to menu" << endl;
                
                cin >> choice2;
                switch (choice2)
                    {
                    case 1:
                        cout << "How many Light Sabers would you like ($1000 each)?" << endl;
                        cin >> choice3;
                        if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                        {
                            if (lightSaber.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                            for (int i = 0; i < choice3; i++) //check if they have enough space
                            {
                                if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                    weaponsHeld[i] = lightSaber; //store the purchased weapon
                                    myMission.setMyMoney(0, lightSaber.getWeaponCost()); //deduct funds
                                    weaponSpaces--;    
                                    weaponsOwned += choice3;
                                    lightSabers += choice3;
                                    //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                }
                                else if (weaponSpaces == 0)
                                {
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    break;
                                }   
                            }
                            }
                            else if(lightSaber.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                cout << "You don't have enough money." << endl;
                            }
                            else if(weaponSpaces == 0){
                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                            }
                        }
                        
                        else if(choice3 > 2){
                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                        }
                        
                        else{
                            cout << "Re-enter a valid option." << endl;
                        }                        
                        break;
                    case 2:
                        cout << "How many Blasters would you like ($2000 each)?" << endl;
                        cin >> choice3;
                        if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                        {
                            if (blaster.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                            for (int i = 0; i < choice3; i++) //check if they have enough space
                            {
                                if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                    weaponsHeld[i] = blaster; //store the purchased weapon
                                    myMission.setMyMoney(0,blaster.getWeaponCost()); //deduct funds
                                    weaponSpaces--;   
                                    weaponsOwned += choice3;
                                    blasters += choice3;
                                    //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                }
                                else if (weaponSpaces == 0)
                                {
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    break;
                                }   
                            }
                            }
                            else if(blaster.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                cout << "You don't have enough money." << endl;
                            }
                            else if(weaponSpaces == 0){
                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                            }
                        }
                        
                        else if(choice3 > 2){
                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                        }
                        
                        else{
                            cout << "Re-enter a valid option." << endl;
                        }                        
                        break;
                    case 3:
                        cout << "How many Beam Guns would you like ($5000 each)?" << endl;
                        cin >> choice3;
                        if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                        {
                            if (beamGun.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                            for (int i = 0; i < choice3; i++) //check if they have enough space
                            {
                                if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                    weaponsHeld[i] = beamGun; //store the purchased weapon
                                    myMission.setMyMoney(0, beamGun.getWeaponCost()); //deduct funds
                                    weaponSpaces--;
                                    weaponsOwned += choice3;
                                    beamGuns += choice3;
                                    //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                }
                                else if (weaponSpaces == 0)
                                {
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    break;
                                }   
                            }
                            }
                            else if(beamGun.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                cout << "You don't have enough money." << endl;
                            }
                            else if(weaponSpaces == 0){
                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                            }
                        }
                        
                        else if(choice3 > 2){
                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                        }
                        
                        else{
                            cout << "Re-enter a valid option." << endl;
                        }                        
                        break;
                    }
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                }

            break;

        case 2:
            cout << "Would you like to purchase a translator device ($5000)? 1 for yes, 0 for no." << endl;
            cin >> choice2;
            if (choice2 == 1 && myMission.getMyMoney() >= 5000) //if yes and they have enough money
            {
                if (myMaterials.getTranslators() == 0) //and they have no translators
                {
                    myMaterials.setTranslators(1); //set translators
                    myMission.setMyMoney(0, 5000);
                    translator = true; //this is set to true if the player owns a translator
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                }
            }
            else if(myMission.getMyMoney() < 5000){
                cout << "You do not have enough money." << endl;
            }
            
            break;

        case 3:
        mySuit.setSuitGrade(buySuit(myMission, mySuit, choice2));
            break;

        case 4:
            cout << "How many medical kits would you like to purchase ($2000 each)? You currently have 0 and can at most have 5." << endl;
            cin >> choice2;
            if (choice2 + myMaterials.getMedKits() <= 5 && choice2 * 2000 <= myMission.getMyMoney()) //if they have room for med kits + enough $
            {
                myMaterials.setMedKits(choice2, 0); //give them their requested number of med kits
                myMission.setMyMoney(0, choice2 * 2000); //deduct funds
                cout << "You have $" << myMission.getMyMoney() << " left." << endl;
            }
            else if(choice2 + myMaterials.getMedKits() > 5){
                cout << "You cannot have more than 5 kits. Re-enter a valid quantity." << endl;
            }
            else if(choice2 * 2000 > myMission.getMyMoney()){
                cout << "You do not have enough money." << endl;
            }
            break;

        case 5:
            if (myStatus.getFuel() == myStatus.getMyFuelCapacity())
            {
                cout << "The fuel tank is already at capacity! So you cannot buy more." << endl;
            }
            else{
                cout << "You have " << myStatus.getFuel() << " gallons of fuel. Your spacecraft can hold 400k gallons of fuel. How many gallons would you like to purchase ($1,000 per 10,000 gallons)? Input must be in multiples of 10000s." << endl;
                cin >> choice2;
                if (myStatus.getFuel() + choice2 <= 400000 && choice2 % 10000 == 0 && choice2 / 10 <= myMission.getMyMoney())
                {
                    myStatus.setFuel(choice2, 0);
                    myMission.setMyMoney(0, (choice2 * 1000)/10000);
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                }
                else if(myStatus.getFuel() + choice2 >= 400000){
                    cout << "You cannot buy more than the fuel tank's capacity, which is 400K." << endl;
                }
                else if(choice2 % 10000 != 0){
                    cout << "Input must be in multiples of 10000s. Re-enter a valid quantity." << endl;
                }
                else if (choice2/10 > myMission.getMyMoney())
                {
                    cout << "You do not have enough money." << endl;
                }
            }         
            break;

        case 6:
            //exit the menu
            break;
        default:
            break;
        }
        }
        else if(translator == true) //if the user has bought a translator
        {
        cout << "-------RESOURCE CENTER--------" << endl;
        cout << "Which item do you wish to buy?" << endl;
        cout << "1. Weapon" << endl;
        cout << "2. Space suit" << endl;
        cout << "3. Medical Kits" << endl;
        cout << "4. Fuel" << endl;
        cout << "5. Purchase and Leave" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
                while (choice2 != 4){
                cout << "Which weapon type do you wish to buy?" << endl;
                cout << "1. Light Saber" << endl;
                cout << "2. Blaster" << endl;
                cout << "3. Beam Gun" << endl;
                cout << "4. Go back to menu" << endl;
                
                cin >> choice2;
                switch (choice2)
                    {
                    case 1:
                        cout << "How many Light Sabers would you like ($1000 each)?" << endl;
                        cin >> choice3;
                        if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                        {
                            if (lightSaber.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                            for (int i = 0; i < choice3; i++) //check if they have enough space
                            {
                                if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                    weaponsHeld[i] = lightSaber; //store the purchased weapon
                                    myMission.setMyMoney(0, lightSaber.getWeaponCost()); //deduct funds
                                    weaponSpaces--;    
                                    weaponsOwned += choice3;
                                    lightSabers += choice3;
                                    //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                }
                                else if (weaponSpaces == 0)
                                {
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    break;
                                }   
                            }
                            }
                            else if(lightSaber.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                cout << "You don't have enough money." << endl;
                            }
                            else if(weaponSpaces == 0){
                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                            }
                        }
                        
                        else if(choice3 > 2){
                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                        }
                        
                        else{
                            cout << "Re-enter a valid option." << endl;
                        }                        
                        break;
                    case 2:
                        cout << "How many Blasters would you like ($2000 each)?" << endl;
                        cin >> choice3;
                        if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                        {
                            if (blaster.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                            for (int i = 0; i < choice3; i++) //check if they have enough space
                            {
                                if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                    weaponsHeld[i] = blaster; //store the purchased weapon
                                    myMission.setMyMoney(0,blaster.getWeaponCost()); //deduct funds
                                    weaponSpaces--;   
                                    weaponsOwned += choice3;
                                    blasters += choice3;
                                    //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                }
                                else if (weaponSpaces == 0)
                                {
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    break;
                                }   
                            }
                            }
                            else if(blaster.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                cout << "You don't have enough money." << endl;
                            }
                            else if(weaponSpaces == 0){
                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                            }
                        }
                        
                        else if(choice3 > 2){
                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                        }
                        
                        else{
                            cout << "Re-enter a valid option." << endl;
                        }                        
                        break;
                    case 3:
                        cout << "How many Beam Guns would you like ($5000 each)?" << endl;
                        cin >> choice3;
                        if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                        {
                            if (beamGun.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                            for (int i = 0; i < choice3; i++) //check if they have enough space
                            {
                                if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                    weaponsHeld[i] = beamGun; //store the purchased weapon
                                    myMission.setMyMoney(0, beamGun.getWeaponCost()); //deduct funds
                                    weaponSpaces--;
                                    weaponsOwned += choice3;
                                    beamGuns += choice3;
                                    //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                }
                                else if (weaponSpaces == 0)
                                {
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    break;
                                }   
                            }
                            }
                            else if(beamGun.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                cout << "You don't have enough money." << endl;
                            }
                            else if(weaponSpaces == 0){
                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                            }
                        }
                        
                        else if(choice3 > 2){
                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                        }
                        
                        else{
                            cout << "Re-enter a valid option." << endl;
                        }                        
                        break;
                    }
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                }
            break;
        case 2:
        mySuit.setSuitGrade(buySuit(myMission, mySuit, choice2));
            break;

        case 3:
            cout << "How many medical kits would you like to purchase ($2000 each)? You currently have 0 and can at most have 5." << endl;
            cin >> choice2;
            if (choice2 + myMaterials.getMedKits() <= 5 && choice2 * 2000 <= myMission.getMyMoney()) //if they have room for med kits + enough $
            {
                myMaterials.setMedKits(choice2, 0); //give them their requested number of med kits
                myMission.setMyMoney(0, choice2 * 2000); //deduct funds
                cout << "You have $" << myMission.getMyMoney() << " left." << endl;
            }
            else if(choice2 + myMaterials.getMedKits() > 5){
                cout << "You cannot have more than 5 kits. Re-enter a valid quantity." << endl;
            }
            else if(choice2 * 2000 > myMission.getMyMoney()){
                cout << "You do not have enough money." << endl;
            }
            break;

        case 4:
            if (myStatus.getFuel() == myStatus.getMyFuelCapacity())
            {
                cout << "The fuel tank is already at capacity! So you cannot buy more." << endl;
            }
            else{
                cout << "You have " << myStatus.getFuel() << " gallons of fuel. Your spacecraft can hold 400k gallons of fuel. How many gallons would you like to purchase ($1,000 per 10,000 gallons)? Input must be in multiples of 10000s." << endl;
                cin >> choice2;
                if (myStatus.getFuel() + choice2 <= 400000 && choice2 % 10000 == 0 && choice2 / 10 <= myMission.getMyMoney())
                {
                    myStatus.setFuel(choice2, 0);
                    myMission.setMyMoney(0, (choice2 * 1000)/10000);
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                }
                else if(myStatus.getFuel() + choice2 >= 400000){
                    cout << "You cannot buy more than the fuel tank's capacity, which is 400K." << endl;
                }
                else if(choice2 % 10000 != 0){
                    cout << "Input must be in multiples of 10000s. Re-enter a valid quantity." << endl;
                }
                else if (choice2/10 > myMission.getMyMoney())
                {
                    cout << "You do not have enough money." << endl;
                }
            }         
            break;

        case 5:
            //exit the menu
            choice = 6;
            break;
        default:
            break;
        }
        }        
    }

    else{
        cout << "Re-enter a valid option." << endl;
        choice = 1;
    }

    choice2 = 1;

}

cout << "Great purchase, Elon is sending a Cybertruck with your supplies to you right now." << endl;

//LIFTOFF!
cout << "Hit enter when you are ready to enter space and go to your first planet." << endl;
s = "";
cin.ignore();
getline(cin, s);

//deduct fuel. 50k for first planet
myStatus.setFuel(0,fuelCost);

cout << "3,2,1 . . . LIFTOFF! You are now in space. Hit enter to start exploring your first planet." << endl;
getline(cin, s);
/*
PHASE TWO------------------------------------------------------------------------------------------------------------------------------
*/

//generate a planet
Planet myPlanet;
vector<string> habitableTraits;
vector<string> uninhabitableTraits;

myPlanet.genPlanetName(); //generate random planet name
myPlanet.genPlanetRadius(); //generate random planet radius
cout << "Planet: " << myPlanet.getPlanetName() << endl;

//generate a map
Map myMap;
srand(time(NULL));

    for (int i = 0; i < 7; i++) //spawn seven sites
    {
        int randRow;
        int randCol;
        int randType = float(1 + rand() % 6); //random type between 1 and 6
        vector<int> Coordinates(2);

        Coordinates = findFreeSpace(myMap, randRow, randCol); //this guarantees that generated coordinates are a free space
        myMap.spawnSite(Coordinates[0], Coordinates[1], randType); //spawn site there
    }

    for (int i = 0; i < 2; i++) //spawn two hostile aliens
    {
        int randRow;
        int randCol;
        vector<int> Coordinates(2);

        Coordinates = findFreeSpace(myMap, randRow, randCol); //this guarantees that generated coordinates are a free space
        myMap.spawnMisfortune(Coordinates[0], Coordinates[1], 1); //spawn site there
    }

    for (int i = 0; i < float(4 + rand() % 3); i++) //spawn up to 6 additional misfortunes
    {
        int randRow;
        int randCol;
        int randType = float(1 + rand() % 4);
        vector<int> Coordinates(2);

        Coordinates = findFreeSpace(myMap, randRow, randCol); //this guarantees that generated coordinates are a free space
        myMap.spawnMisfortune(Coordinates[0], Coordinates[1], randType); //spawn misfortune there
    }

    for (int i = 0; i < 1; i++) //spawn up to one friendly alien
    {
        int randRow;
        int randCol;
        vector<int> Coordinates(2);

        if (float(rand() % 2) == 1) //spawn NPC with 50% prob
        {
            Coordinates = findFreeSpace(myMap, randRow, randCol); //this guarantees that generated coordinates are a free space
            myMap.spawnNPC(Coordinates[0], Coordinates[1]); //spawn NPC there
        }
    }

//MAIN MENU / PHASE 2------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
char input;

while (input != '7')
{
    //fast return whenever there are no humans left
    if (myMission.getHumansPerished() + myMission.getHumansSaved() >= 8000 || humanLives <= 0)
    {
        cout << "All of humanity has left Earth! Your mission is over." << endl;
        break;
    }
    
    //...or if you run out of health
    if (myStatus.getHealth() <= 0 || mySuit.getSuitHealth() <= 0)
    {
        cout << "You have died due to health loss. Had you planned better with more sophisticated materials,";
        cout << "you may have been able to prevent this. You can no longer explore more of space." << endl;
        break;
    }

bool written = false;
    if (!written) //write first page of the log book
        {
        //open file in append mode. source: https://stackoverflow.com/questions/4155537/writing-into-a-text-file-without-overwriting-it
        //https://stackoverflow.com/questions/4155537/writing-into-a-text-file-without-overwriting-it
        write.open("results.txt", fstream::app);
        write << playerName << "'s Log Book page #" << myPlanet.getNumVisited() << ": Planet " << myPlanet.getPlanetName() << endl;
        write << "Planet size (in diameter of 1000 kms): " << myPlanet.getPlanetRadius() << endl;
        write << "Planet's carrying capacity (in millions): " << myPlanet.getCarryingCapacity() << endl;
        write << "Habitable traits discovered: ";
        for (int i = 0; i < habitableTraits.size(); i++)
        {
            write << habitableTraits[i];
            if (habitableTraits.size() > 1 && i != habitableTraits.size()-1) //only print space and comma if there's > 1 trait. don't print after the last trait
            {
                write << ", ";
            }
        }
        write << endl;

        write << "Non-habitable traits discovered: ";
        for (int i = 0; i < uninhabitableTraits.size(); i++)//only print space and comma if there's > 1 trait. don't print after the last trait
        {
            write << uninhabitableTraits[i];
            if (uninhabitableTraits.size() > 1 && i != uninhabitableTraits.size()-1)
            {
                write << ", ";
            }
            
        }
        write << endl;
        
        write << "Friendly alien assessment: " << endl;

        if (alienClaim == 1)
        {
            write << "Habitable" << endl;
        }
        else if (alienClaim == 0)
        {
            write << "Uninhabitable" << endl;
        }
        else{

        }
        written = true;
        
        write.close();
        }

    myMap.displayMap();
    cout << "Select one:" << endl;
    cout << "1. Move" << endl;
    cout << "2. View Status" << endl;
    cout << "3. View log book" << endl;
    cout << "4. Resource center" << endl;
    cout << "5. Report planet as habitable" << endl;
    cout << "6. Enter wormhole to next planet" << endl;
    cout << "7. Give up" << endl;
    
    cin >> input;
    char charChoice;
    switch(input)
    {
    case '1': //MOVE
        myMap.displayMap();
        while(charChoice != 'm'){
        
        cout << "Select one: w. up s. down d. right a. left m. menu" << endl;
        cin >> charChoice;

            if (charChoice == 'w' || charChoice == 's' || charChoice == 'a' || charChoice == 'd') //if valid move input
            {
                if(!myMap.executeMove(charChoice)){ //if move is out of range
                        cout << "Out of range of map" << endl;
                    }
                else{
                    myMission.setMyMoney(50,0); //$50 gained per valid move
                    
                    //if we find a misfortune
                    if (myMap.isMisfortuneLocaton())
                    {
                        if(myMap.getMisfortuneType() == 1){ //if alien attack
                        //get random alien name
                        string alienName;
                        int randAlien = float(1+ rand() % 20); //generate a random number between 1 and 20 for 20 alien names
                        int n = 1;
                        file.open("alien_names.txt");
                        
                        for (int i = 1; i <= randAlien; i++)
                        {
                            if (i == randAlien)
                            {
                                getline(file, alienName); //get the random alien name
                            }
                        
                        }
                        
                        file.close();

                            cout << "You just ran into " << alienName << " Think you can beat this dangerous alien for helping save humanity?" << endl;
                            cout << "1. Attack" << endl << "2. Forfeit" << endl;
                            cin >> choice3;

                            if (choice3 == 1)
                            {
                                if (weaponsOwned == 0)
                                {
                                    if (myMission.getMyMoney() >= 1000)
                                    {
                                        cout << "You do not have a weapon to fight! Let's visit the resource center and buy a weapon!" << endl;
                        while (weaponsOwned == 0){
                        cout << "Which weapon type do you wish to buy?" << endl;
                        cout << "1. Light Saber" << endl;
                        cout << "2. Blaster" << endl;
                        cout << "3. Beam Gun" << endl;
                        
                        cin >> choice2;
                        switch (choice2)
                            {
                            case 1:
                                cout << "How many Light Sabers would you like ($1000 each)?" << endl;
                                cin >> choice3;
                                if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                                {
                                    if (lightSaber.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                                    for (int i = 0; i < choice3; i++) //check if they have enough space
                                    {
                                        if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                            weaponsHeld[i] = lightSaber; //store the purchased weapon
                                            myMission.setMyMoney(0, lightSaber.getWeaponCost()); //deduct funds
                                            weaponSpaces--;    
                                            weaponsOwned += choice3;
                                            lightSabers += choice3;
                                        }
                                        else if (weaponSpaces == 0)
                                        {
                                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                            break;
                                        }   
                                    }
                                    }
                                    else if(lightSaber.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                        cout << "You don't have enough money." << endl;
                                    }
                                    else if(weaponSpaces == 0){
                                        cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    }
                                }
                                
                                else if(choice3 > 2){
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                }
                                
                                else{
                                    cout << "Re-enter a valid option." << endl;
                                }                        
                                break;
                            case 2:
                                cout << "How many Blasters would you like ($2000 each)?" << endl;
                                cin >> choice3;
                                if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                                {
                                    if (blaster.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                                    for (int i = 0; i < choice3; i++) //check if they have enough space
                                    {
                                        if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                            weaponsHeld[i] = blaster; //store the purchased weapon
                                            myMission.setMyMoney(0,blaster.getWeaponCost()); //deduct funds
                                            weaponSpaces--;   
                                            weaponsOwned += choice3;
                                            blasters += choice3;
                                            //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                        }
                                        else if (weaponSpaces == 0)
                                        {
                                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                            break;
                                        }   
                                    }
                                    }
                                    else if(blaster.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                        cout << "You don't have enough money." << endl;
                                    }
                                    else if(weaponSpaces == 0){
                                        cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    }
                                }
                                
                                else if(choice3 > 2){
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                }
                                
                                else{
                                    cout << "Re-enter a valid option." << endl;
                                 }
                                break;
                            case 3:
                                cout << "How many Beam Guns would you like ($5000 each)?" << endl;
                                cin >> choice3;
                                if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                                {
                                    if (beamGun.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                                    for (int i = 0; i < choice3; i++) //check if they have enough space
                                    {
                                        if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                            weaponsHeld[i] = beamGun; //store the purchased weapon
                                            myMission.setMyMoney(0, beamGun.getWeaponCost()); //deduct funds
                                            weaponSpaces--;
                                            weaponsOwned += choice3;
                                            beamGuns += choice3;
                                            //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                        }
                                        else if (weaponSpaces == 0)
                                        {
                                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                            break;
                                        }   
                                    }
                                    }
                                    else if(beamGun.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                        cout << "You don't have enough money." << endl;
                                    }
                                    else if(weaponSpaces == 0){
                                        cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    }
                                }
                                
                                else if(choice3 > 2){
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                }
                                
                                else{
                                    cout << "Re-enter a valid option." << endl;
                                }                        
                                break;
                            }
                            cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                    //     }
                     //}

                                    }
                                    }   
                                    else{
                                        cout << "You neither have a weapon nor enough money to buy a weapon. Consequently";
                                        cout << ", the alien attacked and defeated you could not retreat :(" << endl;
                                    }
                                    
                                    }
                                    
                            //BATTLE
                            cout << "Let's attack! Choose a weapon from your arsenal quickly and attack before the enemy advances!" << endl;
                            cout << "1. " << weaponsHeld[0].getWeaponName() << endl; //if we are attacking, the player must have a weapon

                            for (int i = 0; i < 1; i++)
                            {
                                if(weaponsHeld[1].getWeaponName() != ""){ //if we have a second weapon
                                    cout << "2. " << weaponsHeld[1].getWeaponName() << endl; //print this weapon as an option as well
                                }
                            }
                            
                            while (choice2 != 1 && choice2 != 2){ //get user weapon choice

                            cin >> choice2;
                            if (choice2 != 1 && choice2 != 2)
                            {
                                cout << "Invalid input" << endl;
                            }
                            }

                            int r1 = float(1 + rand() % 6);
                            int r2 = float(1 + rand() % 6);
                            int battleChance = (r1 * weaponsHeld[choice2-1].getWeaponType())*(1 + fighter) - (r2 * myPlanet.getNumVisited());
                            bool battleWon;
                            if (battleChance > 0) //if the battle was won
                            {
                                battleWon = true;
                                int randomWeaponType = float(1 + rand() % 3);
                                Weapon randomWeapon;
                                switch (randomWeaponType) //give them a random weapon
                                {
                                case 1:
                                    randomWeapon = lightSaber; 
                                    lightSabers++;
                                    break;
                                case 2:
                                    randomWeapon = blaster;
                                    blasters++;
                                    break;
                                case 3:
                                    randomWeapon = beamGun;
                                    beamGuns++;
                                    break;
                                default:
                                    break;
                                }
                                if (weaponSpaces >= 1) //if there is room for an additional weapon
                                {
                                    cout << "You defeated " << alienName << " Great Job! You won the " << randomWeapon.getWeaponName() << ". But you lost 10% of space suit health while fighting" << endl;
                                    weaponsHeld.push_back(randomWeapon);
                                    weaponsOwned++;
                                    weaponSpaces--;
                                }
                                else{ //if there is no room for an additional weapon
                                cout << "You defeated " << alienName << ". Great Job! You saw the enemy's weapon lying down but you cannot carry it with you";
                                cout << " as you already have 2 weapons. Unfortunately, you lost 10% of space suit health while fighting." << endl;
                                }

                                mySuit.setSuitHealth(100, 90, 1); //deduct 10% suit hp
                            }

                            else{
                                battleWon = false;
                                cout << "Aggh! You lost the battle! " << alienName << " seems to be hard for you! Tough times. Unfortunately, you experience the following due to this loss:" << endl;
                                cout << "1. Your health was decreased by 30%" << endl;
                                cout << "2. Your suit health was decreased by " << (100 - 20 * mySuit.getSuitGrade()) << "%." << endl;
                                cout << "3. You lost the " << weaponsHeld[choice2-1].getWeaponName() << ", the weapon you used for attacking the alien." << endl;
                                
                                myStatus.setHealth(0, 30); //lose 30% hp

                                mySuit.setSuitHealth(100, 20, mySuit.getSuitGrade()); //lose 100 - 20*x % suit health
                                weaponsHeld.erase(weaponsHeld.begin() + (choice2 - 1)); //lose weapon used in battle
                            }
                                if (lola == true)
                                {
                                    myStatus.setHealth(5,0); //if lola doctor is a team member, give 5% health after a battle
                                }
                            }
                            else if (choice3 == 2){
                                cout << "Really?! You chose to forfeit the battle? This is disappointing! You lost a weapon due to this decision.";
                                cout << "Hopefully, you git gud before you encounter the next alien." << endl;
                                //remove a random weapon from inventory
                                
                                if (weaponsOwned >= 1) //if they have a weapon
                                {
                                    int randWep = float(rand() % 2);
                                    weaponsHeld.erase(weaponsHeld.begin() + randWep); //remove a random weapon
                                    weaponsOwned--;
                                    weaponSpaces++; 
                                }
                                else{
                                    if (myMission.getMyMoney() >= 10000) //if they have 10k or more
                                    {
                                        myMission.setMyMoney(0, 10000); //tax 10k
                                    }
                                    else{
                                        myMission.setMyMoney(0, myMission.getMyMoney()); //take all money
                                    }
                                }
                                
                            }
                            
                        }
                        
                        if (myMap.getMisfortuneType() == 2) //if extreme weather event
                        {
                            cout << "Oh no! You've encountered a weather storm. Your health decreased by 10%" << endl;
                            myStatus.setHealth(0,10); //decrease health by 10%
                            mySuit.setSuitHealth(50, 10, mySuit.getSuitGrade()); //decrease suit health by (50 - 10 * grade)%
                        }

                        if (myMap.getMisfortuneType() == 3) //if crater
                        {
                            cout << "Oh no! You've fallen into a crater. Your health has decreased by 50%." << endl;
                            myStatus.setHealth(0,50);
                            mySuit.setSuitHealth(50, 10, mySuit.getSuitGrade()); //decrease suit health by (50 - 10 * grade)%
                        }

                        if (myMap.getMisfortuneType() == 4) //if space sickness
                        {
                            cout << "Oh no! You've gotten space sickness. Your health decreased by 30%." << endl;
                            myStatus.setHealth(0,30);
                        }
                    }
                    
                    //if we find a site
                    if (myMap.isSiteLocation())
                    {
                        cout << "Good job, you have found a site that may have some useful information about this planet. If you get this question";
                        cout << " right, the information will be revealed. If you answer incorrectly though, you'll become more frustrated and lose 1% health due to stress." << endl;

                        file.open("questions.txt");
                        line = "";
                        int randLine = float(rand() % 87);
                        int lineCount = 0;
                        string arr[5] = {};
                        
                        while(getline(file, line) && lineCount != randLine){ //get a random line
                            lineCount++;
                        }

                        split(line, ',', arr, 5);

                        string question = arr[0];
                        string questionArr[2];
                        split(question, ';', questionArr, 2); //split first question from first answer
                        
                        cout << "string question: " << questionArr[0] << endl; //ask question
                        
                        vector<string> answers(4);
                        answers[0] = questionArr[1]; //save first answer into answers vector

                        for (int i = 1; i < 4; i++)
                        {
                            answers[i] = arr[i]; //store the answers in the vector for workability
                        }
                        
                        char ans = 'a';
                        vector<string> answerHolder;
                        for (int i = 0; i < 4; i++)
                        {
                            int randAns = float(rand() % (answers.size())); //generates a random integer
                            string _randAns = answers[randAns];

                            cout << ans << ". ";
                            cout << _randAns << endl;

                            string tempAns = "";
                            tempAns += ans;

                            answerHolder.push_back(tempAns);
                            answerHolder.push_back(answers[randAns]);

                            answers.erase(answers.begin() + randAns); //erase the answer so that it cannot be chosen again
                            tempAns = "";
                            ans++;
                        }

                        char userAnsw;
                        bool correct = false;

                        while(correct == false){
                        
                        cin >> userAnsw; //get answer

                        for (int i = 0; i < 8; i+=2)
                        {
                            string tempUserAns = "";
                            tempUserAns += userAnsw;

                            if(tempUserAns == answerHolder[i]){ //if they choose a particular letter answer
                                if (answerHolder[i+1] == questionArr[1]) //if they've chosen the correct answer
                                {
                                    int trait = myMap.getSiteTrait();
                                    string _trait = "";
                                    switch (trait)
                                    {
                                    case 1:
                                        _trait = "Water";
                                        break;
                                    case 2:
                                        _trait = "Oxygen";
                                        break;
                                    case 3:
                                        _trait = "Fertile soil";
                                        break;
                                    case 4:
                                        _trait = "Bad atmosphere";
                                        break;
                                    case 5:
                                        _trait = "Toxic gas";
                                        break;
                                    case 6:
                                        _trait = "Extreme temperatures";
                                        break;
                                    default:
                                        break;
                                    }

                                    cout << "Correct answer!" << endl;
                                    cout << "You just discovered that this planet has " << _trait;
                                    bool traitFound;
                                    if (1 <= trait && 3 >= trait)
                                    {
                                        cout << ". This is a great sign. This discovery has been added to your log book" << endl;
                                        //only add trait if it is not a duplicate
                                        for (int i = 0; i < habitableTraits.size(); i++)
                                        {
                                            if (habitableTraits[i] == _trait)
                                            {
                                                traitFound = true;
                                            }
                                            else{
                                                traitFound = false;
                                            }
                                        }
                                        if (!traitFound)
                                        {
                                            habitableTraits.push_back(_trait);
                                            traitFound = false;
                                        }
                                        
                                    }
                                    else
                                    {
                                        cout << ". This is not a promising sign... This discovery has been added to your log book" << endl;
                                        uninhabitableTraits.push_back(_trait);
                                        //only add trait if it is not a duplicate
                                        for (int i = 0; i < uninhabitableTraits.size(); i++)
                                        {
                                            if (uninhabitableTraits[i] == _trait)
                                            {
                                                traitFound = true;
                                            }
                                            else{
                                                traitFound = false;
                                            }
                                        }
                                        if (!traitFound)
                                        {
                                            uninhabitableTraits.push_back(_trait);
                                            traitFound = false;
                                        }
                                    }

                                    correct = true;
                                    break;
                                }
                                else
                                {
                                    cout << "Incorrect answer! Reduced your health by 1% because of frustration." << endl;
                                    myStatus.setHealth(0,1); //deduct 1% hp
                                }
                                    
                            }
                        }
                        }
                        file.close();
                    }
                    
                    //if we find a friendly alien
                    if (myMap.isNPCLocation())
                    {
                        cout << "You have run into a friendly alien!" << endl;
                        if (translator == true) //if player has a translator
                        {
                            string npcChoice;
                            cout << "You can communicate with this alien. You can defeat them in rock, paper, scissors three times and gain $200 (c)";
                            cout << "or you can ask them about the habitability of this planet (a).";
                            cout <<  " The chance of the alien telling the truth is 70%. You can only pick one option." << endl;
                            while (npcChoice != "a" && npcChoice != "c")
                            {
                                getline(cin, npcChoice);
                            }
                            if (npcChoice == "a") //have alien tell them about the habitability
                            {
                                int lie = float(rand() % 10); //generate random number between 0 and 10

                                if (chuck == 1) //if chuck intimidator is on the team
                                {
                                if (!myMap.isHabitable())
                                {
                                    if (lie >= 0 && lie <= 2) //20% chance they will say the planet is inhabitable if it is not
                                    {
                                        cout << "Hello human! I have looked around this planet and think this would make a great home for you." << endl;
                                        alienClaim = 1; //set to one if they claim habitability
                                    }
                                    else{
                                        cout << "Hello human! I have looked around this planet and think this would be a terrible choice";
                                        cout << " for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else." << endl;
                                        alienClaim = 0;
                                    }       
                                }
                                else if (myMap.isHabitable())
                                {
                                    if (lie >= 0 && lie <= 8) //80% chance they will say the planet is habitable if it is
                                    {
                                        cout << "Hello human! I have looked around this planet and think this would make a great home for you." << endl;
                                        alienClaim = 1;//set to one if they claim habitability
                                    }
                                    else{
                                        cout << "Hello human! I have looked around this planet and think this would be a terrible choice";
                                        cout << " for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else." << endl;
                                        alienClaim = 0;
                                    }       
                                }                                    
                                }

                                else{ //if no chuck intimidator
                                if (!myMap.isHabitable())
                                {
                                    if (lie >= 0 && lie <= 3) //30% chance they will say the planet is inhabitable if it is not
                                    {
                                        cout << "Hello human! I have looked around this planet and think this would make a great home for you." << endl;
                                        alienClaim = 1; //set to one if they claim habitability
                                    }
                                    else{
                                        cout << "Hello human! I have looked around this planet and think this would be a terrible choice";
                                        cout << " for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else." << endl;
                                        alienClaim = 0;
                                    }       
                                }
                                else if (myMap.isHabitable())
                                {
                                    if (lie >= 0 && lie <= 7) //70% chance they will say the planet is habitable if it is
                                    {
                                        cout << "Hello human! I have looked around this planet and think this would make a great home for you." << endl;
                                        alienClaim = 1;//set to one if they claim habitability
                                    }
                                    else{
                                        cout << "Hello human! I have looked around this planet and think this would be a terrible choice";
                                        cout << " for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else." << endl;
                                        alienClaim = 0;
                                    }       
                                }
                                }

                                cout << "How would you like to respond?" << endl;
                                file.open("alien_conversation.txt");
                                string playerLines[2];
                                int j = 0;
                                int response;
                                vector<string> convo;
                                line = "";
                                while (getline(file, line))
                                {
                                    split(line, ',', playerLines, 2);
                                    convo.push_back(playerLines[1]); //store all of the lines in a vector
                                    j++;

                                }
                                
                                if (alienClaim == 1)
                                {
                                    for (int i = 0; i < 5; i++)
                                    {
                                        cout << i+1 << ". " << convo[i+5] << endl; //print habitable lines
                                    }
                                    cin >> response;
                                    cout << convo[response + 4] << endl;
                                }
                                else{
                                    for (int i = 0; i < 5; i++)
                                    {
                                        cout << i+1 << ". " << convo[i] << endl; //print uninhabitable lines
                                    }
                                    cin >> response;
                                    cout << convo[response - 1] << endl;
                                }
                                file.close();
                                
                            }
                            else if (npcChoice == "c")//rock paper scissors
                            {
                                int numWon = playRockPaperScissors();
                                if (numWon >= 2)
                                {
                                    cout << "Congratulations! You defeated the alien and won $200" << endl;
                                    myMission.setMyMoney(200,0);
                                }
                                else{
                                    cout << "You failed to defeat the alien. You don't get any money or intel." << endl;
                                }

                            }

                        }
                        else{
                            cout << "You do not have a translator and cannot communicate with this alien. This alien";
                            cout << "may have useful information for you or money to offer, you can purchase a translator";
                            cout << "from the store if you would like to talk to them." << endl;
                        }
                    }
                    
                }
            }
            
            myMap.displayMap(); //display map after every move, even if invalid
        }
        charChoice = ' '; //clear charChoice or it will be stuck at m, and movement will not work
        
        break;
    case '2': //VIEW STATUS
        int _hp;
        int _fuel;
        int _suitHp;

        //get health status
        cout << "       Health:" << endl;
        _hp = myStatus.getHealth();
        cout << "       ";
        for (int i = 0; i < _hp / 5; i++)
        {
            cout << "_";
        }
        cout << " " << _hp << "%" << endl;
        
        //get suit health status
        cout << "       Space Suit Health:" << endl;
        _suitHp = (float(mySuit.getSuitHealth())/100.0) * 100;
        cout << "       ";
        for (int i = 0; i < _suitHp / 5; i++)
        {
            cout << "_";
        }
        cout << " " << _suitHp << "%"<< endl;

        //get fuel tank status
        cout << "       Fuel tank:" << endl;
        _fuel = (float(myStatus.getFuel())/float(myStatus.getMyFuelCapacity())) * 100;
        cout << "       ";
        for (int i = 0; i < _fuel / 5; i++)
        {
            cout << "_";
        }
        cout << " " << _fuel << "%"<< endl << endl;

        cout << "Planets explored: " << myPlanet.getNumVisited() << endl;
        cout << "Planets accurately reported habitable: " << endl;
        cout << "Planets inaccurately reported habitable: " << endl;

        cout << "Humans saved (in millions): " << myMission.getHumansSaved() << endl;
        cout << "Humans perished (in millions): " << myMission.getHumansPerished() << endl;

        cout << "- Money - $" << myMission.getMyMoney() << endl;
        cout << "- WEAPONS - " << weaponsOwned << endl;
        cout << "   1. Light Saber - " << lightSabers << endl;
        cout << "   2. Blaster - " << blasters << endl;
        cout << "   3. Beam Gun - " << beamGuns << endl;
        cout << "- TRANSLATOR - " << myMaterials.getTranslators() << endl;
        cout << "- SPACE SUIT GRADE #" << mySuit.getSuitGrade() << endl;
        cout << "- MEDICAL KITS - " << myMaterials.getMedKits() << endl;
        cout << "- FUEL - " << myStatus.getFuel() << " Gallons" << endl; 
        break;
    case '3': //view log book
        logBook(playerName, myPlanet, habitableTraits, uninhabitableTraits, alienClaim);
        cout << endl;
        break;
    case '4': //access resource center
        choice = 1;
        while (choice != 6){
        if (translator == false)
        {
        if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
        {
        cout << "-------RESOURCE CENTER--------" << endl;
        cout << "Which item do you wish to buy?" << endl;
        cout << "1. Weapon" << endl;
        cout << "2. Translator" << endl;
        cout << "3. Space suit" << endl;
        cout << "4. Medical Kits" << endl;
        cout << "5. Fuel" << endl;
        cout << "6. Purchase and Leave" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
                while (choice2 != 4){
                cout << "Which weapon type do you wish to buy?" << endl;
                cout << "1. Light Saber" << endl;
                cout << "2. Blaster" << endl;
                cout << "3. Beam Gun" << endl;
                cout << "4. Go back to menu" << endl;
                
                cin >> choice2;
                switch (choice2)
                    {
                    case 1:
                        cout << "How many Light Sabers would you like ($1000 each)?" << endl;
                        cin >> choice3;
                        if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                        {
                            if (lightSaber.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                            for (int i = 0; i < choice3; i++) //check if they have enough space
                            {
                                if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                    weaponsHeld[i] = lightSaber; //store the purchased weapon
                                    myMission.setMyMoney(0, lightSaber.getWeaponCost()); //deduct funds
                                    weaponSpaces--;    
                                    weaponsOwned += choice3;
                                    lightSabers += choice3;
                                    //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                }
                                else if (weaponSpaces == 0)
                                {
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    break;
                                }   
                            }
                            }
                            else if(lightSaber.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                cout << "You don't have enough money." << endl;
                            }
                            else if(weaponSpaces == 0){
                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                            }
                        }
                        
                        else if(choice3 > 2){
                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                        }
                        
                        else{
                            cout << "Re-enter a valid option." << endl;
                        }                        
                        break;
                    case 2:
                        cout << "How many Blasters would you like ($2000 each)?" << endl;
                        cin >> choice3;
                        if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                        {
                            if (blaster.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                            for (int i = 0; i < choice3; i++) //check if they have enough space
                            {
                                if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                    weaponsHeld[i] = blaster; //store the purchased weapon
                                    myMission.setMyMoney(0,blaster.getWeaponCost()); //deduct funds
                                    weaponSpaces--;   
                                    weaponsOwned += choice3;
                                    blasters += choice3;
                                    //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                }
                                else if (weaponSpaces == 0)
                                {
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    break;
                                }   
                            }
                            }
                            else if(blaster.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                cout << "You don't have enough money." << endl;
                            }
                            else if(weaponSpaces == 0){
                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                            }
                        }
                        
                        else if(choice3 > 2){
                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                        }
                        
                        else{
                            cout << "Re-enter a valid option." << endl;
                        }                        
                        break;
                    case 3:
                        cout << "How many Beam Guns would you like ($5000 each)?" << endl;
                        cin >> choice3;
                        if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                        {
                            if (beamGun.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                            for (int i = 0; i < choice3; i++) //check if they have enough space
                            {
                                if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                    weaponsHeld[i] = beamGun; //store the purchased weapon
                                    myMission.setMyMoney(0, beamGun.getWeaponCost()); //deduct funds
                                    weaponSpaces--;
                                    weaponsOwned += choice3;
                                    beamGuns += choice3;
                                    //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                }
                                else if (weaponSpaces == 0)
                                {
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    break;
                                }   
                            }
                            }
                            else if(beamGun.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                cout << "You don't have enough money." << endl;
                            }
                            else if(weaponSpaces == 0){
                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                            }
                        }
                        
                        else if(choice3 > 2){
                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                        }
                        
                        else{
                            cout << "Re-enter a valid option." << endl;
                        }                        
                        break;
                    }
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                }

            break;
        case 2:
            cout << "Would you like to purchase a translator device ($5000)? 1 for yes, 0 for no." << endl;
            cin >> choice2;
            if (choice2 == 1 && myMission.getMyMoney() >= 5000)
            {
                if (myMaterials.getTranslators() == 0)
                {
                    myMaterials.setTranslators(1);
                    myMission.setMyMoney(0, 5000);
                    translator = true;
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                }
            }
            else if(myMission.getMyMoney() < 5000){
                cout << "You do not have enough money." << endl;
            }
            
            break;
        case 3:
            cout << "Would you like to upgrade your spacesuit to any of these? The space suit health will be set to 100%." << endl;
            cout << "1. Space suit grade 2 is $5,000" << endl;
            cout << "2. Space suit grade 3 is $10,000" << endl;
            cout << "3. Space suit grade 4 is $15,000" << endl;
            cout << "4. Space suit grade 5 is $20,000" << endl;
            cin >> choice2;
            if (((choice2+1)-mySuit.getSuitGrade()) * 5000 <= myMission.getMyMoney()){ //if the user has enough money, they can purchase a suit upgrade
                switch (choice2)
                {
                case 1:
                    myMission.setMyMoney(0, ((2-mySuit.getSuitGrade()) * 5000)); //this charges only based on the difference in suit grade.
                    mySuit.setSuitGrade(2);
                    cout << "Your spacesuit is now a grade " << mySuit.getSuitGrade() << "." << endl;
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                    break;
                case 2:
                    myMission.setMyMoney(0, (3-mySuit.getSuitGrade()) * 5000); //this charges only based on the difference in suit grade.
                    mySuit.setSuitGrade(3);
                    cout << "Your spacesuit is now a grade " << mySuit.getSuitGrade() << "." << endl;
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                    break;
                case 3:
                    myMission.setMyMoney(0, (4-mySuit.getSuitGrade()) * 5000); //this charges only based on the difference in suit grade.
                    mySuit.setSuitGrade(4);
                    cout << "Your spacesuit is now a grade " << mySuit.getSuitGrade() << "." << endl;
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                    break;
                case 4:
                    myMission.setMyMoney(0, (5-mySuit.getSuitGrade()) * 5000); //this charges only based on the difference in suit grade.
                    mySuit.setSuitGrade(5);
                    cout << "Your spacesuit is now a grade " << mySuit.getSuitGrade() << "." << endl;
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                    break;
                
                default:
                    break;
                }
            break;
            }
            else{
                cout << "You do not have enough money." << endl;
            }
        case 4:
            cout << "How many medical kits would you like to purchase ($2000 each)? You currently have 0 and can at most have 5." << endl;
            cin >> choice2;
            if (choice2 + myMaterials.getMedKits() <= 5 && choice2 * 2000 <= myMission.getMyMoney()) //if they have room for med kits + enough $
            {
                myMaterials.setMedKits(choice2, 0); //give them their requested number of med kits
                myMission.setMyMoney(0, choice2 * 2000); //deduct funds
                cout << "You have $" << myMission.getMyMoney() << " left." << endl;
            }
            else if(choice2 + myMaterials.getMedKits() > 5){
                cout << "You cannot have more than 5 kits. Re-enter a valid quantity." << endl;
            }
            else if(choice2 * 2000 > myMission.getMyMoney()){
                cout << "You do not have enough money." << endl;
            }
            break;
        case 5:
            if (myStatus.getFuel() == myStatus.getMyFuelCapacity())
            {
                cout << "The fuel tank is already at capacity! So you cannot buy more." << endl;
            }
            else{
                cout << "You have " << myStatus.getFuel() << " gallons of fuel. Your spacecraft can hold 400k gallons of fuel. How many gallons would you like to purchase ($1,000 per 10,000 gallons)? Input must be in multiples of 10000s." << endl;
                cin >> choice2;
                if (myStatus.getFuel() + choice2 <= 400000 && choice2 % 10000 == 0 && choice2 / 10 <= myMission.getMyMoney())
                {
                    myStatus.setFuel(choice2, 0);
                    myMission.setMyMoney(0, (choice2 * 1000)/10000);
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                }
                else if(myStatus.getFuel() + choice2 >= 400000){
                    cout << "You cannot buy more than the fuel tank's capacity, which is 400K." << endl;
                }
                else if(choice2 % 10000 != 0){
                    cout << "Input must be in multiples of 10000s. Re-enter a valid quantity." << endl;
                }
                else if (choice2/10 > myMission.getMyMoney())
                {
                    cout << "You do not have enough money." << endl;
                }
                
            }            
            //if at some other point
            cout << "Great purchase, Elon is sending a Falcon rocket with your supplies to you right now." << endl;
            break;
        case 6:
            //exit the menu
            break;
        default:
            break;
        }
    }
        }
        else if(translator == true){ //if they have bought a translator
        if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
        {
        cout << "-------RESOURCE CENTER--------" << endl;
        cout << "Which item do you wish to buy?" << endl;
        cout << "1. Weapon" << endl;
        cout << "2. Space suit" << endl;
        cout << "3. Medical Kits" << endl;
        cout << "4. Fuel" << endl;
        cout << "5. Purchase and Leave" << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
                while (choice2 != 4){
                cout << "Which weapon type do you wish to buy?" << endl;
                cout << "1. Light Saber" << endl;
                cout << "2. Blaster" << endl;
                cout << "3. Beam Gun" << endl;
                cout << "4. Go back to menu" << endl;
                
                cin >> choice2;
                switch (choice2)
                    {
                    case 1:
                        cout << "How many Light Sabers would you like ($1000 each)?" << endl;
                        cin >> choice3;
                        if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                        {
                            if (lightSaber.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                            for (int i = 0; i < choice3; i++) //check if they have enough space
                            {
                                if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                    weaponsHeld[i] = lightSaber; //store the purchased weapon
                                    myMission.setMyMoney(0, lightSaber.getWeaponCost()); //deduct funds
                                    weaponSpaces--;    
                                    weaponsOwned += choice3;
                                    lightSabers += choice3;
                                    //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                }
                                else if (weaponSpaces == 0)
                                {
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    break;
                                }   
                            }
                            }
                            else if(lightSaber.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                cout << "You don't have enough money." << endl;
                            }
                            else if(weaponSpaces == 0){
                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                            }
                        }
                        
                        else if(choice3 > 2){
                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                        }
                        
                        else{
                            cout << "Re-enter a valid option." << endl;
                        }                        
                        break;
                    case 2:
                        cout << "How many Blasters would you like ($2000 each)?" << endl;
                        cin >> choice3;
                        if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                        {
                            if (blaster.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                            for (int i = 0; i < choice3; i++) //check if they have enough space
                            {
                                if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                    weaponsHeld[i] = blaster; //store the purchased weapon
                                    myMission.setMyMoney(0,blaster.getWeaponCost()); //deduct funds
                                    weaponSpaces--;   
                                    weaponsOwned += choice3;
                                    blasters += choice3;
                                    //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                }
                                else if (weaponSpaces == 0)
                                {
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    break;
                                }   
                            }
                            }
                            else if(blaster.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                cout << "You don't have enough money." << endl;
                            }
                            else if(weaponSpaces == 0){
                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                            }
                        }
                        
                        else if(choice3 > 2){
                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                        }
                        
                        else{
                            cout << "Re-enter a valid option." << endl;
                        }                        
                        break;
                    case 3:
                        cout << "How many Beam Guns would you like ($5000 each)?" << endl;
                        cin >> choice3;
                        if (choice3 == 0 || choice3 == 1 || choice3 == 2) //if the user wants a valid number of light sabers
                        {
                            if (beamGun.getWeaponCost() * choice3 <= myMission.getMyMoney()){ //check if they have enough $

                            for (int i = 0; i < choice3; i++) //check if they have enough space
                            {
                                if(weaponSpaces >= 1){ //if there is an empty space in the weapons inventory
                                    weaponsHeld[i] = beamGun; //store the purchased weapon
                                    myMission.setMyMoney(0, beamGun.getWeaponCost()); //deduct funds
                                    weaponSpaces--;
                                    weaponsOwned += choice3;
                                    beamGuns += choice3;
                                    //cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                                }
                                else if (weaponSpaces == 0)
                                {
                                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                                    break;
                                }   
                            }
                            }
                            else if(beamGun.getWeaponCost() * choice3 > myMission.getMyMoney()){
                                cout << "You don't have enough money." << endl;
                            }
                            else if(weaponSpaces == 0){
                                cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                            }
                        }
                        
                        else if(choice3 > 2){
                            cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                        }
                        
                        else{
                            cout << "Re-enter a valid option." << endl;
                        }                        
                        break;
                    }
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                }

            break;

        case 2:
            cout << "Would you like to upgrade your spacesuit to any of these? The space suit health will be set to 100%." << endl;
            cout << "1. Space suit grade 2 is $5,000" << endl;
            cout << "2. Space suit grade 3 is $10,000" << endl;
            cout << "3. Space suit grade 4 is $15,000" << endl;
            cout << "4. Space suit grade 5 is $20,000" << endl;
            cin >> choice2;
            if (((choice2+1)-mySuit.getSuitGrade()) * 5000 <= myMission.getMyMoney()){ //if the user has enough money, they can purchase a suit upgrade
                switch (choice2)
                {
                case 1:
                    myMission.setMyMoney(0, ((2-mySuit.getSuitGrade()) * 5000)); //this charges only based on the difference in suit grade.
                    mySuit.setSuitGrade(2);
                    cout << "Your spacesuit is now a grade " << mySuit.getSuitGrade() << "." << endl;
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                    break;
                case 2:
                    myMission.setMyMoney(0, (3-mySuit.getSuitGrade()) * 5000); //this charges only based on the difference in suit grade.
                    mySuit.setSuitGrade(3);
                    cout << "Your spacesuit is now a grade " << mySuit.getSuitGrade() << "." << endl;
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                    break;
                case 3:
                    myMission.setMyMoney(0, (4-mySuit.getSuitGrade()) * 5000); //this charges only based on the difference in suit grade.
                    mySuit.setSuitGrade(4);
                    cout << "Your spacesuit is now a grade " << mySuit.getSuitGrade() << "." << endl;
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                    break;
                case 4:
                    myMission.setMyMoney(0, (5-mySuit.getSuitGrade()) * 5000); //this charges only based on the difference in suit grade.
                    mySuit.setSuitGrade(5);
                    cout << "Your spacesuit is now a grade " << mySuit.getSuitGrade() << "." << endl;
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                    break;
                
                default:
                    break;
                }
            break;
            }
            else{
                cout << "You do not have enough money." << endl;
            }
        case 3:
            cout << "How many medical kits would you like to purchase ($2000 each)? You currently have 0 and can at most have 5." << endl;
            cin >> choice2;
            if (choice2 + myMaterials.getMedKits() <= 5 && choice2 * 2000 <= myMission.getMyMoney()) //if they have room for med kits + enough $
            {
                myMaterials.setMedKits(choice2, 0); //give them their requested number of med kits
                myMission.setMyMoney(0, choice2 * 2000); //deduct funds
                cout << "You have $" << myMission.getMyMoney() << " left." << endl;
            }
            else if(choice2 + myMaterials.getMedKits() > 5){
                cout << "You cannot have more than 5 kits. Re-enter a valid quantity." << endl;
            }
            else if(choice2 * 2000 > myMission.getMyMoney()){
                cout << "You do not have enough money." << endl;
            }
            break;
        case 4:
            if (myStatus.getFuel() == myStatus.getMyFuelCapacity())
            {
                cout << "The fuel tank is already at capacity! So you cannot buy more." << endl;
            }
            else{
                cout << "You have " << myStatus.getFuel() << " gallons of fuel. Your spacecraft can hold 400k gallons of fuel. How many gallons would you like to purchase ($1,000 per 10,000 gallons)? Input must be in multiples of 10000s." << endl;
                cin >> choice2;
                if (myStatus.getFuel() + choice2 <= 400000 && choice2 % 10000 == 0 && choice2 / 10 <= myMission.getMyMoney())
                {
                    myStatus.setFuel(choice2, 0);
                    myMission.setMyMoney(0, (choice2 * 1000)/10000);
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                }
                else if(myStatus.getFuel() + choice2 >= 400000){
                    cout << "You cannot buy more than the fuel tank's capacity, which is 400K." << endl;
                }
                else if(choice2 % 10000 != 0){
                    cout << "Input must be in multiples of 10000s. Re-enter a valid quantity." << endl;
                }
                else if (choice2/10 > myMission.getMyMoney())
                {
                    cout << "You do not have enough money." << endl;
                }
                
            }            
            //if at some other point
            cout << "Great purchase, Elon is sending a Falcon rocket with your supplies to you right now." << endl;
            break;
        case 5:
            //exit the menu
            choice = 6;
            break;
        default:
            break;
        }
    }
        }
    else{
        cout << "Re-enter a valid option." << endl;
        choice = 1;
    }
    choice2 = 1;
    }
        break;
    case '5': //report planet as habitable
        cout << "Are you sure you want to report back to mission control that this planet is habitable? ";
        cout << "As a reminder, here is your log book:" << endl << endl;
        
        logBook(playerName, myPlanet, habitableTraits, uninhabitableTraits, alienClaim);
        cout << endl;
        char playerReport;
        cout << "Reporting this planet is irreversible. If the planet is in fact habitable, you will save " << myPlanet.getCarryingCapacity() << " million people!";
        cout << " If it's not, the people sent to this planet will die." << endl;
        cout << "Ready to report? [y/n]" << endl;
        
        cin >> playerReport;
        if (playerReport == 'y')
        {
            if (humanLives > myPlanet.getCarryingCapacity()) //only deduct lives if it will not make the number of human lives negative
            {
                humanLives -= myPlanet.getCarryingCapacity();
            }
            else{
                humanLives = 0;
            }

            if (myMap.isHabitable())
            {
                cout << "Congratulations! You saved " << myPlanet.getCarryingCapacity() << " million people! Planet " << myPlanet.getPlanetName() << " is their";
                cout << " new home. You have " << humanLives << " million people to save left." << endl;
                myMission.setHumansSaved(myPlanet.getCarryingCapacity());
                accuratelyHabitable++;
            }
            else
            {
                if (humanLives > 0) //if people died, but still people living
                {
                cout << "Your choice has led to tragedy. " << myPlanet.getCarryingCapacity() << " million people were sent to planet ";
                cout << myPlanet.getPlanetName() << "and died due to its inhospitable conditions. You still have " << humanLives;
                cout << " million people to save, so keep exploring." << endl;
                myMission.setHumansPerished(myPlanet.getCarryingCapacity());
                inaccuratelyHabitable++;
                }
                else{ //if everyone died
                cout << "Your choice has led to tragedy. " << myPlanet.getCarryingCapacity() << " million people were sent to planet ";
                cout << myPlanet.getPlanetName() << " and died due to its inhospitable conditions." << endl;
                inaccuratelyHabitable++;
                    break;
                }

            }   
        }
        break;
    case '6': //ENTER WORMHOLE
        //write past log book into results
        char wormhole;
        cout << "Are you sure you want to enter this wormhole? You will start a new page in your log book and you will lose fuel." << endl;
        cout << "Enter wormhole? [y/n]" << endl;
        
        while (wormhole != 'y' && wormhole != 'n')
        {
            cin >> wormhole;
            if (wormhole == 'y')
        {
            string tempPlanetName = myPlanet.getPlanetName();
            myPlanet.clearPlanetName();
            myPlanet.genPlanetName(); //generate random planet name
            
            //check if they have enough fuel
            fuelCost = fuelCost * fuelCost/1000000 + fuelCost;
            if (myStatus.getFuel() >= fuelCost)
            {
        myStatus.setFuel(0, fuelCost); //deduct fuel
            
        //Reset planet
        myPlanet.genPlanetRadius(); //generate random planet radius
        cout << "Planet: " << myPlanet.getPlanetName() << endl;
        habitableTraits.clear();
        uninhabitableTraits.clear();
        //new map
        myMap.resetMap();

    for (int i = 0; i < 7; i++) //spawn seven sites
    {
        int randRow;
        int randCol;
        int randType = float(1 + rand() % 6);
        vector<int> Coordinates(2);

        Coordinates = findFreeSpace(myMap, randRow, randCol); //this guarantees that generated coordinates are a free space
        myMap.spawnSite(Coordinates[0], Coordinates[1], randType); //spawn site there
    }

    for (int i = 0; i < 2; i++) //spawn two hostile aliens
    {
        int randRow;
        int randCol;
        vector<int> Coordinates(2);

        Coordinates = findFreeSpace(myMap, randRow, randCol); //this guarantees that generated coordinates are a free space
        myMap.spawnMisfortune(Coordinates[0], Coordinates[1], 1); //spawn site there
    }

    for (int i = 0; i < float(4 + rand() % 3); i++) //spawn up to 6 additional misfortunes
    {
        int randRow;
        int randCol;
        int randType = float(1 + rand() % 4);
        vector<int> Coordinates(2);

        Coordinates = findFreeSpace(myMap, randRow, randCol); //this guarantees that generated coordinates are a free space
        myMap.spawnMisfortune(Coordinates[0], Coordinates[1], randType); //spawn misfortune there
    }

    for (int i = 0; i < 1; i++) //spawn up to one friendly alien
    {
        int randRow;
        int randCol;
        vector<int> Coordinates(2);

        if (float(rand() % 2) == 1) //spawn NPC with 50% prob
        {
            Coordinates = findFreeSpace(myMap, randRow, randCol); //this guarantees that generated coordinates are a free space
            myMap.spawnNPC(Coordinates[0], Coordinates[1]); //spawn NPC there
        }
    }   
            }

            else if(myStatus.getFuel() < fuelCost){ //if they don't have enough fuel
            
            cout << "You are about to travel to planet " << myPlanet.getPlanetName() <<" but you do not have sufficient fuel to travel. ";
            cout << "You will need " << fuelCost-myStatus.getFuel() << " more gallons of fuel to travel to this planet, which costs $";
            cout << ((fuelCost-myStatus.getFuel())/10) + ((fuelCost-myStatus.getFuel()) % 10) << "." << endl;
            cout << " Go ahead and make the purchase? [y/n]" << endl;
            wormhole = ' ';
            while (wormhole != 'y' && wormhole!= 'n')
        {
            cin >> wormhole;
            if (wormhole == 'y'){ //take them to buy more fuel if they select y

                if (myStatus.getFuel() == 400000) //if their fuel tank is full
                {
                    cout << "The fuel tank is already at capacity! So you cannot buy more." << endl;
                }
            else{
                //if tank is not full
                cout << "You have " << myStatus.getFuel() << " gallons of fuel. Your spacecraft can hold 400k gallons of fuel. How many gallons would you like to purchase ($1,000 per 10,000 gallons)? Input must be in multiples of 10000s." << endl;
                //get numgallons wanted
                cin >> choice2;

                if (myStatus.getFuel() + choice2 <= 400000 && choice2 % 10000 == 0 && choice2 / 10 <= myMission.getMyMoney())
                {
                    myStatus.setFuel(choice2, 0);
                    myMission.setMyMoney(0, (choice2 * 1000)/10000);
                    cout << "You have $" << myMission.getMyMoney() << " left." << endl;
                }
                else if(myStatus.getFuel() + choice2 >= 400000){
                    cout << "You cannot buy more than the fuel tank's capacity, which is 400K." << endl;
                }
                else if(choice2 % 10000 != 0){
                    cout << "Input must be in multiples of 10000s. Re-enter a valid quantity." << endl;
                }
                else if (choice2/10 > myMission.getMyMoney())
                {
                    cout << "You do not have enough money." << endl;
                }
            }        
            }

            else if(wormhole == 'n'){ //take them back to the main menu
                myPlanet.setPlanetName(tempPlanetName); //reset planet name to the old planet name
                break;
            }
            else{
                cout << "Invalid input." << endl;
            }
        }
        
            }
        }

        else if(wormhole == 'n'){ //if they don't want to go through the wormhole
        break; //take them back to the menu
        }

        else{ //if not y or n
            cout << "Invalid input." << endl;
        }
        
        }
        wormhole = ' ';  
        break;
    case '7':
        cout << "Are you sure you want to give up? [y/n]" << endl;
        while(charChoice != 'y' || charChoice != 'n'){
        cin >> charChoice;
        if (charChoice == 'y')
        {
            cout << "It is disappointing to hear that you have quit, humanity was depending on you." << endl;
            break;
        }
        else if (charChoice == 'n')
        {
            break;
        }
        else{
            cout << "Invalid input" << endl;
        }
        }
        break;

    default:
        break;
    }
}

//GAME END
//print logbook
int lineCount = 0;
file.open("results.txt");
cout << "Here is your Log Book: " << endl << endl;
while (getline(file, line))
{
    cout << line << endl;
    lineCount++;
    if (lineCount % 6 == 0) //place a new line between each log book print
        {
            cout << endl;
        }
}
file.close();

cout << endl;

int planetsExplored = myPlanet.getNumVisited();
double totalScore = ((myMission.getHumansSaved()-myMission.getHumansPerished()) / (8000 * (accuratelyHabitable + inaccuratelyHabitable))) / ((planetsExplored) * 100); 
cout << "Here's a summary of how you did: " << endl;
cout << "Planets explored: " << myPlanet.getNumVisited() << endl;
cout << "Planets accurately reported habitable: " << accuratelyHabitable << endl;
cout << "Planets inaccurately reported habitable: " << inaccuratelyHabitable << endl;
cout << "Humans saved (in millions): " << myMission.getHumansSaved() << endl;
cout << "Humans perished (in millions): ";
if (humanLives <= 0)
{
    cout << 8000 << endl;
}
else{
    cout << myMission.getHumansPerished() << endl;
}

if (totalScore == 100)
{
    cout << "Congratulations, got a score of 100! Great job." << endl;
}
else{
    cout << "TOTAL SCORE: " << totalScore << endl;
    cout << "Play again to see if you can do better!" << endl;
}

    return 0;
}