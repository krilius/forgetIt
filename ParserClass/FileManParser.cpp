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

    //Get websites élément
    xercesc::DOMElement* websitesElement=this->getChildByTagName(this->root, "websites");

    //Make list of website
    xercesc::DOMNodeList* websiteList=websitesElement->getChildNodes();
    XMLSize_t websiteCount = websiteList->getLength();


    //Read the list of website
    for(int i=0;i<websiteCount;i++){

        xercesc::DOMNode* current=websiteList->item(i);
        std::string TagName=xercesc::XMLString::transcode(current->getNodeName());

        if( current->getNodeType() == xercesc::DOMNode::ELEMENT_NODE ) {
            Website newWebsite;

            //Get id
            XMLCh* idXMLCh=(XMLCh*)((xercesc::DOMElement*)current)->getAttribute((XMLCh*) xercesc::XMLString::transcode("id"));
            //Convert id to string from XMLCh
            std::string id=xercesc::XMLString::transcode(idXMLCh);

            //Assign id
            newWebsite.setId(id);

            //Assign title
            newWebsite.setTitle(\
            this->getContentOfChild(dynamic_cast< xercesc::DOMElement* >( current ),"title"));

            //Assign url
            newWebsite.setUrl(\
            this->getContentOfChild(dynamic_cast< xercesc::DOMElement* >( current ),"url"));

            //Assign username
            newWebsite.setUsername(\
            this->getContentOfChild(dynamic_cast< xercesc::DOMElement* >( current ),"username"));

            //Assign password
            newWebsite.setPassword(\
            this->getContentOfChild(dynamic_cast< xercesc::DOMElement* >( current ),"password"));

            //Assign description
            newWebsite.setDescription(\
            this->getContentOfChild(dynamic_cast< xercesc::DOMElement* >( current ),"description"));

            //Add website to container
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
