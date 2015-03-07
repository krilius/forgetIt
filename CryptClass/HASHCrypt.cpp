#include "HASHCrypt.hpp"



//Constructeur
HASHCrypt::HASHCrypt(std::string chain){
    this->MD5_32=this->initMD5_32(chain);    //Initialisation MD5 sur 32bits
    this->MD5_128=this->initMD5_128(chain);  //Initialisation MD5 sur 128bits
}


//Destructeur
HASHCrypt::~HASHCrypt(){
}



//Retourne la somme de controle MD5 sur 32 bits
std::string HASHCrypt::initMD5_32(std::string chain){

    //Calcule de la somme de controle MD5 dans un type byte à partir du paramètre chain
    CryptoPP::Weak1::MD5 hash;
    byte digest[ CryptoPP::Weak1::MD5::DIGESTSIZE ];
    hash.CalculateDigest( digest, (byte*) chain.c_str(), chain.length() );

    //Convertion du hash en std::string
    CryptoPP::HexEncoder encoder;
    std::string output;
    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( digest, sizeof(digest) );
    encoder.MessageEnd();

    //Retourne la sortie de la convertion
    return output;
}

//Retourne la somme de controle MD5 sur 128 bits
std::string HASHCrypt::initMD5_128(std::string chain){

    //Calcule de la somme de controle MD5 dans un type byte à partir du paramètre chain
    CryptoPP::Weak1::MD5 hash;
    byte digest[ CryptoPP::Weak1::MD5::DIGESTSIZE * 4 ];
    hash.CalculateDigest( digest, (byte*) chain.c_str(), chain.length() );

    //Convertion du hash en std::string
    CryptoPP::HexEncoder encoder;
    std::string output;
    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( digest, sizeof(digest) );
    encoder.MessageEnd();

    //Retourne la sortie de la convertion
    return output;
}


//Getter MD5_32
std::string HASHCrypt::getMD5_32(){
    return this->MD5_32;
}

//Getter MD5_128
std::string HASHCrypt::getMD5_128(){
    return this->MD5_128;
}
