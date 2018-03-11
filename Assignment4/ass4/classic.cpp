#include "classic.h"

Classic::Classic(int stock, string director, string title, short year, 
    string majorActor, string release): Media(stock, director, title, year)
{

    releaseDate = release;
    //TODO deal with major actor

}

string Classic::toString() const
{
    return ("Classic: " + to_string(getStock()) + ", " + getDirector() + ", " + getTitle() + ", " + releaseDate); //TODO major actor
}

bool Classic::operator==(const Media & rhItem) const
{
    return false; //TODO
}

bool Classic::operator<(const Media & rhItem) const
{
    return false;
}

bool Classic::operator>(const Media & rhItem) const
{
    return false;
}
