#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "network.h"

TEST_CASE("Profile Class and Functions"){
    Profile p1 = Profile("John", "johnathan");
    CHECK(p1.getUsername() == "John");
    CHECK(p1.getFullName() == "johnathan (@John)");
    p1.setDisplayName("Johnny");
    CHECK(p1.getFullName() == "Johnny (@John)");
    Profile p2 = Profile();
    CHECK(p2.getUsername() == "");
    CHECK(p2.getFullName() == " (@)");
    p2.setDisplayName("Something");
    CHECK(p2.getFullName() == "Something (@)");
    Profile p3 = Profile("username", "displayname");
    CHECK(p3.getUsername() == "username");
    CHECK(p3.getFullName() == "displayname (@username)");
    p3.setDisplayName("newdisplay");
    CHECK(p3.getFullName() == "newdisplay (@username)");
}
TEST_CASE("Network Class and Functions"){
    Network nw;
    //addUser Functions
    CHECK(nw.addUser("user123", "Bob") == true); // alphanumeric & unique -- should return true
    CHECK(nw.addUser("user123", "Bob") == false); // alphanumeric but not unique -- should return false
    CHECK(nw.addUser("johnny", "Bob") == true); // alphanumeric & unique -- should return true
    CHECK(nw.addUser("johnny34", "Johnathan") == true); // return true
    CHECK(nw.addUser("kate", "katy") == true); // return true
    CHECK(nw.addUser("!invalid", "invaliduser") == false); // not alphanumeric -- should return false

    //follow Functions
    CHECK(nw.follow("user123", "johnny") == true); // both users are in the network -- should return true
    CHECK(nw.follow("user123", "randomusername") == false); // randomusername does not exist -- should return false
    CHECK(nw.follow("johnny", "user123") == true); // both users are in the network -- should return true
    CHECK(nw.follow("katy", "johnny34") == false); // katy is not a username -- should return false
}
