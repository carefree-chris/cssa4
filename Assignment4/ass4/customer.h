#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

#include "customer.h"

using namespace std;

class Customer {
public:

    Customer(string lName, string fName, short ID);

    +Customer();

    void printHistory();

    //void addToHistory()

    string getLastName();

    string getFirstName();


    bool operator==(const Customer& rightHandItem) const;

    bool operator<(const Customer& rightHandItem) const;

    bool operator>(const Customer& rightHandItem) const;

private:
    string lastName;
    string firstName;
    short customerID;
    List<Pair<bool, string>> history;

};
#endif // CUSTOMER_H