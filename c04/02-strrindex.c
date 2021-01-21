/*
 *
 * Exercise 4-1.
 *      Write the function strrindex(s,t),wihich returns the postion of the rightmost occurrence of t in s , or -1 if there is none.
 *
 */


#include <stdio.h>


#define MAXLEN  1000
#define PATTERN oo

int strrindex(char s[],char t[]);
int anotherline(char s[]);


main()
{
    char c;
    int pos= 0;
    char s[MAXLEN];

    while(anotherline(s) > 0){

       pos = strrindex(s,PATTERN); 
       if(pos > 0){
        printf("\nBingo! %s",s);
       }

    }

}

int anotherline(char s[])
{
    int c;
    int i =0;
    while((c = getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
int strrindex(char s[],char t[])
{
    int i,j;
    for(i = 0; s[i]; i++){

        for(j=0;t[j];j++){
        

        }

    }


}
