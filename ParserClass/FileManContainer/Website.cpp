/**
 * @file Website.cpp
 * @brief Website class definitions
 * @author manzerbredes
 * @date 11 Mars 2015
 *
 * Contain all implementations of Website class.
 *
 */


#include "Website.hpp"


Website::Website(){

}





std::string Website::getTitle(){
    return this->title;
}
std::string Website::getUrl(){
    return this->url;
}
std::string Website::getUsername(){
    return this->username;
}
std::string Website::getPassword(){
    return this->password;
}
std::string Website::getDescription(){
    return this->description;
}




void Website::setTitle(std::string title){
    this->title = title;
}
void Website::setUrl(std::string url){
    this->url = url;
}
void Website::setUsername(std::string username){
    this->username = username;
}
void Website::setPassword(std::string password){
    this->password = password;
}
void Website::setDescription(std::string description){
    this->description = description;
}


bool Website::operator==(const Website& website) const{
    if((this->getId()).compare(website.getId())==0){
        return true;
    }
    return false;
}

