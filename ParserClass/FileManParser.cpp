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

    //String to stringstream
    (this->dataStream) << data;

    //Create parser
    //parser.parse_stream(dataStream);
    (this->parser).parse_file("Doxygen/doc.xml");

    //Retrieve document
    this->document=(this->parser).get_document();

    //Init root Node
    this->rootNode=(this->document)->get_root_node();

    //Init container:
    this->initWebsites();



}


std::string FileManParser::getDocument(){
    std::string data=(this->document)->write_to_string();
    return data;
}


std::vector<Website>* FileManParser::getWebsites(){
    return this->websites;
}




//----------------Container part------------------------
void FileManParser::initWebsites(){
    this->websites=new std::vector<Website>;

    std::vector<xmlpp::Node*> websitesNodeSet=this->rootNode->find("//websites");
    this->websitesNode=websitesNodeSet.at(0);

    std::vector<xmlpp::Node*> websiteNodeSet=this->websitesNode->find("*");

    for(int i=0;i<websiteNodeSet.size();i++){
        xmlpp::Node* current=websiteNodeSet.at(i);
        xmlpp::Element* currentElement=(xmlpp::Element*)current;

        Website newWebsite;
        newWebsite.setId(currentElement->get_attribute_value("id"));

        std::vector<xmlpp::Node*> websiteChildren=current->find("*");

        for(int j=0;j<websiteChildren.size();j++){
            xmlpp::Element* currentChild=(xmlpp::Element*)websiteChildren.at(j);

            std::list<xmlpp::Node*> contentNodes=currentChild->get_children();
            xmlpp::CdataNode* cdataNode=(xmlpp::CdataNode*)contentNodes.front();
            std::string cdataContent=cdataNode->get_content();


            if(currentChild->get_name().compare("title")==0){
                newWebsite.setTitle(cdataContent);
            }
            else if(currentChild->get_name().compare("url")==0){
                newWebsite.setUrl(cdataContent);
            }
            else if(currentChild->get_name().compare("username")==0){
                newWebsite.setUsername(cdataContent);
            }
            else if(currentChild->get_name().compare("password")==0){
                newWebsite.setPassword(cdataContent);
            }
            else if(currentChild->get_name().compare("description")==0){
                newWebsite.setDescription(cdataContent);
            }
        }
        this->websites->push_back(newWebsite);
    }
}









void FileManParser::updateParser(){
    this->rootNode->remove_child(this->websitesNode);

    xmlpp::Element* websitesNode=this->rootNode->add_child("websites");
    this->websitesNode=(xmlpp::Node*)websitesNode;

    for(int i=0;i<this->websites->size();i++){
        xmlpp::Element* current=this->websitesNode->add_child("website");
        Website currentWebsite=this->websites->at(i);

        current->set_attribute("id", currentWebsite.getId());
        xmlpp::Element* title=current->add_child("title");
        title->add_child_cdata(currentWebsite.getTitle());

        xmlpp::Element* url=current->add_child("url");
        url->add_child_cdata(currentWebsite.getUrl());

        xmlpp::Element* username=current->add_child("username");
        username->add_child_cdata(currentWebsite.getUsername());

        xmlpp::Element* password=current->add_child("password");
        password->add_child_cdata(currentWebsite.getPassword());

        xmlpp::Element* description=current->add_child("description");
        description->add_child_cdata(currentWebsite.getDescription());

    }
}
