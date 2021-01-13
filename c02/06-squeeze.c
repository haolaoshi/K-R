/*
 *
 * squeeze:
 * delete all c from n */


#include <stdio.h>

void squeeze(char s[], int c)
{
    int i,j;

    for(i = j = 0; s[i] != '\0'; i++)
        if(s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';

}

main()
{

    char line[1024];

    printf("\n Pls input a line :\n");
    int c,i;
    i = 0; 
    while((c = getchar()) != EOF && c != '\n') line[i++] = c;
    line[i] = '\0';

    printf("\nWhat char would you like to del?\n");

    while((c =getchar()) && c == ' ') ;

    squeeze(line,c);
    printf("\n %s\n",line);
}
