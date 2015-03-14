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





/**
 * @fn int main(int argc, char *argv[])
 * @author manzerbredes
 * @brief main function
 * @param argc contain *argv[] length
 * @param *argv[] contain the arguments list
 * @return Return code, an int.
 */
int main(int argc, char *argv[]){


    //TEST PARSER FAKE ARGUMENT
    FileManParser xmlParser("");

    std::vector<Website> *siteWeb=xmlParser.getWebsites();

    siteWeb->erase(siteWeb->begin()+1);

    xmlParser.updateParser();


    //Save modification in file

    FileManIOFile save("Doxygen/bob.bin");

    save.write("loic", xmlParser.getDocument());

    //Print
    std::cout << xmlParser.getDocument();




    return 0;
}



