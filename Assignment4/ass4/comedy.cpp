#include "comedy.h"



Comedy::Comedy(int stock, string director, string title, short year) :
        Media(stock, director, title, year)
{

}

string Comedy::toString() const
{
    return ("Comedy: " + to_string(getStock()) + ", " + getDirector() + ", " + getTitle() + ", " + to_string(getYear()));
}

bool Comedy::operator==(const Media & rhItem) const
{
    if (getTitle() == rhItem.getTitle() &&
        getYear() == rhItem.getYear()) {

        return true;

    } else {
        return false;
    }
}

bool Comedy::operator<(const Media & rhItem) const
{   

    if (getTitle() < rhItem.getTitle()) {

        return true;

    }
    else if (getTitle() == rhItem.getTitle()) {

        if (getYear() < rhItem.getYear()) {
            return true;
        }
        else {
            return false;
        }

    } else {
        return false;
    }
}

bool Comedy::operator>(const Media & rhItem) const
{

    cout << "TEST TEST TEST" << endl;

    if (getTitle() > rhItem.getTitle()) {

        return true;

    }
    else if (getTitle() == rhItem.getTitle()) {

        if (getYear() > rhItem.getYear()) {
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
