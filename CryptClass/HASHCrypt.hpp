//----- Includes std -----

#include <string>


//----- Includes crypto++ -----
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

//Pour le calcule de la somme de controle MD5
#include "crypto++/md5.h"
//Pour la convertion en hexadécimal et vice-versa
#include "crypto++/hex.h"


/*----- Description -----
Classe executant divers fonctions de hashage sur
un attribut chain en utilisant la bibiothèque crypto++
*/

class HASHCrypt{

    public:
        HASHCrypt(std::string chain);
        ~HASHCrypt();

        std::string getMD5_32();   //Calcule de la somme de controle MD5 sur 32bit
        std::string getMD5_128();   //Calcule de la somme de controle MD5 sur 128bit



    private:
        std::string chain;  //Attribut paramètre des fonctions de hashage


};
