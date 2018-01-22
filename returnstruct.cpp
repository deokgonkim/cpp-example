#include <iostream>

struct Dgkim {
    char name[10];
    int age;
};

struct Dgkim get_dgkim();

int main(int argc, char* argv[]) {
    /*Dgkim dgkim;
    dgkim.name = "DGKIM";
    dgkim.age = 30;
    */
    /*
    Dgkim dgkim = {
        "DGKIM",
        30
    };
    */
    Dgkim dgkim = get_dgkim();

    std::cout << "Name : " << dgkim.name << std::endl;
    std::cout << "Age  : " << dgkim.age << std::endl;
}

struct Dgkim get_dgkim() {
    Dgkim dgkim = {
        "DGKIM",
        30
    };
    return dgkim;
}
