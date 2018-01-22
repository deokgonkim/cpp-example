#include "person.h"

class AgedPerson : public Person {
public:
    AgedPerson();
    ~AgedPerson();

    int getAge() const;
    void setAge(int newAge);

    void DoSome();

private:
    int age;
};
