#include <stdio.h>

#define  WHATS  EOF

main()
{

  int c,d;
  d = 0; 
  char h;
 // printf("[%d],%d \n",d,WHATS);
  h = getchar();
  while(c != EOF ){
  //  if(c =='\n' || c== '\r') printf("%c,size of c= %d\n",c,sizeof(c));
    d++;
    //printf("[%d],%c != EOF ? %d\n",d,c,(c != EOF));
    printf("[%d],%c != EOF ? %d\n",d,h,(h != EOF));
    h = getchar();
  }
}
