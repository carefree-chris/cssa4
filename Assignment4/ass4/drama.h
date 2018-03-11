#ifndef DRAMA_H
#define DRAMA_H

#include "media.h"
#include <string>

using namespace std;

class Drama : public Media {

public:

    Drama(int stock, string director, string title, short year);

    string toString() const;

    // Sorts by director, then title
    bool operator==(const Media& rhItem) const;

    bool operator<(const Media& rhItem) const;

    bool operator>(const Media& rhItem) const;

private:

};
#endif // DRAMA_H