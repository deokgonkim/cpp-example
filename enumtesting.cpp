#include <iostream>


enum Status { NONE, NORMAL, FAULT };

int main(int argc, char* argv[])
{
    Status stat = NONE;
    std::cout << stat << std::endl;
    return 0;
}
