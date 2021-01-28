/*
 * example.
 * argv[0] is the name by which the program was invoked,
 * so argc is at least 1.
 */


#include <stdio.h>

main1(int argc, char *argv[])
{
int i;
for( i = 1; i < argc; i++)
    printf("%s%s ",argv[i],(i < argc - 1 ) ? " " : "" );
printf("\n");
return 0;
}

main2(int argc , char* argv[])
{
    while(--argc > 0 )
        printf("%s%s " , *++argv, (argc > 1 ) ? " ": "");
    printf("\n");
    return 0;
}

#include <string.h>
#define MAXLINE 1000

int getaline(char *line,int max);

main3(int argc, char* argv[])
{
    char line[MAXLINE];
    int found = 0;
    if(argc != 2)
        printf("Usage : find pattern \n");
    else
        while(getaline(line,MAXLINE) > 0)
            if(strstr(line,argv[1]) != NULL) {
                printf("%s",line);
                found++;
            }
    return found;
}

int getaline(char *line,int max)
{
    int c;
    int len = 0 ;

    while((c = getchar()) != EOF && c != '\n'){
        line[len++] = c;
    }
    line[len] = '\0';
    return len;
}
/*
 * Optional arguments should be permitted in any order, *
 * so we impl it.
 */

main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    while(--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c){
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find : illegal option %c \n",c);
                argc = 0;
                found  = -1;
                break;

            }
    if(argc != 1)
        printf("Usage : find -x -n pattern\n");
    else
        while(getaline(line,MAXLINE) > 0){

            lineno++;
            if((strstr(line,*argv) != NULL) != except){
                if(number)
                    printf("%ld:",lineno);
                printf("%s",line);
                found++;
            }

        }
    return found;
}
