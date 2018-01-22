#include <iostream>

int get_number(int n);

int main(int argc, char* argv[]) {
    int n;
    std::cout << "n : " << n << std::endl;

    n = get_number(1);
    std::cout << "n : " << n << std::endl;
}

int get_number(int n) {
    if ( n == 2 ) {
        return 2;
    } else if ( n == 3 ) {
        return 3;
    }
}
