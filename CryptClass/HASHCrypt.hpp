/**
 * @file HASHCrypt.hpp
 * @brief HASHCrypt class header
 * @author manzerbredes
 * @date 8 Mars 2015
 *
 * Contain all prototypes of HASHCrypt class.
 *
 */

#ifndef __HASHCrypt__
#define __HASHCrypt__

//----- std -----
#include <iostream>
#include <string>
#include <sstream>

//----- crypto++ -----
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <crypto++/md5.h>   //For MD5
#include <crypto++/hex.h>   //For Hex convertion
#include <crypto++/sha.h>   //For SHA


/**
 * @class HASHCrypt HASHCrypt.hpp "/CryptClass/HASHCrypt.hpp"
 * @brief Hashing class
 * @author manzerbredes
 *
 * Class who handle hashing functions to a byte* parameter.
 * HASHCrypt try to detect errors and throw exceptions.
 * HASHCrypt use crypto++ library.
 */
class HASHCrypt{

    public:
        /**
         * @brief Contructor
         */
        HASHCrypt();

        /**
         * @brief Destructor
         */
        ~HASHCrypt();

        /**
        * @brief Create an MD5 over 128 bits on a digest array of bytes.
        *
        * @param chain : Chain to hash
        * @param digest : An array of bytes (8 bits)
        * @param size : Length of the array digest
        *
        * **Warning** digest will be modified.
        * Digest must be an array of byte with 16 entries
        */
        void getMD5_128(std::string chain, byte* digest, int size);

        /**
        * @brief Create an SHA over 256 bits on a digest array of bytes.
        *
        * @param chain : Chain to hash
        * @param digest : An array of bytes (8 bits)
        * @param size : Length of the array digest
        *
        * **Warning** digest will be modified.
        * Digest must be an array of byte with 32 entries
        */
        void getSHA_256(std::string chain, byte* digest, int size);   //Return SHA_256


        /**
        * @brief Convert digest to a string of HEX characters
        *
        * @param digest : An array of bytes (8 bits)
        * @param size : Length of the array digest
        *
        * @return a string of hex digest equivalent
        *
        * Digest must be an array of byte with 16 entries
        */
        std::string digestToString(byte* digest, int size); //Return a string of a digest

        /**
        * @brief Compare 2 digest
        *
        * @param digest1 : An array of bytes (8 bits)
        * @param digest2 : An array of bytes (8 bits)
        * @param size : Length of the array digest1 or digest2
        *
        * @return a boolean if digest1 equals to digest2
        *
        * **Warning** if sizeof(digest1) != sizeof(digest 2) : segmentation fault !
        * Compare the two digest.
        */
        bool compareDigest(byte* digest1, byte* digest2, int size);


    private:

        /**
        * @brief Check the digest size
        *
        * @param sizeRequired : Digest size expected
        * @param size : Given digest size
        *
        * Throw an exception, and stop the programm if
        * sizeRequired != size
        * Use getInvalidDigestSizeError method.
        */
        void checkDigestSize(int sizeRequired, int size);

        /**
        * @brief Make and error message.
        *
        * @param sizeRequired : Digest size expected
        * @param size : Given digest size
        *
        * @return a string correspond to the error message
        *
        * Construct an error message with sizeRequired and size.
        */
        std::string getInvalidDigestSizeError(int sizeRequired, int size);



};

#endif
