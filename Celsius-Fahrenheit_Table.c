
#include <stdio.h>

int main()
{
    printf("Celsius-Fahrenheit Table\t");
    
    float celsius, farh;
    int lower, upper, step;
    
    lower= 0;
    upper= 50;
    step= 5; 
    
    celsius= lower;
    while (celsius <= upper) {
        farh= (9.0/5.0)*(celsius+32);
        printf("%3.0f%6.1f\n", celsius, farh);
        celsius= celsius+step;
        
    }
    
    return 0;
}

