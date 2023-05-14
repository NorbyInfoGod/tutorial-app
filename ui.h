//
// Created by norby on 4/9/2023.
//

#include "service.h"
#include <iostream>
#include <cstring>
class User {
private:
    Service service;
public:
    User(const Service& s) : service(s)
    {
        std::string user_choice;
        while(true){

            std::cout << "\n\nUser menu\n"
                         "1 - List all tutorials from given presenter\n"
                         "2 - See watchlist\n"
                         "3 - Delete from watchlist\n"
                         "> ";
            std::cin >> user_choice;
            std::cin.ignore();
            try {
                if(service.isNumber(user_choice)) {
                    switch (stoi(user_choice)) {
                        case 1:
                            list_by_presenter();
                            break;
                        case 2:
                            list_watchlist();
                            break;
                        case 3:
                            remove_watchlist();
                            break;
                        default:
                            throw MyException("Invalid Option\n");
                    }
                }
                else
                    throw MyException("Invalid Option\n");
            }
            catch (MyException& e)
            {
                std::cout<<e.what();
            }

        }
    }

    void list_by_presenter()
    {
        bool exists = false;
        std::string presenter;
        std::cout<<"Presenter: ";
        getline(std::cin, presenter);
        back:
        vector<Tutorial> copy(service.Repo().getLength());
        auto newsize = copy_if(service.Repo().list().begin(), service.Repo().list().end(), copy.begin(), [&presenter](const Tutorial& i){return i.getPresenter() == presenter;});
        copy.resize(distance(copy.begin(), newsize));
        for(auto& i: service.Repo().list())
        {
                std::string choice;
                std::cout<<i.toString();
                i.Watch();
                std::cout<<"Like? y/n\n> ";
                std::cin>>choice;
                if(choice == "y")
                    i.Like();
                else{
                    if(choice != "n")
                        throw MyException("Invalid Option");
                }
                std::cout<<"Add to watchlist? y/n\n> ";
                std::cin>>choice;
                if(choice == "y")
                    this->service.add_watchlist(i);
                else{
                    if(choice != "n")
                        throw MyException("Invalid Option");
                }
                std::cout<<"Do you wish to stop? y/n\n> ";
                std::cin>>choice;
                if(choice == "y")
                    goto stop;
                else{
                    if(choice != "n")
                        throw MyException("Invalid Option");
                }
                exists = true;
            }
        if(!exists)
            throw MyException("No tutorials found");
        goto back;
        stop:;
    }
    void list_watchlist()
    {
        for(auto& i : service.Watchlist().list())
        {
            std::cout<<i.toString();
        }
    }
    void remove_watchlist()
    {
        std::string index;
        std::cout<<"Index to remove: ";
        std::cin>>index;
        if(!this->service.isNumber(index))
        {
            throw MyException("Invalid index");
        }
        this->service.remove_watchlist(stoi(index));
    }
};

class Admin{
private:
    Service service;
public:
    Admin(const Service& s) : service(s)
    {
        std::string user_choice;
        while(true){

            std::cout << "\n\nAdmin menu\n"
                         "1 - Add new tutorial\n"
                         "2 - Remove tutorial\n"
                         "3 - Update tutorial\n"
                         "4 - List tutorials\n"
                         "> ";
            std::cin >> user_choice;
            std::cin.ignore();
            try {
                if(this->service.isNumber(user_choice))
                {
                    switch (stoi(user_choice)) {
                        case 1:
                            add();
                            break;
                        case 2:
                            remove();
                            break;
                        case 3:
                            update();
                            break;
                        case 4:
                            list();
                            break;
                        default:
                            throw MyException("Invalid Option\n");
                    }
                }
                else
                    throw MyException("Invalid option\n");
            }
            catch (MyException& e)
            {
                std::cout<<e.what();
            }

        }
    }

    void add()
    {
        std::string presenter, title, link, minutes, seconds, likes;
        std::cout<<"Presenter: ";
        getline(std::cin, presenter);
        std::cout<<"Title: ";
        getline(std::cin, title);
        std::cout<<"Minutes: ";
        getline(std::cin, minutes);
        if(!service.isNumber(minutes))
        {
            throw MyException("Invalid minutes");
        }
        std::cout<<"Seconds: ";
        getline(std::cin, seconds);

        if(!service.isNumber(seconds))
        {
            throw MyException("Invalid seconds");
        }
        std::cout<<"Likes: ";
        getline(std::cin, likes);

        if(!service.isNumber(likes))
        {
            throw MyException("Invalid likes");
        }
        std::cout<<"Link: ";
        getline(std::cin, link);
        if(!service.isLink(link))
        {
            throw MyException("Invalid link");
        }
        int i_minutes = stoi(minutes), i_seconds = stoi(seconds), i_likes = stoi(likes);
        Tutorial new_elem(presenter, title, i_minutes, i_seconds,i_likes, link);
        this->service.add_repository(new_elem);
    }
    void remove()
    {
        std::string index;
        std::cout<<"Index to remove: ";
        std::cin>>index;
        if(!this->service.isNumber(index))
        {
            throw MyException("Invalid index");
        }
        this->service.remove_repository(stoi(index));
    }
    void update()
    {
        std::string index;
        std::cout<<"Index to update: ";
        std::cin>>index;
        std::cin.ignore();
        if(!this->service.isNumber(index))
        {
            throw MyException("Invalid index");
        }
        else
        {
            if(stoi(index)>=this->service.Repo().getLength() || stoi(index)<0)
                throw MyException("Invalid index");
        }
        std::string presenter, title, link, minutes, seconds, likes;
        std::cout<<"Presenter: ";
        getline(std::cin, presenter);
        std::cout<<"Title: ";
        getline(std::cin, title);
        std::cout<<"Minutes: ";
        getline(std::cin, minutes);
        if(!service.isNumber(minutes))
        {
            throw MyException("Invalid minutes");
        }
        std::cout<<"Seconds: ";
        getline(std::cin, seconds);

        if(!service.isNumber(seconds))
        {
            throw MyException("Invalid seconds");
        }
        std::cout<<"Likes: ";
        getline(std::cin, likes);

        if(!service.isNumber(likes))
        {
            throw MyException("Invalid likes");
        }
        std::cout<<"Link: ";
        getline(std::cin, link);
        if(!service.isLink(link))
        {
            throw MyException("Invalid link");
        }
        int i_minutes = stoi(minutes), i_seconds = stoi(seconds), i_likes = stoi(likes);
        this->service.update_repository(stoi(index), presenter, title, i_minutes, i_seconds, i_likes, link);
    }
    void list()
    {
        for(auto& i : service.Repo().list())
        {
            std::cout<<i.toString();
        }
    }
};

