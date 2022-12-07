#include "profile.h"

Profile::Profile(){
    displayname = "";
    username = "";
}

Profile::Profile(std::string usrn, std::string dspn){
    displayname = dspn;
    username = usrn;
}

std::string Profile::getUsername(){
    return username;
}

std::string Profile::getFullName(){
    std::string fullname = displayname + " (@" + username + ")";
    return fullname;
}

void Profile::setDisplayName(std::string dspn){
    displayname = dspn;
}