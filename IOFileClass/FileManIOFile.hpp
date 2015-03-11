/**
 * @file FileManIOFile.hpp
 * @brief FileManIOFile class definitions
 * @author manzerbredes
 * @date 9 Mars 2015
 *
 * Contain all definitions of FileManIOFile class.
 *
 */

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
        * @brief Read encrypted file.
        *
        * @param key : key to encrypt data
        *
        * Save data to "filename" attribute.
        *
        */
        void write(std::string key, std::string data);

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





};
