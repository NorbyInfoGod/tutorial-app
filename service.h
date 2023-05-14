//
// Created by norby on 4/25/2023.
//

#ifndef A6_NORBYINFOGOD_1_SERVICE_H
#define A6_NORBYINFOGOD_1_SERVICE_H
#include "repository.h"
#include "watchlist.h"
class MyException: public std::exception{
private:
    char const* message;
public:
    MyException(char const* msg) : message(msg) {}
    char const* what()
    {
        return message;
    }
};
class Service
{
    private:
        Repository& repository;
        Watchlist watchlist;
    public:
        Service(Repository& r) : repository{r} {}
        Repository& Repo()
        {
            return repository;
        }
        Watchlist Watchlist()
        {
            return watchlist;
        }
        int getWLength()
        {
            return watchlist.getLength();
        }
        void like(const int index)
        {
            this->repository[index].Like();
        }
        void add_repository(const Tutorial& to_be_added)
        {
            if(this->repository.search(to_be_added))
                throw MyException("Element already present");
            this->repository.add(to_be_added);
        }

        void remove_repository(const int index)
        {
            if(index>=this->repository.getLength() || index<0)
                throw MyException("Invalid index");
            this->repository.remove(index);
        }

        void update_repository(const int index, std::string presenter, std::string title, int minutes, int seconds, int likes, std::string link)
        {
            this->repository.update(index, presenter, title, minutes, seconds, likes, link);
        }
        bool isNumber(const std::string& s)
        {
            return std::regex_match(s, std::regex("[0-9]+"));
        }
        bool isLink(const std::string& s)
        {
            return std::regex_match(s, std::regex("https://www.youtube.com/watch?v=[a-z0-9]+"));
        }
        void add_watchlist(const Tutorial& to_be_added)
        {
            if(this->watchlist.search(to_be_added))
                throw MyException("Element already present");
            this->watchlist.add(to_be_added);
        }

        void remove_watchlist(const int index)
        {
            if(index>=this->watchlist.getLength() || index<0)
                throw MyException("Invalid index");
            this->watchlist.remove(index);
        }

        Tutorial getRepo(const int index)
        {
            return this->repository[index];
        }
        Tutorial getWatchlist(const int index)
        {
            return this->watchlist[index];
        }
    };
#endif //A6_NORBYINFOGOD_1_SERVICE_H
