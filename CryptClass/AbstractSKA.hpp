/**
 * @file AbstractSKA.hpp
 * @brief Class for Symmetric-Key Algorithm (SKA)
 * @author manzerbredes
 * @date 8 Mars 2015
 *
 * Specify which method the algorithm must be implement.
 *
 */



/**
 * @class AbstractSKA AbstractSKA.hpp "/CryptClass/AbstractSKA.hpp"
 * @brief Class for Symmetric-Key Algorithm (SKA)
 * @author manzerbredes
 *
 * This class should not be instanciate directly.
 *
 */

class AbstractSKA {

    public:
        AbstractSKA(){
        }
        ~AbstractSKA(){
        }

       /**
        * @brief Encrypt data.
        *
        * @param key : key used to encrypt data
        * @param data : contain data to encrypt.
        *
        * This method must be overwritten.
        * **Warning** data will be modified.
        *
        */
        virtual void encrypt(std::string key, char* data) = 0;

       /**
        * @brief Decrypt data.
        *
        * @param key : key used to decrypt data
        * @param data : contain data to decrypt.
        *
        * This method must be overwritten.
        * **Warning** data will be modified.
        *
        */
        virtual void decrypt(std::string key, char* data) = 0;
};
