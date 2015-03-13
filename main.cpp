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
#include "FileManContainer.hpp"
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




    std::string xml="<?xml version=\"1.0\" standalone=\"yes\" ?>\n\
<forgetIt>         \n\
<websites>       \n\
      \n\
    </websites>               \n\
</forgetIt>        \n\
                     ";


    FileManParser parser(xml);



    //std::cout << std::endl << parser.getData() << std::endl;






    /*std::string chaine="It's work !";
    std::string key="loic";
    AESCrypt aes;


    FileManIOFile fichier = FileManIOFile("Doxygen/bob2.bin");

    fichier.write(key,chaine);

    fichier.read(key);

    if(fichier.isReadable())
        std::cout << fichier.getData();*/

    FileManContainer container= parser.getContainer();
    std::vector<Website> websites= container.getWebsites();
    std::cout << websites.at(0).getId();

    return 0;

}
