#include <stdio.h>
#include <ctype.h>


main()
{
    int c ;
    while((c = getchar()) != EOF){
        if(isalnum(c)) putchar(c);
        else if(c <= 32) printf("%o",c);
        else printf("%c",c);
    }
    return 0;
}
