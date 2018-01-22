#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("argc : %d\n", argc);
    printf("argv addr : %x\n", argv);
    printf("argv valu : %x\n", (*argv)+sizeof(char*));
    printf("argv[0] addr : %x\n", argv[0]);
    printf("argv[1] addr : %x\n", argv[1]);
    printf("argv[2] addr : %x\n", argv[2]);
    printf("argv[0] valu : %s\n", argv[0]);
    printf("argv[1] valu : %s\n", argv[1]);
    printf("argv[2] valu : %s\n", argv[2]);
}
