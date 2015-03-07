#include "HASHCrypt.hpp"


//Constructeur
HASHCrypt::HASHCrypt(){
}


//Destructeur
HASHCrypt::~HASHCrypt(){
}


/*
    chain : objet de type string à hacher à l'aide de l'algorithme MD5
    digest: tableau de type byte* contenant les données hasher
    size: int faisant référence à la taille du tableau

    Attention si size!=sizeof(digest) risque d'erreur de type Segmentation fault

*/
void HASHCrypt::getMD5_128(std::string chain, byte* digest, int size){

    //Contrôle de la taille du digest
    this->checkDigestSize(CryptoPP::Weak1::MD5::DIGESTSIZE,size);

    //Calcule de la somme de controle MD5 dans un type byte* à partir du paramètre chain
    CryptoPP::Weak1::MD5 hash;
    hash.CalculateDigest( digest, (byte*) chain.c_str(), chain.length() );

}


/*
    chain : objet de type string à hacher à l'aide de l'algorithme SHA-256
    digest: tableau de type byte* contenant les données hasher
    size : int faisant référence à la taille du tableau

    Attention si size!=sizeof(digest) risque d'erreur de type Segmentation fault

*/
void HASHCrypt::getSHA_256(std::string chain, byte* digest, int size){

    //Contrôle de la taille du digest
    this->checkDigestSize(CryptoPP::SHA256::DIGESTSIZE,size);

    //Calcule du SHA-256 dans un type byte* à partir du paramètre chain
    CryptoPP::SHA256 hash;
    hash.CalculateDigest( digest, (byte*) chain.c_str(), chain.length() );
}


/*
    size : contient la taille des données passer en paramètre à la méthode de hashage choisi
*/
std::string HASHCrypt::getInvalidDigestSizeError(int sizeRequired, int size){
    std::ostringstream erreurStream;
    erreurStream << "Taille de digest invalide ! ("<< sizeRequired <<" octets requis et "<< size <<" donner)";
    return erreurStream.str();
}

/*
    sizeRequired : Taille du disgest attendu
    size : Taille du digest donné
*/
void HASHCrypt::checkDigestSize(int sizeRequired, int size){
    try{
        if(size !=sizeRequired){
            throw this->getInvalidDigestSizeError(sizeRequired, size);
        }

    }
    catch(std::string erreur){
        std::cerr << erreur <<std::endl;
        std::exit(EXIT_FAILURE);
    }
}
