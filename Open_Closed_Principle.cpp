/**
 * @file Open_Closed_Principle.ccp
 *
 * @brief Principle 2 - Open Closed Principle (OCP): This principle states that a class
 * has to be open for extension but close for modification. This means that if a new instance
 * of the class has requires a different behaviour, this behaviour can be extended without
 * modifying the existing code. Practically, this can be done with: Abstration + Polymorphism.
 * 
 * Check the example below:
 *
 * @ingroup Design Principles CPP
 *
 * @author Anass Kaziz
 *
 */

// Bad Example:

class Shape {
public:
    double calculateArea() {
            return x * y;
    }
private:
    double x;
    double y;
};

/* The calculateArea function doesn't fit with the new Shape instance which is a circle.
This requires a modification of the function itself */
Shape circle;  

// Correction of the example: Use Abstraction + Polymorphism

class Shape {
public:
    virtual double calculateArea() const = 0;
};

class Rectangle: public Shape {
public:
    double calculateArea() const override {
        return x * y;
    }
private:
    double x;
    double y;
};

class Circle: public Shape {
    public:
        double calculateArea() const override {
            return radius * radius * 3.14;
        }

    private:
        double radius;
};


// Second Bad Example

class Circle {
public:
    double radius;
};

class AreaCalculator {
public:
    double calculateArea(const Circle& circle) {
        return 3.14159265359 * circle.radius * circle.radius;
    }
};

// Correction of the bas example: After applying OCP using abstraction and polymorphism:
class Shape {
public:
    virtual double calculateArea() const = 0;
};

class Circle : public Shape {
public:
    double radius;
    double calculateArea() const override {
        return 3.14159265359 * radius * radius;
    }
};

/*We made the whole module close to modification, by making the calcylateArea function
a virtual function of an abstract class */