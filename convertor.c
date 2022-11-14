#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int input_basis();

long input_number(int);

long to_decimal(int, long);

int main(){
    int base = input_basis();
    printf("The base is: %d\n", base);
    long number = input_number(base);
    printf("The number is: %ld\n", number);
    long decimal_value = to_decimal(base, number);
    printf("The decimal number is: %ld\n", decimal_value);
    return 0;
}

int input_basis(){
    int base;
    do{
        printf("Enter base: ");
        scanf("%d", &base);
    }while(base < 2);
    return base; 
}

long input_number(int base){
    bool isValid;
    long number;
    do{
        isValid = true;
        printf("Enter number: ");
        scanf("%ld", &number);
        long copy = number;
        for(int i; copy != 0 && isValid; i++){
            int digit = copy % 10;
            copy /= 10;
            if(digit >= base) isValid = false;
        }
    }while(!isValid);
    return number;
}

long to_decimal(int base, long number){
    long decimal_value = 0;
    for(int i = 0; number != 0; i++){
        int digit = number % 10;
        number /= 10;
        decimal_value += digit * (long)(pow(base, i)); 
    }
    return decimal_value;
}