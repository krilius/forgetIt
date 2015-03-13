/**
 * @file AESCrypt.hpp
 * @brief AESCrypt class header
 * @author manzerbredes
 * @date 8 Mars 2015
 *
 * Contain all prototypes of AESCrypt class.
 *
 */

#ifndef __AESCrypt__
#define __AESCrypt__

//----- std -----
#include "AbstractSKA.hpp"
#include "HASHCrypt.hpp"
#include <iostream>

//----- crypto++ -----
#include <crypto++/aes.h>
#include <crypto++/modes.h>
#include <crypto++/filters.h>


/**
 * @class AESCrypt AESCrypt.hpp "/CryptClass/AESCrypt.hpp"
 * @brief Class  for Advanced Encryption Standard (AES) algorithm
 * @author manzerbredes
 *
 * This class provide AES encrypt and decrypt.
 * Key used is 32 bytes key (256 bits).
 *
 * \bug Find another solution for managing padding.
 */
class AESCrypt : public AbstractSKA {


    public:
        //Constructor
        AESCrypt();

        //Destructor
        ~AESCrypt();


       /**
        * @brief Run encryptRoutine.
        *
        * @param key : key used to encrypt data
        * @param data : contain data to encrypt.
        *
        * @return string : correspond to crypted data
        *
        * Run encryptRoutine with byte* key or string key.
        * Allow you to choose between string key or byte key.
        *
        */
        std::string encrypt(std::string key, std::string data);
        std::string encrypt(byte* key, std::string data);


        /**
        * @brief Decrypt data from AES algorithm.
        *
        * @param key : key used to encrypt data
        * @param data : contain data to decrypt from AES encrypt.
        *
        * @return string : correspond to decrypted data
        *
        * Decrypt data, and return them into a string.
        *
        */
        std::string decrypt(std::string key, std::string data);



    private:

      /**
        * @brief Encrypt data with AES algorithm.
        *
        * @param key : key used to encrypt data
        * @param data : contain data to encrypt.
        *
        * @return string : correspond to crypted data
        *
        * Encrypt data, and return them into a string.
        * Padding are blank space.
        *
        */
        std::string encryptRoutine(std::string data, byte* digest, int size);


        //Attributes:

        HASHCrypt hash; ///< hash instance to generate SHA-256 hash code.


};

#endif
