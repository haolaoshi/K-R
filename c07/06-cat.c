/*
 *
 * Example 
 *
 */

#include <stdio.h>



main(int argc,char *argv[])
{
    FILE    *fp;
    void filecopy(FILE  *,FILE  *);
    if(argc == 1)
        filecopy(stdin,stdout);
    else
        while(--argc > 0)
           if((fp = fopen(*++argv,"r")) == NULL){
                printf("#1");
                printf("cat : can't open %s\n",*argv);
                return 1;
            }else{
                printf("#2");
                filecopy(fp, stdout);
                fclose(fp);
            } 
    return 0;

}

void filecopy(FILE  *fp,FILE    *op)
{
    printf("#3");
    int c;
    while((c = getc(fp)) != EOF)
        putc(c,op);
}
