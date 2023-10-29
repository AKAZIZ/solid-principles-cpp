/**
 * @file Single_Responsibility_Principle.ccp
 *
 * @brief Principle 1 - Single Responsibility Principle (SRP): This principle states that a class or a function
 * has to be responsible of doing only one thing, and has to have only one reason to change.
 * 
 * Check the example below:
 *
 * @ingroup Design Principles CPP
 *
 * @author Anass Kaziz
 *
 */

// Bad Example

class ProcessAndDisplayImage {
public:
    ProcessAndDisplayImage() {
        // Object init
    }

    ~ProcessAndDisplayImage() {
        // Destructor
    }

    void processImage() {
        //  Processing logic
    }
    
    void DisplayImage() {
        // Disply logic
    }
};


// Correction of the example: Assign processing and display logics to different classes.

class ProcessImage {
public:
    ProcessImage () {
        // Object init
    }
    
    ~ProcessImage() {
        // Destructor
    }

    void processImage() {
        // Processing logic
    }
};

class DisplayImage {
public:
    DisplayImage() {
        // Object init
    }

    ~DisplayImage() {
        // Destructor
    }

    void displayImage() {
        // Display logic
    }
};


// Second bad example

class Employee {
public:
    void calculateSalary() {
        // Calculate employee's salary.
    }
    
    void generateReport() {
        // Generate a report about the employee.
    }
};

// Correction of the example:
class Employee {
public:
    void calculateSalary() {
        // Calculate employee's salary.
    }
};

class ReportGenerator {
public:
    void generateReport(const Employee& employee) {
        // Generate a report about the employee.
    }
};