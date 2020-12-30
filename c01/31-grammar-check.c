/*
 *
 * Write a program to check a C program for fudimentary syntax errors;
 * like unbalanced parentheses,brackets and braces.
 * Dont's forget about quotes,both single and double,
 * escape sequences,and comments.
 * (This program is hard if you do it in full generality)
 */

/*
 *  [],  (),{},"",'', ;,  # , // , 
 *
 *
 */


#include <stdio.h>

#define MAXLEN  1000

#define DEBUG   0 

char leftPathent[] =  {'[','(','{','"','\'',';','#','\/' ,']',')','}'};
char rightPathent[] = {']',')','}','"','\'',';','\n','\/'};
int existSymbol(char[],int len);

main()
{

//printf("%s\n",leftPathent);
//printf("%s\n",rightPathent);
//read a line ,if enclose one of symbol in left , then  find another in right 
//forbiden when meet the '\n';
//


int len ,pos;
char left,right;
char aline[MAXLEN];
int errors = 0;

    while((len = getaline(aline)) > 0) {
        errors = existSymbol(aline,len);//what symbol, and pos 
        if(errors == 1){
            printf(" ERRORS in line %s \n",aline);
            break;
        }else{
            //printf("    checked!");

        }
    }

}

int getaline(char aline[])
{

    int c,len;
    len  = 0;

    while((c = getchar()) != EOF && c != '\n'){
        aline[len] = c;
        len++;
    }
    aline[len] = '\0';
    //printf("get a string %s",aline);
    return len;
}

int existSymbol(char aline[],int len)
{
    int i = 0; 
    int j = 0;
    int left = 0;
    int right = 0;
    int pos = 0; 
//    while(pos < len){
 //       i = pos;
        while(aline[i]){  // int main();
            if ( aline[i] == ' ' ){
                i++;
                continue;
            }
            if(DEBUG)        printf("\n line[%d] = %c \n\t",i,aline[i]);
            if(left == 0)
                for(j= 0 ;j < 11; j++){
                    if(aline[i] == leftPathent[j]){ 
                     if(DEBUG)  printf(",%c",aline[i]);
                      left = 1;
                     if(DEBUG)  printf("\nFound a pathent %c",leftPathent[j]);
                     if(DEBUG)  printf("\nWe need find right pathen %c ",rightPathent[j]);
                        break;
                    }
                    else {
                         if(DEBUG)  printf(",  %d = %c ",j,leftPathent[j]);
                    }
                }
            if(left == 1 && j >= 8) {
                printf("\nEnter a right pathent!  %c ",leftPathent[j]);
                return 1;
            }
            if(left == 1 && right== 0  && aline[i] == rightPathent[j]) {
                 if(DEBUG)   printf("   ---------- found %c \n",aline[i]);
                right = 1;
            } 
            i++;
  /*      }
        if(left == right ){
            pos++;
            left = right = 0;
        }else{
            printf("\n---------i=%d,j=%d,aline[i]=%c",i,j,aline[--i]);
          break; 
        }*/
    }
  //  printf("\nNow %c  , Expect  %c !",aline[i-1], rightPathent[j]);
    if(leftPathent[j] == ';') return 0;
    return (right ==  left ) ? 0 : 1;
}
