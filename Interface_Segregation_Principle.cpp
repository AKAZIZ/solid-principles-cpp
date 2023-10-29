/**
 * @file Interface_Segregation_Principle.ccp
 *
 * @brief Principle 4 - Interface Segregation Principle (ISP): A class should not be forced to implement
 * (even with empty implementation) interfaces that it doesn't need. 
 * 
 * Check the example below:
 *
 * @ingroup Design Principles CPP
 *
 * @author Anass Kaziz
 *
 */

// Bad example

class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};

class Robot : public Worker {
public:
    void work() override {
        // Robot performs work
    }
    void eat() override {
        // Robot cannot eat, so an empty implementation
    }
};

class Human : public Worker {
public:
    void work() override {
        // Human performs work
    }
    void eat() override {
        // Human eats
    }
};


// Correction of the bad example


class Eatable {
public:
    virtual void eat() = 0;
};

class Workable {
    virtual void work() = 0;
};

class Robot : public Workable {
public:
    void work() override {
        // Robot performs work
    }
};

class Human : public Workable, public Eatable {
public:
    void work() override {
        // Human performs work
    }
    void eat() override {
        // Human eats
    }
};

/* In general, better to implement properties as abstract classes to give flexibilty to drived 
class of property selection */