#include <stdio.h>

int main(){
    int variable = 5;
    int* pVar = &variable;
    printf("Hello World!\n");
    printf("Size of Integer %ld\n", sizeof(int));
    printf("Address of variable is: %p\n", pVar);
    printf("Address of int variable + 1 is: %p\n", pVar + 1);
    return 0;
}