#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0

main()
{
  int c;
  int state = OUT_WORD;

  while((c = getchar()) != EOF){
    if(c == ' ' || c == '\t' || c == '\n'){ 
        if(state == IN_WORD) putchar('\n');
        state = OUT_WORD;
    }else {
        state = IN_WORD;
        putchar(c);
    }
    

  }

}
