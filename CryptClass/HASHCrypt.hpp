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
 * Class who handle hashing functions on a byte* parameter.
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
        * @param size : Length of digest
        *
        * **Warning** digest will be modified.
        * Digest must be an array of byte with 16 entries
        * Invalid size can cause "Segmentation Fault"
        */
        void getMD5_128(std::string chain, byte* digest, int size);


        /**
        * @brief Create an SHA over 256 bits on a digest array of bytes.
        *
        * @param chain : Chain to hash
        * @param digest : An array of bytes (8 bits)
        * @param size : Length of digest
        *
        * **Warning** digest will be modified.
        * Digest must be an array of byte with 32 entries
        * Invalid size can cause "Segmentation Fault"
        */
        void getSHA_256(std::string chain, byte* digest, int size);   //Return SHA_256


        /**
        * @brief Convert digest to a string of HEX characters
        *
        * @param digest : an array of bytes (8 bits)
        * @param size : length of digest
        *
        * @return return a string of hex digest equivalent
        *
        * Digest must be an array of byte.
        */
        std::string digestToString(byte* digest, int size); //Return a string


        /**
        * @brief Compare 2 digest
        *
        * @param digest1 : An array of bytes (8 bits)
        * @param digest2 : An array of bytes (8 bits)
        * @param size : Length of the array digest1 or digest2
        *
        * @return return a boolean (true if digest1 equals to digest2 and false else)
        *
        * **Warning** if sizeof(digest1) != sizeof(digest 2) : segmentation fault !
        * Compare the two digest.
        *
        */
        bool compareDigest(byte* digest1, byte* digest2, int size);


    private:

        /**
        * @brief Check the digest size
        *
        * @param sizeRequired : Digest size expected
        * @param size : Given digest size
        *
        * Throw an exception, and stop the program if
        * sizeRequired != size
        * Use getInvalidDigestSizeError method.
        */
        void checkDigestSize(int sizeRequired, int size);


        /**
        * @brief Make "invalid digest size" error message.
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
