/*
 *
 * Exercise 3-6.
 *
 *          Write a version of itoa that accepts three arguments instead of two.
 *          The third argument is a minimum field width;
 *          the converted number must be padded with blanks on the left if necessary to make it widt enough.
 *
 *
 */

void reverse(char s[])
{

    int len = strlen(s) - 1;
    int i;
    char c;
    for(i =0; i <= (len/2); i++){
       c = s[len - i]; 
        s[len-i] = s[i];
        s[i] = c;
    }
}

void itoa(int n,char s[], int width)
{
    char c;
    int len = 0;
    int i =0;
    int sign = n;
    if(n < 0) n = -n;

    do{
        s[i++] = n % 10 + '0';
    }while((n /= 10) > 0);

    if(sign <0) s[i++] = '-';

    while(i < width) s[i++] = '_'; 
    s[i] = '\0';
    reverse(s);
}

main()
{
    char s[100];
    itoa(12345,s,10);
    printf("%s\n",s);
}
