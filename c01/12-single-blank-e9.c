#include <stdio.h>


main()
{
    int c,nc;

    c = getchar();
    nc = 0;
    while(c != EOF){
        if(c == 32) {
          nc++;
        }else if(nc == 1){
          putchar(32); 
          putchar(c);
          nc = 0;
        }else if(nc > 1){
          nc = 0;
          putchar(32);
          putchar(c);
        }else{
          putchar(c);
        }
        
        c = getchar(); 
    }

}
