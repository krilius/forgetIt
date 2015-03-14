/**
 * @file Website.hpp
 * @brief Website class definitions
 * @author manzerbredes
 * @date 11 Mars 2015
 *
 * Contain all definitions of Website class.
 *
 */

#ifndef __WEBSITE__
#define __WEBSITE__

#include <string>


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

#include <string>
#include "AbstractIDManager.hpp"

/**
 * @class Website Website.hpp "/ParserClass/FileManContainer/Website.hpp"
 * @brief Class for quick open and close encrypted file.
 * @author manzerbredes
 *
 * Container for website data.
 *
 */
class Website : public AbstractIDManager {


    public:

        Website();

        /**
        * @brief Containner getters.
        */

        std::string getTitle();
        std::string getUrl();
        std::string getUsername();
        std::string getPassword();
        std::string getDescription();


        /**
        * @brief Containner setters.
        */
        void setTitle(std::string title);
        void setUrl(std::string url);
        void setUsername(std::string username);
        void setPassword(std::string password);
        void setDescription(std::string description);


      /**
        * @brief Equality comparator
        */
        bool operator==(const Website& website) const;

    private:

        std::string title;          ///< Title of the website
        std::string url;            ///< Url of the website
        std::string username;       ///< username of the account
        std::string password;       ///< password of the account
        std::string description;    ///< Description of the website
};


#endif
