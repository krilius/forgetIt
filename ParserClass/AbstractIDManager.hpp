/**
 * @file AbstractIDManager.cpp
 * @brief AbstractIDManager class definitions
 * @author manzerbredes
 * @date 11 Mars 2015
 *
 * Contain all definitions of AbstractIDManager class.
 *
 */

#include <string>
#include <sstream>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.





 class AbstractIDManager{


    public:
        AbstractIDManager();

        std::string getId();
        void setId(std::string id);

        std::string generateId();

    private:

        std::string id;

 };
