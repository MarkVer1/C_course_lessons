#include <stdio.h>
#include <math.h>

int main(){

    const double PI = 3.14159;
    double radius;
    double circumference;
    double area;

    printf("Enter a radius\n");
    scanf("%lf", &radius);

    circumference = 2 * PI * radius;
    area = PI * radius * radius;

    printf("Circumference: %lf\nArea: %lf", circumference, area);

    return 0;
}