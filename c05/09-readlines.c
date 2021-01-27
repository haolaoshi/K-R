/*
 *
 * Exercise 5-7.
 *          Rewrite readlines to stroe lines in an array supplied by main.
 *          rather than calling alloc to maintain storage.
 *          How Much faster is the program ?
 *
 */

#define MAXLEN 100
int getline(cha * ,int);

char *alloc(int);

int readlines(char *linptr[],int maxlines)
{
    int len, nlines;
    char *p,line[MAXLEN];

    nlines = 0;
    while((len = getline(line,MAXLEN)) > 0)
    {
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else{
            line[len-1] = '\0';
            strcpy(p,line);
            lineptr[nlines++] = p;
        }

    }
    return nlines;
}
