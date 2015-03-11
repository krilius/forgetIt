/**
 * @file FileManParser.cpp
 * @brief FileManParser class definitions
 * @author manzerbredes
 * @date 11 Mars 2015
 *
 * Contain all implementations of FileManParser class.
 *
 */


#include "FileManParser.hpp"


FileManParser::FileManParser(std::string data){
    this->data=data;

    try {
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException& toCatch) {
        // Do your failure processing here

    }


    xercesc::XercesDOMParser *parser = new xercesc::XercesDOMParser();
    xercesc::MemBufInputSource myxml_buf((const XMLByte*)this->data.c_str(), this->data.size(), "dummy",false);

    parser->parse("Doxygen/doc.xml");


    this->document=parser->getDocument();
    this->root=this->document->getDocumentElement();

    this->initWebsites();



}



FileManContainer FileManParser::getContainer(){
    return this->container;
}


std::string FileManParser::getData(){ return this->data;};



void FileManParser::initWebsites(){

    xercesc::DOMElement* websitesElement=this->getChildByTagName(this->root, "websites");


    xercesc::DOMNodeList* nodeList=websitesElement->getChildNodes();
    XMLSize_t nodeCount = nodeList->getLength();

    for(int i=0;i<nodeCount;i++){

        xercesc::DOMNode* current=nodeList->item(i);
        std::string TagName=xercesc::XMLString::transcode(current->getNodeName());

        if( current->getNodeType() == xercesc::DOMNode::ELEMENT_NODE ) {
            Website newWebsite;

            newWebsite.setTitle(\
            this->getContentOfChild(dynamic_cast< xercesc::DOMElement* >( current ),"title"));

            newWebsite.setUrl(\
            this->getContentOfChild(dynamic_cast< xercesc::DOMElement* >( current ),"url"));

            newWebsite.setUsername(\
            this->getContentOfChild(dynamic_cast< xercesc::DOMElement* >( current ),"username"));

            newWebsite.setPassword(\
            this->getContentOfChild(dynamic_cast< xercesc::DOMElement* >( current ),"password"));

            newWebsite.setDescription(\
            this->getContentOfChild(dynamic_cast< xercesc::DOMElement* >( current ),"description"));


            this->container.addWebsite(newWebsite);

        }
    }
}


xercesc::DOMElement* FileManParser::getChildByTagName(xercesc::DOMElement* node, std::string TagName){
    xercesc::DOMNodeList* nodeList=node->getChildNodes();
    XMLSize_t nodeCount = nodeList->getLength();
    xercesc::DOMElement* returnElement=NULL;

    for(int i=0;i<nodeCount;i++){

        xercesc::DOMNode* current=nodeList->item(i);
        std::string currentTagName=xercesc::XMLString::transcode(current->getNodeName());

        if( current->getNodeType() == xercesc::DOMNode::ELEMENT_NODE ) {
            if(currentTagName.compare(TagName)==0){
                returnElement=dynamic_cast< xercesc::DOMElement* >( current );
                break;
            }
        }
    }

    return returnElement;
}


std::string FileManParser::getContentOfChild(xercesc::DOMElement* node,std::string TagName){
    xercesc::DOMElement* child=this->getChildByTagName(node,TagName);
    return xercesc::XMLString::transcode(child->getTextContent());
}
