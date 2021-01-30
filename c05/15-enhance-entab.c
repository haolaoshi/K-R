/*
 *
 * Exercise 5-12.
 *      Extend entab and detab to accept the shorthand 
 *              entab -m +n
 *      to mean tab stops every n columns,starting at column m .
 *      Choose convenient for the user default behavior
 */

#include <stdio.h>
main(int argc , char* argv[])
{

    while(argc-- > 0)
        printf("%s%s",*++argv,( argc > 1)? "  ":"");
    printf("\n");
    return 0;
}
