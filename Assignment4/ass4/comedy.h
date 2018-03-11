#ifndef COMEDY_H
#define COMEDY_H

#include "media.h"
#include <string>

using namespace std;

/*class ComedyFactory : public MediaFactory {
public:
    ComedyFactory() {

        Media::registerType("C", this);

    }
};*/

//static ComedyFactory global_ComedyFactory;

class Comedy : public Media {

public:
    
    Comedy(int stock, string director, string title, short year);

    string toString() const;

    // Sorts by title, then year
    bool operator==(const Media& rhItem) const;

    bool operator<(const Media& rhItem) const;

    bool operator>(const Media& rhItem) const;

private:

};
#endif // COMEDY_H