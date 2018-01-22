#include <iostream>

int main(int argc, char* argv[])
{
    int i;
    std::cout << "Enter number to check: " << std::endl;
    std::cin >> i;
    std::cout << "You entered " << i << std::endl;
    if ( 0 < i < 10 )
    {
        std::cout << "Number is between 0 and 10" << std::endl;
    }
}
