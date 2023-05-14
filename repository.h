//
// Created by norby on 4/25/2023.
//

#ifndef A6_NORBYINFOGOD_1_REPOSITORY_H
#define A6_NORBYINFOGOD_1_REPOSITORY_H

#include "tutorial.h"
class Repository{
private:
    vector<Tutorial> elements;
public:
    Repository() = default;;
    void add(const Tutorial& t)
    {
        elements.push_back(t);
    }
    void remove(int index)
    {
        elements.erase(elements.begin()+index);
    }
    vector<Tutorial> list()
    {
        return elements;
    }
    void update(int index, string presenter, string title, int minutes, int seconds, int likes, string link)
    {
        elements[index].setTitle(title);
        elements[index].setPresenter(presenter);
        elements[index].setMinutes(minutes);
        elements[index].setSeconds(seconds);
        elements[index].setLikes(likes);
        elements[index].setLink(link);
    }
    Tutorial& operator[](const int index)
    {
        return elements[index];
    }

    int getLength() {
        return elements.size();
    }
    bool search(const Tutorial& elem)
    {
        for(auto& i : elements)
            if(elem.getLink() == i.getLink())
                return true;
        return false;
    }
};
#endif //A6_NORBYINFOGOD_1_REPOSITORY_H
