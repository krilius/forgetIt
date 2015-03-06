//----- Includes std -----

#include <iostream>
#include <string>

//----- Includes personnal Class -----
#include "CryptClass/HASHCrypt.hpp"

//----- Prototype -----
void aff(std::string chaine);




//----- Program Start -----
int main(){

    HASHCrypt hash= HASHCrypt("Chaine");

    aff(hash.getMD5_32());

    return 0;

}




//---- Functions -----

void aff(std::string chaine){
        std::cout << chaine;
}
