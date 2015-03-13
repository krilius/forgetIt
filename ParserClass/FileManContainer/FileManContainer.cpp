/**
 * @file FileManContainer.cpp
 * @brief FileManContainer class definitions
 * @author manzerbredes
 * @date 11 Mars 2015
 *
 * Contain all implementation of FileManContainer class.
 *
 */


#include "FileManContainer.hpp"

FileManContainer::FileManContainer(){
}



void FileManContainer::addWebsite(Website website){
    this->websites.push_back(website);
}

std::vector<Website> FileManContainer::getWebsites(){
    return this->websites;
}
