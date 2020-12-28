#include <stdio.h>
#define LOWER   -50
#define UPPER   150
#define STEP    10

main()
{
    float fahr,celsius;

    printf("Celsius\tFahr\n");
    printf("-------------------\n");
    for(celsius = UPPER; celsius >= LOWER; celsius-= STEP){
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f  %6.1f\n",celsius,fahr);

    }
}
