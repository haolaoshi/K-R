/*
 *
 * Exercise 2-4:
 * Write an alternate versin of squeeze(s1,s2) that delete each character in s1 that matches any chatacter in the strings2.
 */


#include <stdio.h>

void sqeeze(char s1[],char s2[])
{
  int c,d;

printf("you want del every char\" %s \" from in which \"%s\" \n",s1,s2);
int b = 0;
int len = 0;
int e = 0; 
  while(s2[len])len++;
// printf("%d\n",len);

  for(c = d = 0, c =  s1[d]; s1[d]; d++)
  {
     c = s1[d];
     b = 0;
     e = 0;
     while(s2[b]){
        if(s2[b] == c){
          e++; 
        }
        if(e > 0 && b > 0 && (s2[b] != c )) s2[b- e] = s2[b];
        b++;
     }
     len-=e;
     s2[len] = '\0';
     printf("\n%d, [%d] %s, %c",d,len, s2,c);
  }
  s2[len] = '\0';
}

main()
{
   char s1[1000];
   char s2[1000];

    printf("\npls input s1 :\n");
    int i=0,c = 0;
    while((c = getchar()) != EOF && c != '\n') s1[i++] = c;
    s1[i] = '\0';

    i = 0;
    printf("\nPs input s2: \n");
    while((c = getchar()) != EOF && c != '\n') s2[i++] = c;
    s2[i] = '\0';

    sqeeze(s1,s2);


   printf("\nResult s2 = %s \n",s2);


}
