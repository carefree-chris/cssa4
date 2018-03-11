#ifndef CLASSIC_H
#define CLASSIC_H

#include "media.h"
#include <string>

using namespace std;

class Classic : public Media {

public:

    Classic(int stock, string director, string title, short year,
            string majorActor, string releaseDate);

    string toString() const;

    // Equality based on Release Date, then Major Actor
    bool operator==(const Media& rhItem) const;

    bool operator<(const Media& rhItem) const;

    bool operator>(const Media& rhItem) const;

private:
    string releaseDate;
    


};
#endif // CLASSIC_H