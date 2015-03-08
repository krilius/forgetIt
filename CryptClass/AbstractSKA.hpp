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
 * This should not be instanciate directly.
 *
 */

class AbstractSKA {

    public:
        AbstractSKA();
        ~AbstractSKA();

        virtual void encrypt();
        virtual void decrypt();
};
