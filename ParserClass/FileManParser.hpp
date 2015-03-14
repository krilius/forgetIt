/**
 * @file FileManParser.hpp
 * @brief FileManParser class definitions
 * @author manzerbredes
 * @date 11 Mars 2015
 *
 * Contain all definitions of FileManParser class.
 *
 */



#ifndef __FileManParser__
#define __FileManParser__



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



/**
 * @class FileManParser FileManParser.hpp "/ParserClass/FileManContainer/FileManParser.hpp"
 * @brief Class for parser un xml file in a string.
 * @author manzerbredes
 *
 * Parse string using libxml++ library.
 *
 */
class FileManParser{


    public:

        //Constructor
        FileManParser(std::string data);


      /**
        * @brief Get document in string
        *
        * @return a string that contain the document
        *
        * Return current document.
        * To have an up-to-date document, please run updateParser() before.
        *
        */
        std::string getDocument();


      /**
        * @brief Write data in encrypted file.
        *
        * @return vector pointer that point to the vector of website in document
        *
        * You can modified this vector, and for apply change run updateParser()
        *
        */
        std::vector<Website>* getWebsites();



      /**
        * @brief Update the parser
        *
        * Apply all modifications you have made on the vector object (example std::vector<Website>* websites).
        *
        */
        void updateParser();


    private:


      /**
        * @brief Instanciate websites vector
        *
        * Read the document and create all Website object and put them into
        * the websites vector attribute.
        *
        */
        void initWebsites();


        //Parser attributes
        std::stringstream dataStream;   ///< Contain the document you want to parse
        xmlpp::DomParser parser;        ///< Contain the parser



        //Document attributes
        xmlpp::Document* document;      ///< Contain the document (generate by the parser and dataStream)
        xmlpp::Node* rootNode;          ///< Contain the root node of the document


        //Website attributes
        xmlpp::Node* websitesNode;      ///< Contain the websites node of the document
        std::vector<Website> *websites; ///< Contain all website of the document (you can modify it and run updateParser to apply all modifications).

};


#endif
