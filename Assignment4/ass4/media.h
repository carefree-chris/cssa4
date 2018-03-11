#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Media;

class MediaFactory {
public:
    virtual ~MediaFactory() {}
    virtual Media* create() = 0;
};


class Media {
public:
    

    //static void registerType(const string& type, MediaFactory* factory);

    static Media* create(string type, string data);

    Media(int stock, string director, string title, short year);

    int getStock() const;

    bool setStock(int nStock);

    string getDirector() const;

    string getTitle() const;

    short getYear() const;

    virtual string toString() const;

    virtual bool operator==(const Media& rhItem) const;

    virtual bool operator<(const Media& rhItem) const;

    virtual bool operator>(const Media& rhItem) const;

private:

    //static map<string, MediaFactory*> factories;

    int stock;
    string director;
    string title;
    short year;


};
#endif // MEDIA_H