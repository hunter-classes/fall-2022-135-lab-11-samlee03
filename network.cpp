#include "network.h"

Network::Network(){
    numUsers = 0; 
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; j < MAX_USERS; j++){
            following[i][j] = false;
        }
    }
}
bool isAlphanumeric(std::string str){
    for (int i = 0; i < str.length(); i++){
        if (!((str[i] <= 57 && str[i] >= 48) || (str[i] <= 90 && str[i] >= 65) || (str[i] <= 122 && str[i] >= 97))){
            return false;
        }
    }
    return true;
}
int Network::findID(std::string usrn){
    for (int i = 0; i < numUsers; i++){
        if (profiles[i].getUsername() == usrn){
            return i;
        }
    }
    return -1;
}

bool Network::addUser(std::string usrn, std::string dspn){
    if (usrn.length() > 0 && numUsers < 20 && isAlphanumeric(usrn)){
        
        for (int i = 0; i < numUsers; i++){
            if (profiles[i].getUsername() == usrn){
                return false;
            }
        }
        numUsers++;
        profiles[numUsers - 1] = Profile(usrn, dspn);
        return true;
    }
    return false;
}

bool Network::follow(std::string usrn1, std::string usrn2){
    int user1 = -1;
    int user2 = -1;
    for (int i = 0; i < numUsers; i++){
        if (profiles[i].getUsername() == usrn1){
            user1 = i;
        }
        if (profiles[i].getUsername() == usrn2){
            user2 = i;
        }
    }
    if (user1 != -1 && user2 != -1){
        following[user1][user2] = true;
        return true;
    }
    return false;
}
std::string formatName(std::string username){
    return ("\"@" + username + "\"");
}
void Network::printDot(){
    std::cout << "digraph {\n";
    for (int i = 0; i < numUsers; i++){
        std::cout << "  " << formatName(profiles[i].getUsername()) << std::endl;
    }
    std::cout << "\n";
    for (int i = 0; i < numUsers; i++){
        for (int j = 0; j < numUsers; j++){
            if (following[i][j]){
                std::cout << "  " << formatName(profiles[i].getUsername()) << " -> " << formatName(profiles[j].getUsername()) << std::endl;  
            }
        }
    }
    std::cout << "}" << std::endl;
    
}