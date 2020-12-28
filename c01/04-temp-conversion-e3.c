#include <stdio.h>

main()
{
    float fahr,celsius;
    int lower,upper,step;

    lower = -50;
    upper = 150;
    step = 10;

    celsius = lower;

    printf("Celsius\tFahr\n");
    printf("-------------------\n");
    for(celsius = 150; celsius >= lower; celsius-= step){
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f  %6.1f\n",celsius,fahr);

    }
}
