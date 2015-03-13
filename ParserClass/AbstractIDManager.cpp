/**
 * @file AbstractIDManager.cpp
 * @brief AbstractIDManager class definitions
 * @author manzerbredes
 * @date 11 Mars 2015
 *
 * Contain all implémentations of AbstractIDManager class.
 *
 */

#include "AbstractIDManager.hpp"

AbstractIDManager::AbstractIDManager(){
    this->id=this->generateId();
}

AbstractIDManager::AbstractIDManager(std::string id){
    this->id=id;
}
AbstractIDManager::~AbstractIDManager(){
    this->id=id;
}



void AbstractIDManager::setId(std::string id){
    this->id = id;
}

std::string AbstractIDManager::generateId(){
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    std::stringstream ss;
    ss << uuid;
    return ss.str();
}

std::string AbstractIDManager::getId(){
    return this->id;
}
