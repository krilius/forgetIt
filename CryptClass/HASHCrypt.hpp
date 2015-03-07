//----- Includes std -----

#include <string>


//----- Includes crypto++ -----

//Pour le calcule de la somme de controle MD5
#include <crypto++/md5.h>
//Pour la convertion en hexadécimal et vice-versa
#include <crypto++/hex.h>


/*----- Description -----
Classe executant divers fonctions de hachage sur
un paramètre donné à l'initialisation, ainsi celui-ci
n'est présent en mémoire qu'à l'initialisation.
Utilise la bibliothèque crypto++
*/

class HASHCrypt{

    public:
        //Constructeur
        HASHCrypt(std::string chain);

        //Destructeur
        ~HASHCrypt();

        std::string getMD5_32();    //Retourne MD5_32
        std::string getMD5_128();   //Retourne MD5_128



    private:
        //Calcule de MD5 sur 32bits
        std::string initMD5_32(std::string chain);

        //Calcule de MD5 sur 128 bits
        std::string initMD5_128(std::string chain);


        std::string MD5_32;   //Attribut MD5 sur 32bits
        std::string MD5_128;  //Attribut MD5 sur 128 bits


};
