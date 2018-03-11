#include "customer.h"

using namespace std;

Customer::Customer(string lName, string fName, short ID)
{
    lastName = lName;
    firstName = fName;
    customerID = ID;
}

void Customer::printHistory()
{

}

string Customer::getLastName()
{
    return lastName;
}

string Customer::getFirstName()
{
    return firstName;
}

short Customer::getID()
{
    return customerID;
}

bool Customer::operator==(const Customer& rightHandItem) const
{
    if (customerID == rightHandItem.customerID) {
        return true;
    }
    else {
        return false;
    }
}

bool Customer::operator<(const Customer& rightHandItem) const
{
    if (customerID < rightHandItem.customerID) {
        return true;
    }
    else {
        return false;
    }
}

bool Customer::operator>(const Customer& rightHandItem) const
{
    if (customerID > rightHandItem.customerID) {
        return true;
    }
    else {
        return false;
    }
}
