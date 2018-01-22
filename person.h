
class Person {
public:
    Person();
    Person(char* name);
    ~Person();

    char* getName() const;
    void setName(char* name);

    virtual void DoSome();

private:
    char* name;
};
