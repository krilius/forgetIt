/**
 * @file AESCrypt.cpp
 * @brief AESCrypt class definitions
 * @author manzerbredes
 * @date 8 Mars 2015
 *
 * Contain all definitions of AESCrypt class.
 *
 */

//----- class -----
#include "AESCrypt.hpp"




//Constructor
AESCrypt::AESCrypt(){
    this->hash=HASHCrypt(); //Init hash attribute
}

//Destructor
AESCrypt::~AESCrypt(){

}




//Encrypt string
std::string AESCrypt::encrypt(std::string key, std::string data){

    //Generate SHA-256
    byte digest[32];
    hash.getSHA_256(key, digest, (int)sizeof(digest));

    //Contain data encrypted
    std::string cipher;


    //Use try, catch to be ensure no problems happening
    try{
        //Create encoder to encrypt data
        CryptoPP::ECB_Mode<CryptoPP::AES>::Encryption encoder;
        encoder.SetKey( digest, sizeof(digest) );

        //Encrypt data with StreamTransformationFilter with NO PADDING
        CryptoPP::StringSource ss1(data, true,
            new CryptoPP::StreamTransformationFilter( encoder,
                new CryptoPP::StringSink( cipher ),
                    CryptoPP::StreamTransformationFilter::ZEROS_PADDING

            )
        );
    }
    catch( CryptoPP::Exception& e )
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    //return encrypted data
    return cipher;

}



//Decrypt string
std::string AESCrypt::decrypt(std::string key, std::string data){


    byte digest[32];
    hash.getSHA_256(key, digest, (int)sizeof(digest));


    //Contain data decrypted
    std::string cipher;

    //Use try, catch to be ensure no problems happening
    try {

        //Create decoder to encrypt data
        CryptoPP::ECB_Mode< CryptoPP::AES >::Decryption decoder;
        decoder.SetKey( digest, sizeof(digest) );

        //Decrypt data with StreamTransformationFilter with NO PADDING
        CryptoPP::StringSource ss3( data, true,
                new CryptoPP::StreamTransformationFilter( decoder,
                    new CryptoPP::StringSink( cipher ),
                    CryptoPP::StreamTransformationFilter::NO_PADDING
                )
        );
    }
    catch( CryptoPP::Exception& e )
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }


    int i=0;
    for(i=0;i<cipher.length();i++){
        if(cipher[i]=='\0')
            break;
    }
    cipher.erase(i,cipher.length()-1);
    //return decrypted data
    return cipher;
}
