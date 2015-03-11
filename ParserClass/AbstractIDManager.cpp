/**
 * @file AbstractFileContainer.hpp
 * @brief FileManContainer class definitions
 * @author manzerbredes
 * @date 11 Mars 2015
 *
 * Contain all definitions of FileManContainer class.
 *
 */

#ifndef __FileManContainer__
#define __FileManContainer__



/**
 * @class Website Website.hpp "/ParserClass/FileManContainer/Website.hpp"
 * @brief Class for manager all FileMan container (websites etc...)
 * @author manzerbredes
 *
 *
 *
 */

class FileManContainer{

    public:
        FileManContainer();

        void addWebsite(Website website);
        std::vector<Website> getWebsites();

    private:

        std::vector<Website> websites;
};


#endif
