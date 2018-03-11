#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <utility>
#include <list>

using namespace std;

class Customer {
public:

    Customer(string lName, string fName, short ID);

    

    void printHistory();

    //void addToHistory()

    string getLastName();

    string getFirstName();

    short getID();

    bool operator==(const Customer& rightHandItem) const;

    bool operator<(const Customer& rightHandItem) const;

    bool operator>(const Customer& rightHandItem) const;

private:
    string lastName;
    string firstName;
    short customerID;
    list<pair<bool, string>> history; //??? TODO

};
#endif // CUSTOMER_H