// ass4.cpp : Defines the entry point for the console application.
//

#include "trackingsystem.h"
#include "customer.h"


using namespace std;

int main()
{

    TrackingSystem MediaStorageSystem;
    static map<string, MediaFactory*> factories;

    MediaStorageSystem.readInCustomers("data4customers.txt");
    
    MediaStorageSystem.readInMedia("data4movies.txt");
    return 0;
}

