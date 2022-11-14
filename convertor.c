#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int input_base();

long input_number(int);

long to_decimal(int, long);

long from_decimal_to_base(long, int);

int main(){
    printf("Convert a number from base (2-10) to base (2-10)\n");
    int from_base = input_base();
    long number = input_number(from_base);
    printf("Convert to base:\n");
    int to_base = input_base();
    long decimal_value = to_decimal(from_base, number);
    long to_other_base = from_decimal_to_base(decimal_value, to_base);
    printf("The number in base %d is: %ld\n", to_base, to_other_base);
    return 0;
}

int input_base(){
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

long from_decimal_to_base(long number, int base){
    long base_number = 0;
    for(int i = 0; number != 0; i++){
        int reminder = number % base;
        base_number += reminder * (long)(pow(10, i));
        number /= base;
    }
    return base_number;
}