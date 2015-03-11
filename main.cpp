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

//----- class -----
#include "AESCrypt.hpp"
#include "HASHCrypt.hpp"
#include "FileManIOFile.hpp"



/**
 * @fn int main(int argc, char *argv[])
 * @author manzerbredes
 * @brief main function
 * @param argc contain *argv[] length
 * @param *argv[] contain the arguments list
 * @return Return code, an int.
 */
int main(int argc, char *argv[]){

    std::string chaine="It's work !";
    std::string key="loic";
    AESCrypt aes;


    FileManIOFile fichier = FileManIOFile("Doxygen/bob.bin");

    fichier.write(key, chaine);

    fichier.read(key);

    if(fichier.isReadable())
        std::cout << fichier.getData();

    fichier.write(chaine+" YES");

    fichier.read(key);

    if(fichier.isReadable())
        std::cout << fichier.getData();

    return 0;

}
