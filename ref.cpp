#include <iostream>

int normal(int a);
int ref(int &a);

int main(int argc, char* argv[])
{
    int n;
    n = 30;
    std::cout << "number : " << n << std::endl;
    normal(30);
    std::cout << "number : " << n << std::endl;
}

int normal(int a)
{
    std::cout << "Inside normal" << std::endl;
    std::cout << "  before : " << a << std::endl;
    a ++;
    std::cout << "  after : " << a << std::endl;
}

int ref(int& a)
{
    std::cout << "Inside normal" << std::endl;
    std::cout << "  before : " << a << std::endl;
    a ++;
    std::cout << "  after : " << a << std::endl;
}
