//----- Includes std -----
#include <iostream>
#include <string>
#include <sstream>

//----- Includes crypto++ -----

//Pour le calcule de la MD5
#include <crypto++/md5.h>
//Pour la convertion en hexadécimal et vice-versa
#include <crypto++/hex.h>
//Pour l'utilisation de l'algorithme SHA
#include <crypto++/sha.h>


/*----- Description -----
Classe exécutant divers fonctions de hachage sur
un paramètre donné à la méthode choisie.
Gestion des exceptions.
Utilise la bibliothèque crypto++
*/

class HASHCrypt{

    public:
        //Constructeur
        HASHCrypt();

        //Destructeur
        ~HASHCrypt();

        //Contruit un MD5 de 128 bits sur le tableau digest de taille size à l'aide de la chaine chaine.
        void getMD5_128(std::string chain, byte* digest, int size);

        //Contruit un SHA de 256 bits sur le tableau digest de taille size à l'aide de la chaine chaine.
        void getSHA_256(std::string chain, byte* digest, int size);   //Retourne SHA_256

    private:

        //Arrête le programme en cas de taille de Digest invalide et affiche une erreur.
        void checkDigestSize(int sizeRequired, int size);

        //Assemble et retourne les messages d'erreurs de type : InvalidDigestSizeError
        std::string getInvalidDigestSizeError(int sizeRequired, int size);



};
