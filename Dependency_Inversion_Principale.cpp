/**
 * @file Dependency_Inversion_Principle.ccp
 *
 * @brief Principle 5 - Dependency Iversion Principle (DIP): High level modules should not depend
 * on low level modules. Both should depend on Abstractions. And abstration shouldn't depend
 * on details, details should depend on abstraction. This principle promotes decoupling and 
 * and flexibility in changing layers in the code.
 * 
 * Check the example below:
 *
 * @ingroup Design Principles CPP
 *
 * @author Anass Kaziz
 *
 */

// Example

#include <iostream>

// Abstraction
class Switchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

// Low-level module (detail)
class LightBulb : public Switchable {
public:
    void turnOn() override {
        std::cout << "Light bulb is on." << std::endl;
    }

    void turnOff() override {
        std::cout << "Light bulb is off." << std::endl;
    }
};

class CoffeeMachine : public Switchable {
public:
    void turnOn() override {
        std::cout << "Coffee machine is on." << std::endl;
    }

    void turnOff() override {
        std::cout << "Coffee machine is off." << std::endl;
    }
};

// High-level module
class Switch {
private:
    Switchable& device;  // Dependency on an abstraction

public:
    Switch(Switchable& device) : device(device) {}

    void operate() {
        device.turnOn();  // The high-level module depends on the abstraction
    }

    void turnOff() {
        device.turnOff(); // The high-level module depends on the abstraction
    }
};

int main() {
    LightBulb bulb;
    Switch lightSwitch(bulb); // Dependency inversion by passing the concrete implementation

    CoffeeMachine coffeeMachine;
    Switch coffeeMachineSwitch(coffeeMachine);

    lightSwitch.operate(); // Turn on the light bulb
    lightSwitch.turnOff(); // Turn off the light bulb

    coffeeMachineSwitch.operate(); // Turn on the coffee machine
    coffeeMachineSwitch.turnOff(); // Turn off the coffee machine

    return 0;
}


