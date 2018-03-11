#include <iostream>
#include <fstream>

#include "trackingsystem.h"

using namespace std;

TrackingSystem::TrackingSystem() {

}

TrackingSystem::~TrackingSystem() {

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
                //Add to set?
            }

            
            //cout << "Type: " << code << ", data" << data << endl;

        }



    }
    else {
        cout << "Error: Could not open this file: " << filePath << endl;
        return false;
    }

    return true;
}

bool TrackingSystem::readInCommands(string filePath)
{
    return false;
}

void TrackingSystem::inventory()
{
}

bool TrackingSystem::history(short customerID)
{
    return false;
}
