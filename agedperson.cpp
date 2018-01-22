#include <iostream>
#include "agedperson.h"

AgedPerson::AgedPerson()
    : Person("No name yet") {
    std::cout << "Aged Person constructor" << std::endl;
}

AgedPerson::~AgedPerson() {
    std::cout << "Aged Person distructor" << std::endl;
}

int AgedPerson::getAge() const {
    return age;
}

void AgedPerson::setAge(int newAge) {
    age = newAge;
}

void AgedPerson::DoSome() {
    std::cout << "AgedPerson is doing something" << std::endl;
}
