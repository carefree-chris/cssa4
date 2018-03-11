
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "customer.h"
#include <vector>

using namespace std;

class CustomerHashTable {
public:

    CustomerHashTable();

    ~CustomerHashTable();

    bool insert(Customer* nextInsert);

    bool contains(short customerID);

    Customer* getByID(short customerID);



    

private:
    vector<vector<Customer*>> customerBucket;
    int reserveSize = 20000;

};
#endif // HASHTABLE_H