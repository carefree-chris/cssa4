#ifndef CLASSIC_H
#define CLASSIC_H

#include "media.h"
#include <string>

using namespace std;

class Classic : public Media {

public:

    

    // Equality based on Release Date, then Major Actor
    bool operator==(const Media& rhItem) const;

    bool operator<(const Media& rhItem) const;

    bool operator>(const Media& rhItem) const;

private:

};
#endif // CLASSIC_H