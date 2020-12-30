/*
 * Exercise 1-17.
 * Write a program to print all input lines that are longer than 80 characters.
 *
 */


#include <stdio.h>



#define MAXLEN  80

int getaline(int );

main(){

    int len,c;
    char longer[MAXLEN];

    while((len = getaline(MAXLEN)) && (len >= 0)){
        printf("\n");
    }
    printf("\nExit about len = %d",len);
}

int getaline(int maxlen){

    int c,len;
    len = 0;
    char lines[MAXLEN];

    while((c = getchar()) != EOF && c != '\n'){
       if(len < maxlen){
          lines[len] = c;     
       }else if(len == maxlen){
          printf("\n[over-80]%s",lines);
       }else{
          printf("%c",c);
       }
       len++;
    }
    if(c == EOF) len = -1;
    else len++;
    return len;
}
