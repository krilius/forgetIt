//----- Includes std -----

#include <iostream>
#include <string>

//----- Includes personnal Class -----
#include "CryptClass/HASHCrypt.hpp"

//----- Prototype -----
void aff(std::string chaine);




//----- Program Start -----
int main(){






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
