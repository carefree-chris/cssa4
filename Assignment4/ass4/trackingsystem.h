
#ifndef TRACKINGSYSTEM_H
#define TRACKINGSYSTEM_H

#include "customerhashtable.h"
#include "media.h"



#include <string>
#include <set>
#include <map>

class TrackingSystem {
public:

    TrackingSystem();

    ~TrackingSystem();

    bool readInCustomers(string filePath);

    bool readInMedia(string filePath);

    bool readInCommands(string filePath);

    void inventory();

    void history(short customerID);
private:

    void parseCommand(string commandInfo);

    void borrowMedia(string commandData);

    void returnMedia(string commandData);

    struct mediaCompare {
        bool operator()(const Media* leftPtr, const Media* rightPtr) const {
            if (*leftPtr < *rightPtr) {
                return true;
            }
            else {
                return false;
            }
        }
    };

    CustomerHashTable customers;
    map<string, set<Media*, mediaCompare>> mediaStorage;

    

};
#endif // TRACKINGSYSTEM_H