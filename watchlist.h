//
// Created by norby on 4/25/2023.
//

#ifndef A6_NORBYINFOGOD_1_WATCHLIST_H
#define A6_NORBYINFOGOD_1_WATCHLIST_H
//
// Created by norby on 4/8/2023.
//

#ifndef A45_NORBYINFOGOD_WATCHLIST_H
#define A45_NORBYINFOGOD_WATCHLIST_H
#include <vector>
#include "tutorial.h"
class Watchlist {
private:
     vector<Tutorial> database;
public:
    Watchlist() = default;
    void add(const Tutorial& to_be_added)
    {
        this->database.push_back(to_be_added);
    }
    void remove(const int index)
    {
        this->database.erase(database.begin() + index);
    }
    vector<Tutorial> list()
    {
        return this->database;
    }
    int getLength()
    {
        return this->database.size();
    }
    bool search(const Tutorial& elem)
    {
        for(int i=0;i<database.size();i++)
            if(elem.getLink() == database[i].getLink())
                return true;
        return false;
    }
    Tutorial& operator[](const int index)
    {
        return this->database[index];
    }

};


#endif //A45_NORBYINFOGOD_WATCHLIST_H

#endif //A6_NORBYINFOGOD_1_WATCHLIST_H
