/*
 * Example.
 *
 */

#include <stdio.h>

main()
{
    char buf[BUFSIZ];
    int n;

    while((n = read(0,buf,BUFSIZ)) > 0)
        write(1,buf,n);

    return 0;
}

int getchar()
{
    char c;
    return (read(0,&c,1) == 1) ? (unsigned char) c : EOF ;

}

int getchar1()
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if(n == 0){
        n = read(0,buf,sizeof buf);
        bufp = buf;
    }
    return (--n >= 0 ) ? (unsigned char) *bufp++ : EOF;

}


