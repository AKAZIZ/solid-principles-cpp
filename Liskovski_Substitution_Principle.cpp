/**
 * @file Liskovski_Principle.ccp
 *
 * @brief Principle 3 - Liskovski Substitution Principle (LSP): Objects of drived class can replace objects 
 * of their base class without impact on the correctness of the code. This principle should 
 * be applicable by default, as long as the inheritance is done correctly.
 * 
 * Check the example below:
 *
 * @ingroup Design Principles CPP
 *
 * @author Anass Kaziz
 *
 */

// Example

class Dog {
public:
        virtual void bark() const {
            // Barking logic
        }
};

class GermanShepherd: public Dog {
public:
        void bark() const override {
            // Barking logic for GermanShepherd class
        }
};


/* In the implementation of the makeDogBark function, the dog instance can be replaced with an instance
of GermanShepherd and the code still be compiled correctly */
int makeDogBark(const Dog& dog) {

    dog.bark();
}
