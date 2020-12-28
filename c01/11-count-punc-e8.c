#include <stdio.h>


main()
{

  int blanks,tabs,newlines;
  int c = 0;
  for(blanks =0,tabs =0,newlines =0; c != EOF; c = getchar())
    if(c == ' '|| c== 32) ++blanks; 
    else if (c == '\t') ++tabs;
    else if (c == '\n') ++newlines;

  printf("BLANKS:%d\tTABS:%d\tNEWLINES:%d\n",blanks,tabs,newlines);
}
