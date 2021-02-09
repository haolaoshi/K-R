/*
 *
 *
 * 5.12 Complicated Declarations.
 *
 *
 */

void dirdcl(void)
{
    int type;
    if(tokentype == '('){
        dcl();
        if(tokentype != ')')
            printf("error, missing ) \n");
    else if(tokentype == NAME)
        strcpy(name,token);
    else
        printf("Error: expected name or (dcl) \n");

    while((type = gettoken()) == PARENS || type ==BRACKETS)
        if(type == PARENS)
            strcat(out," founction returning");
        else{
            strcat(out," array");
            strcat(out,token);
            strcat(out,"  of");

        }

}

void dcl(void)
{

    int ns;
    for(ns =0; gottoken() == '*'; )
        ns++;
    dirdcl();

    while(ns-- > 0)
        strcat(out,"  pointer to");


}

main()
{
    while(gettoken() != EOF){
        strcpy(datatype,token);
        out[0] = '\0';
        dcl();
        if(tokentype != '\n')
            printf("syntax error\n");
        printf("%s : %s %s \n",name,out,datatype);


    }

    return 0;
}

