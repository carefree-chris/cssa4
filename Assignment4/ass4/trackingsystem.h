
#ifndef TRACKINGSYSTEM_H
#define TRACKINGSYSTEM_H

#include "customerhashtable.h"
#include "media.h"

#include <string>
#include <set>

class TrackingSystem {
public:

    TrackingSystem();

    ~TrackingSystem();

    bool readInCustomers(string filePath);

    bool readInMedia(string filePath);

    bool readInCommands(string filePath);

    void inventory();

    bool history(short customerID);
private:
    CustomerHashTable customers;
    

};
#endif // TRACKINGSYSTEM_H