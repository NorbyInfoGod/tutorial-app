//
// Created by norby on 4/24/2023.
//
#pragma once
#ifndef A45_NORBYINFOGOD_TEST_H
#define A45_NORBYINFOGOD_TEST_H
#include <assert.h>
#include "service.h"

void run_tests()
{
    Repository repo{};
    Service service{repo};
    Tutorial t1("Fireship", "C++ in 100 Seconds", 2, 46, 23, "https://www.youtube.com/watch?v=MNeX4EGtR5Y" );
    Tutorial t2("Angulars", "Car Game in C++ ", 3, 20, 23, "https://www.youtube.com/watch?v=X4LyyvGLABg" );
    Tutorial t3("Fireship", "Let's make 16 games in C++: TETRIS", 4, 52, 13, "https://www.youtube.com/watch?v=zH_omFPqMO4");
    Tutorial t4("Fireship", "C++ Fundamentals", 4, 38, 12, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
    Tutorial t5("Programming with Mosh", "C++ Tutorial for Beginners", 2, 51, 23, "https://www.youtube.com/watch?v=vLnPwxZdW4Y");
    Tutorial t6("CodeBeauty", "C++ Tutorial for Beginners", 3, 25, 45, "https://www.youtube.com/watch?v=_bYFu9mBnr4");
    Tutorial t7("freeCodeCamp.org", "C++ Full Course for Beginners", 10, 43, 21, "https://www.youtube.com/watch?v=aG-1IRwYWqU");
    Tutorial t8("Derek Banas", "C++ Tutorial", 1, 28, 3, "https://www.youtube.com/watch?v=8V0EJjyDM44");
    Tutorial t9("ProgrammingKnowledge", "C++ Programming Tutorial", 5, 16, 45, "https://www.youtube.com/watch?v=zQb4C0DOQKs");
    Tutorial t10("Bucky Roberts", "C++", 98, 4, 12, "https://www.youtube.com/watch?v=2LyzBoHo5EI&list=PLAE85DE8440AA6B83");
    service.add_repository(t1);
    repo.add(t2);
    repo.add(t3);
    repo.add(t4);
    repo.add(t5);
    repo.add(t6);
    repo.add(t7);
    repo.add(t8);
    repo.add(t9);
    repo.add(t10);
    assert(service.Repo().getLength() == 10);
    assert(service.getRepo(0).getPresenter() == "Fireship");
    service.update_repository(0, "asfa",  "b", 3, 2, 1, "d");
    assert(repo[0].getPresenter() == "asfa");
    service.add_watchlist(t1);
    assert(service.getWLength()==1);
    assert(service.getWatchlist(0).getPresenter() == "Fireship");
    service.remove_watchlist(0);
    assert(service.getWLength()==0);
    service.remove_repository(9);
    assert(service.Repo().getLength() == 9);
    try
    {
        service.remove_repository(10);}
    catch(MyException& e)
    {assert(service.isLink("abcd") == 0);}
    try {
        service.add_watchlist(t1);
        service.add_watchlist(t1);
    }
    catch(MyException& e)
    {
        service.like(0);
    }
    assert(service.Repo()[0].getLikes() == 2);
    try
    {
        service.add_repository(t1);
        service.add_repository(t1);}
    catch(MyException& e)
    {assert(service.isNumber("abcd") == 0);}
    try
    {
        service.remove_watchlist(1);}
    catch(MyException& e)
    {
        assert(strcmp(e.what(), "Invalid index") == 0);
    }
    repo[1].Watch();



}

#endif //A45_NORBYINFOGOD_TEST_H
