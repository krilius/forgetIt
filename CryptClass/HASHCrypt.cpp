#include "HASHCrypt.hpp"



//Constructeur
HASHCrypt::HASHCrypt(std::string chain){
    this->chain=chain;  //Initialisation de l'attribut chain
}

//Destructeur
HASHCrypt::~HASHCrypt(){
}



//Retourne la somme de controle MD5 sur 32 bits de l'attribut chain
std::string HASHCrypt::getMD5_32(){

    //Calcule de la somme de controle MD5 dans un type byte à partir de l'attribut chain
    CryptoPP::Weak1::MD5 hash;
    byte digest[ CryptoPP::Weak1::MD5::DIGESTSIZE ];
    hash.CalculateDigest( digest, (byte*) this->chain.c_str(), this->chain.length() );

    //Convertion du hash en std::string
    CryptoPP::HexEncoder encoder;
    std::string output;
    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( digest, sizeof(digest) );
    encoder.MessageEnd();

    //Retourne la sortie de la convertion
    return output;
}

//Retourne la somme de controle MD5 sur 128 bits de l'attribut chain
std::string HASHCrypt::getMD5_128(){

    //Calcule de la somme de controle MD5 dans un type byte à partir de l'attribut chain
    CryptoPP::Weak1::MD5 hash;
    byte digest[ CryptoPP::Weak1::MD5::DIGESTSIZE * 4 ];
    hash.CalculateDigest( digest, (byte*) this->chain.c_str(), this->chain.length() );

    //Convertion du hash en std::string
    CryptoPP::HexEncoder encoder;
    std::string output;
    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( digest, sizeof(digest) );
    encoder.MessageEnd();

    //Retourne la sortie de la convertion
    return output;
}
