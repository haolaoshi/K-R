/*
 *
 *
 * Exercise 7-6:
 * Write a program to compare two files,printing the first line where they diff
 */


#include <stdio.h>
#define MAXLEN  255

main(int argc, char *argv[])
{
    char *prog = argv[0];
    if(argc <3 ){
        fprintf(stderr,"Usage %s  file1  file2 \n",prog);
        exit(1);
    }

    FILE *f1,*f2;
    char line1[MAXLEN];
    char line2[MAXLEN];

    f1 = fopen(argv[1],"r");
    f2 = fopen(argv[2],"r");

    if(f1 == NULL || f2 == NULL){
        fprintf(stderr,"Cannot open file %s or %S \n",argv[1],argv[2]);
        exit(2);
    }else{
        while(fgets(line1,MAXLEN,f1) != NULL)
            if(fgets(line2,MAXLEN,f2) != NULL && strcmp(line1,line2) != 0){
                fputs(line1,stderr);
                fputs(line2,stderr);
                exit(1);
            }
        fprintf(stderr,"The Same about %s  vs %s.\n",argv[1],argv[2]);
    }
    exit(0);
}
