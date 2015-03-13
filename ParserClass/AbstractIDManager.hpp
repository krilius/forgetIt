/**
 * @file AbstractIDManager.hpp
 * @brief AbstractIDManager class definitions
 * @author manzerbredes
 * @date 11 Mars 2015
 *
 * Contain all definitions of AbstractIDManager class.
 * If you want to manage id in class (like container), use
 * this class as superclass.
 *
 */

//----- std -----
#include <string>
#include <sstream>


//----- boost -----
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.




/**
 * @class AbstractIDManager AbstractIDManager.hpp "/CryptClass/AbstractIDManager.hpp"
 * @brief Managing ID
 * @author manzerbredes
 *
 * This class should not be instantiate directly.
 *
 */
 class AbstractIDManager{


    public:
        //Constructor
        AbstractIDManager();

        //Constructor, init with id
        AbstractIDManager(std::string);

        //Destructor
        ~AbstractIDManager();


        //Getters and setters
        std::string getId();
        void setId(std::string id);


    private:
        //Generate and random id
        std::string generateId();

        std::string id; ///< String id attribute

 };
