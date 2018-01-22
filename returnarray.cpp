#include <iostream>

char[] get_name();

int main(int argc, char* argv[]) {
    std::cout << get_name() << std::endl;

    return 0;
}

char[] get_name() {
    char name[] = "dgkim";
    return name;
}
