#include "drama.h"

Drama::Drama(int stock, string director, string title, short year) :
    Media(stock, director, title, year)
{

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
