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
#include "CryptClass/HASHCrypt.hpp"


//----- Prototype -----
void aff(std::string chaine);




/**
 * @fn int main(int argc, char *argv[])
 * @author manzerbredes
 * @brief main function
 * @param argc contain *argv[] length
 * @param *argv[] contain the arguments list
 * @return Return code, an int.
 */
int main(int argc, char *argv[]){






    HASHCrypt hash= HASHCrypt();

    byte code[16];

    hash.getMD5_128("Phrase de test !", code, sizeof(code));

    for(int i=0; i<16;i++){
        std::cout << code[i];
    }


    return 0;

}




//---- Functions -----

void aff(std::string chaine){
        std::cout << chaine;
}
