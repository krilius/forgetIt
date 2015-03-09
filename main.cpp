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
#include "CryptClass/AESCrypt.hpp"
#include "CryptClass/HASHCrypt.hpp"




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

    AESCrypt aes;

    chaine=aes.encrypt("loic", chaine);

    std::cout << chaine << std::endl;

    chaine=aes.decrypt("loic", chaine);

    std::cout << chaine << std::endl;


    return 0;

}
