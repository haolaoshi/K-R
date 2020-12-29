/*
 * write a program to print a histogram of the length of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challengin.
 *
 * Usage:
 *      ./a
 *      (in put some words, then Ctrl+D for EOF)
 *
 */


#include <stdio.h>


#define MAX_WORD    25 
#define IN_WORD     1
#define OUT_WORD    0
lookup(int** arr){
  int i = 0; 
  for(;i < MAX_WORD; i++) printf("%d,",arr[i]);
}
main()
{
    int nc = 0;//char counting
    int state = OUT_WORD;//word soldiers
    int word_counts[MAX_WORD];//words lenth counts
    int max = 0;//maxlen
    int i,c,arrlen;

    for( i = 0; i < MAX_WORD; i++) word_counts[i] = 0;
    putchar(13);

    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            if(state == IN_WORD) {
                word_counts[nc]++;
                //printf(" pos : %d, val : %d \n", nc, word_counts[nc]);
            } 
            nc = 0;
            state = OUT_WORD;
        }else {
            state = IN_WORD;
            nc++;
        }
        //printf("state : %d, nc : %d,  c : %d \n",state,nc,c);
    }

    printf("------------------------\n");
    //for(i = 0; i < MAX_WORD; i++) printf("%d,",word_counts[i]);
    putchar(10);

    for(i = MAX_WORD; i >= 0 ; i-- ) 
        if(word_counts[i] > max) max = word_counts[i];

    //printf("max = %d \n",max);
    
    for(i = MAX_WORD; i>= 0; i--)
        if(word_counts[i] > 0) break;
    
    arrlen = i; 

    for(i = max; i > 0; i--){
      printf("%6d\t",i);
      int j = 0;
      for(; j < MAX_WORD; j++) 
        if(word_counts[j] >= i) printf("[*]");
        else printf("   ");
      printf("\n");
    }
    printf("TITLE: ");
    for(i = 0; i <=  arrlen ; i++ ) 
        //if(word_counts[i] > 0) printf("%3d",i); 
        //else printf("...");
        printf("%3d",i);

    putchar(10);
}
