#include <stdio.h>



//int strlen(const char[]);
#define     LIMIT   1024
//leapyear();

main()
{
    enum boolean{NO,YES};
    enum weeks{MON,TUE,WED,THUR,FRI,SAT,SUN};

    const char msg[] = ("hello,"  "world");
//   printf("%s len = %d \n",msg,strlen(msg));
//    leapyear();
    int lim = LIMIT;

    char buffer[lim];
    char c;
    while(c= withoutand(buffer,lim) >=  0){
    //while(c= getaline(buffer,lim) >=  0){
        printf("%s",buffer);
    }
}

/**
int strlen(const char s[])
{
    int i;
    i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}
**/
leapyear(void)
{
    int from = 2000,to = 2050;

    for(from;from < to; from +=2)
    {
        if((from %4 == 0 && from % 100 != 0 ) || (from % 400 == 0))
            printf( " %d, ",from );

    }

}

int getaline(char buffer[],int lim)
{
    int i;
    int c;
    for(i = 0; i < lim -1 && ( c = getchar()) != '\n' && c != EOF ; ++i){
        buffer[i] = c;
    }
    
    return c == EOF ? -1 : i; 
}

int withoutand(char buffer[],int lim)
{
    int i,c;
    for(i = 0; i < lim - 1; i++)
    {
        c = getchar();
        if(c == '\n') break;
        if(c == EOF) break;
        buffer[i] = c;

    }
    return c == EOF ? -1 : i;
}
