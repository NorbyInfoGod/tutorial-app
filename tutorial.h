//
// Created by norby on 4/25/2023.
//

#ifndef A6_NORBYINFOGOD_1_TUTORIAL_H
#define A6_NORBYINFOGOD_1_TUTORIAL_H
using namespace std;

#include <iostream>
#include <windows.h>
#include <shellapi.h>
#include <regex>
#include <string>
class Tutorial {

private:
    int minutes{}, seconds{}, likes{};
    std::string title, presenter, link;

public:
    Tutorial() = default;

    Tutorial(const Tutorial& t)
    {
        this->title = t.title;
        this->presenter = t.presenter;
        this->link = t.link;
        this->minutes = t.minutes;
        this->seconds = t.seconds;
        this->likes = t.likes;
    }

    Tutorial(const std::string &presenter,const std::string &title, const int &minutes,const int &seconds, const int &likes, const std::string &link)
    {
        this->title = title;
        this->presenter = presenter;
        this->link = link;
        this->minutes = minutes;
        this->seconds = seconds;
        this->likes = likes;
    }

    std::string getPresenter() const {return presenter;}
    std::string getLink() const {return link;}

    int getLikes() const {return likes;}
    void Like()
    {
        likes++;
    }
    void setTitle(const std::string& new_title) {title = new_title;}
    void setPresenter(const std::string& new_presenter) {presenter = new_presenter;}
    void setLink(const std::string& new_link) {link = new_link;}

    void setMinutes(const int& new_minutes) {minutes = new_minutes;}
    void setSeconds(const int& new_seconds) {seconds = new_seconds;}
    void setLikes(const int& new_likes) {likes = new_likes;}

    void Watch() const
    {
        ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
    }

    std::string toString() const
    {
        return this->presenter + " - " + this->title + ", duration: " + std::to_string(this->minutes) + ":" + std::to_string(this->seconds) + ", " + std::to_string(this->likes) +", " + this->link + "\n";
    }
};


#endif //A6_NORBYINFOGOD_1_TUTORIAL_H
