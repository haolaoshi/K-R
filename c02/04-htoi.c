/*
 *
 * Convert Hex String to int values;
 *   0xabcdef; 0XABCDEF;
 */


#include <stdio.h>

main()
{

    char buffer[100];

    int len = 0;

    while((len = getHexString(buffer)) > 0){
        printf("Hex : %s  to Int : %d \n",buffer,htoi(buffer));
    }

}

int getHexString(char s[])
{
    int c ;
    int i =  0 ;
    while((c = getchar()) != EOF && c != '\n')
    {
       s[i] = c;
       i++;
    }
    s[i] = '\0';
    return c == EOF ? -1 : i;
}

int htoi(char s[])
{
    int i = 2;
    int n = 0;
    int h = 0;
    if(s[0] && s[1] && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
       while(s[i] == '0') i++;

       for(s[i];s[i];i++){
          if(s[i] >= 'A' && s[i] <= 'F') 
              h = s[i] - 'A' + 10;
          else if(s[i] >= 'a' && s[i] <= 'f')
              h = s[i] - 'a' + 10;
          else if(isdigit(s[i])){
              h = s[i] - '0';
          }else{
            printf("Somethings wrong!!!" "\n");
            break;
          }
          n = n * 16 + h; 
       }
    }
    return n;
}
