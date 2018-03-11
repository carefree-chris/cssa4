#include "drama.h"

Drama::Drama(int stock, string director, string title, short year) :
    Media(stock, director, title, year)
{

}

string Drama::toString() const
{
    return ("Drama: " + to_string(getStock()) + ", " + getDirector() + ", " + getTitle() + ", " + to_string(getYear()));
}

bool Drama::operator==(const Media & rhItem) const
{
    if (getTitle() == rhItem.getTitle() &&
        getDirector() == rhItem.getDirector()) {

        return true;

    }
    else {
        return false;
    }
}

bool Drama::operator<(const Media & rhItem) const
{
    if (getDirector() < rhItem.getDirector()) {

        return true;

    }
    else if (getDirector() == rhItem.getDirector()) {

        if (getTitle() < rhItem.getTitle()) {
            return true;
        }
        else {
            return false;
        }

    }
    else {
        return false;
    }
}

bool Drama::operator>(const Media & rhItem) const
{
    if (getDirector() > rhItem.getDirector()) {

        return true;

    }
    else if (getDirector() == rhItem.getDirector()) {

        if (getTitle() > rhItem.getTitle()) {
            return true;
        }
        else {
            return false;
        }

    }
    else {
        return false;
    }
}
