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
#include <string>
#include <vector>

//----- class -----
#include "Website.hpp"

//----- xerces -----
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XercesDefs.hpp>



class FileManParser{


    public:
        FileManParser(std::string data);



        std::vector<Website> getWebsites();

        void initWebsites();

        std::string getData();

        xercesc::DOMElement* getChildByTagName(xercesc::DOMElement* node, std::string TagName);
        std::string getContentOfChild(xercesc::DOMElement* node,std::string TagName);

    private:

        xercesc::DOMDocument* document;  ///< contain the document

        xercesc::DOMElement* root;

        std::vector<Website> websites;   ///< contain all websites entries

        std::string data;   ///< contain data to parse

};
