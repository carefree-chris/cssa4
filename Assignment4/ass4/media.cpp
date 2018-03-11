#include "media.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"

Media::Media(int mediaStock, string mediaDirector,
             string mediaTitle, short mediaYear)
{
    stock = mediaStock;
    director = mediaDirector;
    title = mediaTitle;
    year = mediaYear;
}

/*void Media::registerType(const string &type, MediaFactory * factory)
{
    
    factories[type] = factory;
    
}*/

Media * Media::create(string type, string data)
{
    

    if (type == "F" || type == "D" || type == "C") {

        int stock = stoi(data.substr(0, data.find(",")));

        data = data.substr(data.find(", ") + 2,
            data.length());

        string director = data.substr(0, data.find(","));

        data = data.substr(data.find(", ") + 2,
            data.length());

        string title = data.substr(0, data.find(","));

        data = data.substr(data.find(", ") + 2,
            data.length());

        short year;

        // Movie is a comedy
        if (type == "F") {

            short year = stoi(data);

            return new Comedy(stock, director, title, year);
        }

        // Movie is a drama
        if (type == "D") {

            short year = stoi(data);

            return new Drama(stock, director, title, year);
        }

        // Movie is a classic
        if (type == "C") {

            string fName = data.substr(0, data.find(" "));

            data = data.substr(data.find(" ") + 1,
                data.length());

            string lName = data.substr(0, data.find(" "));

            string majorActor = fName + " " + lName;

            data = data.substr(data.find(" ") + 1,
                data.length());

            string releaseDate = data.substr(0, data.length());

            data = data.substr(data.find(" ") + 1,
                data.length());

            year = stoi(data);

            return new Classic(stock, director, title, year, majorActor, releaseDate);

        }


    }

    return nullptr;


}

int Media::getStock() const
{
    return stock;
}

bool Media::setStock(int nStock)
{
    if (nStock <= 0) {
        return false;
    } else {
        stock = nStock;
        return true;
    }
}

string Media::getDirector() const
{
    return director;
}

string Media::getTitle() const
{
    return title;
}

short Media::getYear() const
{
    return year;
}

string Media::toString() const
{
    return getStock() + ", " + getDirector() + ", " +
           getTitle() + ", " + to_string(getYear());
}

bool Media::operator==(const Media& rhItem) const
{
    if (director == rhItem.director &&
        title == rhItem.title &&
        year == rhItem.year) {

        return true;

    } else {
        return false;
    }
}

bool Media::operator<(const Media& rhItem) const
{

    if (title < rhItem.title) {
        return true;
    }
    else if (title == rhItem.title) {
        if (year < rhItem.year) {
            return true;
        } else if (year == rhItem.year) {
            
            if (director < rhItem.director) {
                return true;
            }
            else if (director == rhItem.director) {
                return false;
            }
            else {
                return false;
            }

        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool Media::operator>(const Media& rhItem) const
{
    if (title > rhItem.title) {
        return true;
    }
    else if (title == rhItem.title) {
        if (year > rhItem.year) {
            return true;
        }
        else if (year == rhItem.year) {

            if (director > rhItem.director) {
                return true;
            }
            else if (director == rhItem.director) {
                return false;
            }
            else {
                return false;
            }

        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
