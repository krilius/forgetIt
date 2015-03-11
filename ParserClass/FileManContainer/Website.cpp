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
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    std::stringstream ss;
    ss << uuid;
    this->id=ss.str();
}




std::string Website::getId(){
    return this->id;
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



void Website::setId(std::string id){
    this->id = id;
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
