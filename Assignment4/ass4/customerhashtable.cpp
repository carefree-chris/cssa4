#include "customerhashtable.h"


#include <iostream>//TODO remove
using namespace std;

CustomerHashTable::CustomerHashTable()
{
    customerBucket.resize(reserveSize);
    
}

CustomerHashTable::~CustomerHashTable()
{
    vector<vector<Customer*>>::iterator vectorIt;
    vector<Customer*>::iterator customerIt;

    int test = 1; //TODO remove

    vectorIt = customerBucket.begin();
    while (vectorIt != customerBucket.end()) {

        customerIt = vectorIt->begin();

        while (customerIt != vectorIt->end()) {

            delete *customerIt;
            *customerIt = nullptr;

            ++customerIt;
        }
        

        ++vectorIt;
    }
}

bool CustomerHashTable::insert(Customer* nextInsert)
{
    
    if (contains(nextInsert->getID())) {
        return false;
    }

    //cout << "TESTTESTTEST: " << (customerBucket.empty()) << endl;

    int index = nextInsert->getID() % reserveSize; //Maybe don't hardcode this number?

    customerBucket[index].push_back(nextInsert);

    return true;
}

bool CustomerHashTable::contains(short customerID)
{
    int index = (customerID) % reserveSize;

    vector<Customer*>::iterator it;

    it = customerBucket[index].begin();
    while (it != customerBucket[index].end()) {
        
        if (*it != nullptr && (*it)->getID() == customerID) {
            return true;
        }
        ++it;
    }

    return false;
}

Customer* CustomerHashTable::getByID(short customerID)
{
    return nullptr;
}
