/**
 * @file main.cpp
 * @brief Entry point
 * @author manzerbredes
 * @version Prototype
 * @date 8 Mars 2015
 *
 * Entry point of the application.
 *
 */



//----- std -----

#include <iostream>
#include <string>
#include <vector>

//----- class -----
#include "FileManIOFile.hpp"
#include "FileManParser.hpp"
#include "Website.hpp"

#include <list>
#include <cstdlib>
#include <libxml++/nodes/node.h>
#include <libxml++/libxml++.h>

/**
 * @fn int main(int argc, char *argv[])
 * @author manzerbredes
 * @brief main function
 * @param argc contain *argv[] length
 * @param *argv[] contain the arguments list
 * @return Return code, an int.
 */
int main(int argc, char *argv[]){

    /*
    FileManIOFile fichier("Doxygen/bob.bin");

    fichier.read("loic");

    std::cout << fichier.getData();*/


     std::stringstream xml;
     xml <<"<?xml version=\"1.0\" standalone=\"yes\" ?>\n\
<forgetIt>         \n\
<websites>       \n\
      \n\
    </websites>               \n\
</forgetIt>        \n\
                     ";


    /*FileManParser parser(xml);


    std::vector<Website> websites= parser.getContainer();
    std::cout << typeid(websites.at(0)).name();*/

    /*xmlpp::DomParser parser;
    parser.parse_file("Doxygen/doc.xml");
    xmlpp::Document* doc=parser.get_document();
    const xmlpp::Node* pNode = doc->get_root_node(); //deleted by DomParser.
    const Glib::ustring nom="news";
    const Glib::ustring nm="";
    xmlpp::Element* elem=(xmlpp::Element*)pNode;*/

    //std::vector<xmlpp::Node*> websites=pNode->find("//websites/*/attribute::id");
/*
    xmlpp::Element* ell=(xmlpp::Element*)websites.at(0);
    ell->set_child_text("56");
    elem->add_child(nom);

    std::cout << doc->write_to_string();*/
    //std::cout << (elem->get_child_text())->get_content();




    FileManParser fichier("loic");


    std::vector<Website> *bb=fichier.getWebsites();


    Website a;
    a.setTitle("pierre");


    bb->push_back(a);




    fichier.updateParser();

    std::cout << fichier.getDocument();


    return 0;

}



