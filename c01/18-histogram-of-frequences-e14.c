/*
 * Write a program to print a histogram of the frequencies of different characters in its input.
 *
 *
 */

#include <stdio.h>


main()
{
char words[27];
words[26] = '\0';
int a;
for(a = 0 ; a < 26;a++) words[a] = 0;
int sum = 0;
while((a = getchar()) != EOF){
	if(a > 'z' || a < 'A') continue;
	if(a>'Z') a = a - 32;
	words[a - 65]++;
	sum++;
}


int i = 0;
for(i;i<26;i++) printf("---");
//for(i;i<26;i++) printf("%d,",words[i]); 

printf("\n");
int max = 0;
for(i = 0 ; i < 26; i++) if(words[i]>0) {words[i] = words[i] * 100 / sum;printf("%3d",words[i]);}

printf("\n");
for(i=0;i<26;i++) printf("---");
printf("\n");
i = 0;
while( i < 26) if(words[i] >= max) max = words[i++]; else i++;

while(max > 0){
for(i = 0 ; i < 26; i++){
	if(words[i]>0 && words[i] >=max) printf("[*]");
	else printf("   ");

}
max--;
printf("\n");
}
for(i = 'a' ; i<='z'; i++) printf("%3c",i);
printf("\n");

}
