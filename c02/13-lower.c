/*
 *
 * Exercise 2-10:
 * Rewrite the function lower, which converts uppper case letters to lower case ,with a conditional expression instead of if-else.*/

#include <stdio.h>

void lower(char s[])
{
  int i = 0 ;
  while(s[i]){
    //s[i] = s[i] >= 'A' && s[i] <= 'Z' ? s[i] - 'A' + 'a' : s[i];
    s[i] = s[i] >= 'A' && s[i] <= 'Z' ? s[i] + 32 : s[i];
    i++;
  }
 
}


main()
{

    char line[1000];

    int c = 0;
    int i = 0;
    while((c = getchar()) != EOF && c != '\n'){
        line[i++] = c;
    }

    line[i] = '\0';
    lower(line);
    printf("\n %s ",line);
}
