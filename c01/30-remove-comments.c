/*
 *
 *
 * Exercise 1-23.
 *
 * Write a program to remove all comments from a C program .
 * Don't forget to handle quoted strigs and character constants properly.
 * C comments donnot nest.
 */

#include <stdio.h>
#define FIND_RIGHT  2    
#define FIND_LEFT   1 
#define MAXLINE     255

#define FOUND_SLASH 1
#define FOUND_SLASH_TWO 2
#define FOUND_SLASH_STAR 3
#define FOUND_STAR_TWO 4
#define FOUND_START_END 5

/*
 *    //
 *
 */
int getaline(char[] );
char aline[MAXLINE];
int doubleslash(char[]);

main()
{
    int c, len = 0;
    char* to_end = "//";

    //printf("%s",to_end);
      
    while((len = getaline(aline)) >= 0){
       // printf("\n----------%s------\n",aline);
        doubleslash(aline);
    }
}

int doubleslash(char aline[])
{
    int c,len;
    len = 0; 
    char slash = '/';
    char from_star = '*';

    int meet = 0;
    int j = 0;
    while(aline[len]){
       c = aline[len];
       len++;
       if(c == '/' &&  meet == 0 ){
          meet = FOUND_SLASH;
          continue;
       }else if(c == '/' && meet == FOUND_SLASH){
           meet = FOUND_SLASH_TWO;
           break;
       }else if(c == '*' && meet == FOUND_SLASH){
           meet = FOUND_SLASH_STAR;
           break;        
       }else if(meet == FOUND_SLASH){
          meet = 0;
          printf("%c",slash);
       }
       printf("%c",c);
    }

    while( meet == FOUND_SLASH_TWO && (c = aline[len]) && c != '\0'){
        len++;
    }
    while( meet == FOUND_SLASH_STAR && (c = aline[len]) && c != slash) len++;
    if(meet == FOUND_SLASH_STAR && c == slash && aline[len+1] == '*'){
        len = len + 2;
        while(aline[len]){
            printf("%c",aline[len]);
            len++;
        }
    }
    return c == EOF ? -1 : len;
}

int getaline(char aline[])
{
    int c;
    int i = 0 ;
    while((c = getchar()) && c != EOF && c != '\n'){
        aline[i++] = c;        
    }
    aline[i] = '\0';
    return c == EOF ? -1 : i;
}
