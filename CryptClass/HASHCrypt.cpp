/**
 * @file HASHCrypt.cpp
 * @brief HASHCrypt class definitions
 * @author manzerbredes
 * @date 8 Mars 2015
 *
 * Contain all definitions of HASHCrypt class.
 *
 */

//----- class -----
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


//Check the size of the digest
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

//Make the error
std::string HASHCrypt::getInvalidDigestSizeError(int sizeRequired, int size){
    std::ostringstream erreurStream;
    erreurStream << "Invalid digest size ! ("<< sizeRequired <<" bytes required and "<< size <<" given)";
    return erreurStream.str();
}


//Compare 2 digest (same size)
bool HASHCrypt::compareDigest(byte* digest1, byte* digest2, int size){

    //Try is more safe
    try
    {
        //Compare the two digest
        for(int i=0; i<size; i++){
            //Return false if digest are different
            if(digest1[i] != digest2[i]){
                return false;
            }
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception catched : " << e.what() << std::endl;
    }

    //Return true if digest are equals
    return true;
}


//Convert digest to string
std::string HASHCrypt::digestToString(byte* digest, int size){

    CryptoPP::HexEncoder encoder;
    std::string output;
    encoder.Attach( new CryptoPP::StringSink( output ) );
    encoder.Put( digest, size );
    encoder.MessageEnd();

    return output;
}
