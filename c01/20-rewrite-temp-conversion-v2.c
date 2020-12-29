#include <stdio.h>

float transfer(int fahr);

main()
{
    float fahr;
    int lower,upper,step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("FAHR\tCELSIUS\n");
    printf("-------------------\n");
    while(fahr <= upper){
        printf("%3.0f  %6.1f\n",fahr,(transfer(fahr)));
        fahr = fahr + step;
    }
	printf("\n");
}

float transfer(int fahr){
	return  (float)((5.0/9.0) *(fahr - 32.0));
}
