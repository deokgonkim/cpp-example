#include <iostream>
#include "agedperson.h"

void DoSomePerson(Person p);
void DoSomeAgedPerson(Person& p);

int main(int argc, char* argv[]) {
    //Person p;
    //p.setName("A Person");
    AgedPerson p;
    //p.setName("Old Person");
    p.setAge(9);
    std::cout << p.getName() << std::endl;
    std::cout << p.getAge() << std::endl;
    AgedPerson newPerson = p;

    p.setAge(10);
    std::cout << "Old Person : " << p.getName() << std::endl;
    std::cout << "Old Person : " << p.getAge() << std::endl;
    
    std::cout << "New Person : " << newPerson.getName() << std::endl;
    std::cout << "New Person : " << newPerson.getAge() << std::endl;

    DoSomePerson(p);
    DoSomePerson(newPerson);
    DoSomeAgedPerson(p);
    DoSomeAgedPerson(newPerson);
    return 0;
}

void DoSomePerson(Person p) {
    std::cout << "Person! DoSome" << std::endl;
    p.DoSome();
}

void DoSomeAgedPerson(Person& p) {
    std::cout << "Person! DoSome" << std::endl;
    p.DoSome();
}
