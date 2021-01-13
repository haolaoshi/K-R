/*
 *
 * Exercise 2-5:
 * Write the function any (s1,s2), 
 * which returns the first location in the string s1  where any character from the string s2 occurs,
 * or -1 if s1 contains no characters from s2.
 * (The standard library function strpbrk does the same job but returns a pointer to the locations);
 *
 */

#include <stdio.h>

int any(char s1[],char s2[])
{

    int a,b,c = 0;
    int pos = 0;
    for(a = 0; s2[a];a++)
    {
       for(pos =0 ; s1[pos];pos++)
       {
          if(s2[a] == s1[pos]) return pos;
       }

    }
    return -1;
}


main()
{

    printf("\nInput a long string:\n");
    char s1[1000];
    char c;
    int i = 0;
    while((c = getchar()) != EOF && c != '\n') {
        s1[i++] = c;
    }
    s1[i] = '\0';
    i = 0;
    printf("\nInput a find string:\n");
    char s2[1000];
    while((c = getchar()) != EOF && c != '\n'){
        s2[i++] = c;
    }
    s2[i] = '\0';


    printf("\n---find \"%s\" in \"%s\"  pos at %d\n",s2,s1,any(s1,s2));
}
