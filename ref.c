#include <stdio.h>

int normal(int a);
int ref(int *a);

int main(int argc, char* argv[])
{
    int n;
    n = 30;
    printf("number : %d\n", n);
    ref(&n);
    printf("number : %d\n", n);
}

int normal(int a)
{
    printf("Inside normal\n");
    printf("  before : %d\n", a);
    a ++;
    printf("  after : %d\n", a);
}

int ref(int* a)
{
    printf("Inside ref\n");
    printf("  before : %d\n", *a);
    (*a)++;
    printf("  after : %d\n", *a);
}
