#include <stdio.h>

int main(int argc, char* argv[]) {
    int* number;
    number = new int;
    *number = 10000;
    printf("number address : %x\n", number);
    printf("number value   : %d\n", *number);
    delete number;
    printf("number address : %x\n", number);
    printf("number value   : %d\n", *number);
    *number = 20000;
    printf("number address : %x\n", number);
    printf("number value   : %d\n", *number);
}
