/*
 *
 * reverse : reverse string s in place */


#include <stdio.h>


void reverse(char s[])
{
    int c, i, j;

    for(i=0, j=strlen(s)-1; i<j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

main()
{
  int c;
  char s[1024];

  puts("pls input a line\n");

  int i = 0;
  while((c = getchar()) != EOF && c != '\n'){
      s[i++] = c;
  //    printf("%c",c);
  }
  s[i] = '\0';

  reverse(s);

  puts(s);


}
