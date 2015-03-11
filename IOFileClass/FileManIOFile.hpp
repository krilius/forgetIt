/**
 * @file FileManIOFile.hpp
 * @brief FileManIOFile class definitions
 * @author manzerbredes
 * @date 9 Mars 2015
 *
 * Contain all definitions of FileManIOFile class.
 *
 */


#ifndef __FileManIOFile__
#define __FileManIOFile__

//--- std -----
#include <iostream>
#include <string>
#include <fstream>

//----- class -----
#include "HASHCrypt.hpp"
#include "AESCrypt.hpp"


/**
 * @class FileManIOFile FileManIOFile.hpp "/CryptClass/FileManIOFile.hpp"
 * @brief Class for quick open and close encrypted file.
 * @author manzerbredes
 *
 * -----File organisation-----
 *
 * 16 first bytes : md5 of decrypted file
 * rest of the file : data encrypted (ASE for now)
 *
 */
class FileManIOFile {

    public:
        FileManIOFile(std::string filename);
        ~FileManIOFile();

        /**
        * @brief Read encrypted file.
        *
        * @param key : key to encrypt data
        *
        * Read data from "filename" attribute.
        * If file fully decrypted, readable var switch to true.
        *
        */
        void read(std::string key);


        /**
        * @brief Write data in encrypted file.
        *
        * @param key : key to encrypt data
        * @param data : data to write
        *
        * Write the file with or without key
        * To write data without key, you need to read it before (to save the key
        * in attribute key;
        *
        */
        void write(std::string key, std::string data);
        void write(std::string data);


        /**
        * @brief Write data in encrypted file.
        *
        * @param data : data to write (for MD5)
        * @param dataEncrypted : data to write
        *
        * Write encryptedData to filename
        *
        */
        void writeRoutine(std::string data, std::string dataEncrypted);




        /**
        * @brief True if file fully decrypted.
        *
        * Return "readable" attribute.
        *
        */
        bool isReadable();


        /**
        * @brief Get data attribute.
        *
        * Return "data" attribute.
        *
        * **Warning** if data not fully decrypted (readable!=true),
        * data will be unreadable.
        */
        std::string getData();

    private:

        std::string filename; ///< Filename attribute

        std::string data; ///< Data attribute

        bool readable; ///< Readable attribute

        byte key[32]; ///< Key in SHA-256





};

#endif
