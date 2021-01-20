/*
 *
 *trim: remove trailing blanks,tabs,newlines */

#include <stdio.h>


int trim(char s[])
{
    int n;

    for(n = strlen(s) - 1; n >= 0; n--)
        if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n') break;
    s[n+1] = '\0';
    return n;
}


main()
{
    char s[] = "  I am Good!    ";
    goto good;
    
    trim(s);
good:
    printf("%s\n",s);

}
