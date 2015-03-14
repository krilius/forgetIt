/**
 * @file FileManParser.hpp
 * @brief FileManParser class definitions
 * @author manzerbredes
 * @date 11 Mars 2015
 *
 * Contain all definitions of FileManParser class.
 *
 */


//----- std -----
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

//----- class -----
#include "Website.hpp"

//----- libxml++ -----
#include <cstdlib>
#include <libxml++/libxml++.h>




class FileManParser{


    public:

        //Constructor
        FileManParser(std::string data);


        //Get document in string
        std::string getDocument();


        //Get container vector pointer:
        std::vector<Website>* getWebsites();



        //Apply change that have made on container
        void updateParser();


    private:


        //Instaciate all website container
        void initWebsites();


        //Parser attributes
        std::stringstream dataStream;
        xmlpp::DomParser parser;



        //Document attributes
        xmlpp::Document* document;
        xmlpp::Node* rootNode;


        //Website attributes
        xmlpp::Node* websitesNode;
        std::vector<Website> *websites;

};
