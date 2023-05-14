#include "UI.h"
#include "test.h"
int main()
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
    repo.add(t1);
    repo.add(t2);
    repo.add(t3);
    repo.add(t4);
    repo.add(t5);
    repo.add(t6);
    repo.add(t7);
    repo.add(t8);
    repo.add(t9);
    repo.add(t10);
    run_tests();
    std::cout<<"tests successful!\n";
    std::string x;
    std::cout<<"1 - Administrator Mode\n2 - User Mode\n3 - Exit\n> ";
    std::cin>>x;
    while(x!="1"&&x!="2"&&x!="3"){
        std::cout<<"Invalid choice\n";
        std::cout<<"1 - Administrator Mode\n2 - User Mode\n3 - Exit\n> ";
        std::cin>>x;
    }
    if(x=="1")
        Admin admin{service};
    else if(x=="2")
        User user{service};
    return 0;
}