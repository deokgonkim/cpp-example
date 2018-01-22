#include <iostream>
#include "person.h"

Person::Person() {
    std::cout << "Person Constructor" << std::endl;
    name = "NO NAME";
}

Person::Person(char* initName) {
    name = initName;
}

Person::~Person() {
    std::cout << "Person Distructor" << std::endl;
}

char* Person::getName() const {
    std::cout << "Person says name" << std::endl;
    return name;
}

void Person::setName(char* newName) {
    name = newName;
}

void Person::DoSome() {
    std::cout << "Person is doing something" << std::endl;
}
