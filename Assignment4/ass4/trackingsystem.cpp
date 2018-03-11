#include <iostream>
#include <fstream>

#include "trackingsystem.h"
#include <iterator> //TODO remove
#include <algorithm>
using namespace std;

TrackingSystem::TrackingSystem() {

}

TrackingSystem::~TrackingSystem() {

    map<string, set<Media*, mediaCompare>>::iterator mapIt;
    set<Media*, mediaCompare>::iterator setIt;

    mapIt = mediaStorage.begin();
    while (mapIt != mediaStorage.end()) {

        setIt = mapIt->second.begin();

        while (setIt != mapIt->second.end()) {

            delete *setIt;

            ++setIt;

        }

        ++mapIt;
    }

}

bool TrackingSystem::readInCustomers(string filePath)
{


    ifstream file(filePath);
    string nextLine = "";

    int lineN = 1; // TODO remove

    if (file.is_open()) {

        

        while (!file.eof()) {
            
            getline(file, nextLine);
            if (nextLine.length() == 0) {
                continue;
            }


            short id = stoi(nextLine.substr(0,nextLine.find(" ")));

            nextLine = nextLine.substr(nextLine.find(" ") + 1,
                nextLine.length());

            string lName = nextLine.substr(0, nextLine.find(" "));

            nextLine = nextLine.substr(nextLine.find(" ") + 1,
                nextLine.length());

            string fName = nextLine.substr(0, nextLine.length());

            
            Customer* nCustomer = new Customer(lName, fName, id);

            if (!customers.insert(nCustomer)) {
                cout << "Error: Could not insert customer with ID: " << id 
                     << " (does customer already exist?)" << endl;
            }
        }

        

    }
    else {
        cout << "Error: Could not open this file: " << filePath << endl;
        return false;
    }

    return true;
}

bool TrackingSystem::readInMedia(string filePath)
{

    ifstream file(filePath);
    string nextLine = "";

    if (file.is_open()) {

        while (!file.eof()) {

            getline(file, nextLine);
            if (nextLine.length() == 0) {
                continue;
            }


            string code = nextLine.substr(0, nextLine.find(", "));

            nextLine = nextLine.substr(nextLine.find(", ") + 2,
                nextLine.length());

            string data = nextLine;

            Media* nMedia = Media::create(code, data);

            if (nMedia == nullptr) {
                cout << "Error: Was not able to read media with code '"
                     << code << "'" << endl;
            }
            else {
                mediaStorage[code].insert(nMedia);
            }

        }

    }
    else {
        cout << "Error: Could not open this file: " << filePath << endl;
        return false;
    }

    //cout << boolalpha << endl;
    //cout << "IMPORTANT TEST: " << is_sorted(mediaStorage["C"].begin(), mediaStorage["C"].end()) << endl;

    return true;
}

bool TrackingSystem::readInCommands(string filePath)
{

    ifstream file(filePath);
    string nextLine = "";

    int lineN = 1; // TODO remove

    if (file.is_open()) {



        while (!file.eof()) {

            getline(file, nextLine);
            if (nextLine.length() == 0) {
                continue;
            }

            parseCommand(nextLine);

        }

    }
    else {
        cout << "Error: Could not open this file: " << filePath << endl;
        return false;
    }

    return true;
}

void TrackingSystem::inventory()
{

    cout << endl << "----------------INVENTORY----------------" << endl;

    map<string, set<Media*, mediaCompare>>::reverse_iterator mapIt;
    set<Media*, mediaCompare>::iterator setIt;

    mapIt = mediaStorage.rbegin();
    while (mapIt != mediaStorage.rend()) {

        setIt = mapIt->second.begin();

        while (setIt != mapIt->second.end()) {

            

            cout << (*setIt)->toString() << endl;

            ++setIt;

        }

        ++mapIt;
    }
}

void TrackingSystem::history(short customerID)
{
    Customer* IDMatch;
    IDMatch = customers.getByID(customerID);

    if (IDMatch == nullptr) {

        cout << "Error: Cannot get history of customer ID = " << customerID
            << " (customer does not exist)." << endl;

    }
    else {

        cout << endl << "---------------- Customer " << customerID << 
            " History----------------" << endl;
        //TODO properly print history
    }
}

void TrackingSystem::parseCommand(string commandInfo)
{
    char code = commandInfo[0];

    switch (code) {

    case 'B': // Borrow

        borrowMedia(commandInfo);

        break;
    case 'R': // Return

        returnMedia(commandInfo);

        break;
    case 'I': // Inventory
        inventory();
        break;
    case 'H': // History

        commandInfo = commandInfo.substr(1, commandInfo.length());

        short ID;
        ID = stoi(commandInfo);

        history(ID);
        
        break;
    default:
        cout << "Error: '" << code << "' is not a valid command code." << endl;
        break;
    }


}

void TrackingSystem::borrowMedia(string commandData)
{
    commandData = commandData.substr(2, commandData.length());

    short ID;
    ID = stoi(commandData);

    Customer* IDMatch;
    IDMatch = customers.getByID(ID);

    if (IDMatch == nullptr) {

        cout << "Error: Customer ID = " << ID
            << " cannot borrow items (customer does not exist)." << endl;
        return;
    }

    commandData = commandData.substr(commandData.find(" ") + 1,
                  commandData.length());
    string mediaType = commandData.substr(0, 1);

    if (mediaType != "D") {
        cout << "Error: Cannot borrow. Media type '" << mediaType <<
            "' is not a valid code." << endl;
        return;
    }

    commandData = commandData.substr(commandData.find(" ") + 1,
                  commandData.length());
    string itemCode = commandData.substr(0, 1);

    commandData = commandData.substr(commandData.find(" ") + 1,
                  commandData.length());

    if (mediaStorage[itemCode].size() <= 0) {

        cout << "Error: There is no media available to borrow under category '"
            << itemCode << ".' This category is empty, or does not exist."
            << endl;
    }



    //cout << "TEST TEST " << commandData << endl;
    //cout << "TEST TEST TEST CODE: " << itemCode << endl;
}

void TrackingSystem::returnMedia(string commandData)
{
}
