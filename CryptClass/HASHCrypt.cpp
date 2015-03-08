/**
 * @file HASHCrypt.cpp
 * @brief HASHCrypt class definitions
 * @author manzerbredes
 * @date 8 Mars 2015
 *
 * Contain all definitions of HASHCrypt class.
 *
 */


#include "HASHCrypt.hpp"


//Constructor
HASHCrypt::HASHCrypt(){
}

//Destructor
HASHCrypt::~HASHCrypt(){
}



void HASHCrypt::getMD5_128(std::string chain, byte* digest, int size){

    //Digest size controller
    this->checkDigestSize(CryptoPP::Weak1::MD5::DIGESTSIZE,size);

    //Create the MD5 on digest parameter
    CryptoPP::Weak1::MD5 hash;
    hash.CalculateDigest( digest, (byte*) chain.c_str(), chain.length() );

}


void HASHCrypt::getSHA_256(std::string chain, byte* digest, int size){

    //Digest size controller
    this->checkDigestSize(CryptoPP::SHA256::DIGESTSIZE,size);

    //Create the SHA-256 on digest parameter
    CryptoPP::SHA256 hash;
    hash.CalculateDigest( digest, (byte*) chain.c_str(), chain.length() );
}



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


std::string HASHCrypt::getInvalidDigestSizeError(int sizeRequired, int size){
    std::ostringstream erreurStream;
    erreurStream << "Invalid digest size ! ("<< sizeRequired <<" bytes required and "<< size <<" given)";
    return erreurStream.str();
}

