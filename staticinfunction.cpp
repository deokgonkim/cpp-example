#include <iostream>

int someFunc(int);

int main(int argc, char* argv[])
{
    someFunc(argc);
    someFunc(argc);
}

int someFunc(int arg)
{
    //static int s = arg + 1;
    int s = arg + 1;
    std::cout << "S is " << s << std::endl;
    s ++;
}
