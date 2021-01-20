/*
 *
 * Exercise 3-3:
 *      Write a function expand(s1,s2) that expands shorthand notations like a -z in the string s1 into the equivalent complete list abc...xyz 
 *      int s2. Allow for letters of either case and digits,and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.
 *      Arrange that a leading or trailing - is taken literally.
 *
 */

#include <stdio.h>

//assuming s2 length is enough.
void expand(char s1[],char s2[])
{
   printf("%s\n",s1);
   int i = 0 ;
   int j = 0;
    char c = 0;
    int len = strlen(s1) - 1;
    for(i=0,j=0; s1[i]; i++,j++){
        if((s1[i] != '-')) {
            s2[j] = s1[i];
   //         printf("(%d=%i,%c)",j,i,s2[j]); 
        }else if(i>0 && (s1[i] = '-')&& i < len){
           if(s1[i+1]> 'z' || s1[i+1] < 'a') {
               s2[j] = s1[i];
    ///           printf("[%d=%d],%c",j,i,s2[j]);
           } else{
      //          printf("\n\t");
              for(c = s1[i-1]+ 1 ; c < s1[i+1];j++, c++){
                 s2[j] = c;
       //          printf("{%d,%d},%c ",j,i,s2[j]);
              }
              printf("\n");
              j--;
           }
        }

    }
   s2[j] = '\0'; 
  //printf("\n i = %d ,len = %d, j = %d",i,len,j);
}

main()
{
    char s1[] = "I Can Say a-z songs.";

    char s2[1000];

    expand(s1,s2);
    printf("%s\n",s2);

}
