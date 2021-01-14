/*
 *
 * Exercise 3-2.
 * Write a function escape(s,t) that converts characters likes new line and tab into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch . Write a function for the other direction as well,
 * converting escape sequnes into the real characters.
 */

#include <stdio.h>

/*convert invisible characters  in t into visible s[] */
void escape(char s[],char t[])
{
    int i =0;
    int j =0;
    while(t[i]){
        char c = t[i];
        if(c == '\t'){
            s[j++] ='\\';
            s[j++] = 't';
        }else if(c == '\n'){
            s[j++] = '\\';
            s[j++] = 'n';
        }else{
            s[j++] = c;
        }
     //   printf("\ni=%d,j=%d,\t%s",i,j,s);
        i++;
    }

}


/*Use switch , convert visible characters into invisble characters */
void  aescape(char s[],char t[])
{
    int i =0; 
    int j =0;
    while(t[i]){
        if(t[i] == '\\'){
            switch(t[i]){
                case 'n':
                    s[j] = '\n';i+=2;break;
                case 't':
                    s[j] = '\t';i+=2;break;
                default:
                    s[j] = '\\';i+=1;break;
            }

        }else{
            s[j] = t[i];
            i++;
        }
    }
}


main()
{
    char t[1000];
    char s[1000];
    int c = 0;
    int i =0 ;
    while((c = getchar())&& c != EOF){
        t[i++] = c;
    }
    t[i] = '\0';
    escape(s,t);
    printf("\nconvert t=%d to s= %s",t,s);
    aescape(t,s);
    printf("\naescape s=%s, to t=%s",s,t);
}
