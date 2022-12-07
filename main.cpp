#include <iostream>
#include "network.h"
#include <string>

int main() {

    std::cout << "Task A: \n";
    Profile p1("marco", "Marco");    
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    std::cout << p2.getUsername() << std::endl; // tarma1
    std::cout << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)
    std::cout << std::endl;
    std::cout << "Task B: \n";
    Network nw;
    std::cout << "Attempt to add user (mario, Mario): " << nw.addUser("mario", "Mario") << std::endl;     // true (1)
    std::cout << "Attempt to add user (luigi, Luigi): " << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

    std::cout << "Attempt to add user (mario, Mario2): " << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
    std::cout << "Attempt to add user (mario 2, Mario2): " << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
    std::cout << "Attempt to add user (mario-2, Mario2): " << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)
    for(int i = 2; i < 20; i++)
        std::cout << "Attempt to add user (mario" << std::to_string(i) << ", Mario" << std::to_string(i) << "): " <<  nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i)) << std::endl;   // true (1)
    std::cout << "Attempting to add user (yoshi, Yoshi): "<< nw.addUser("yoshi", "Yoshi") << std::endl;     // false (0)
    std::cout << std::endl;
    std::cout << "Task C" << std::endl;
    nw.follow("mario", "luigi");
    nw.follow("mario2", "mario3");
    nw.follow("mario3", "mario2");
    nw.printDot();
}