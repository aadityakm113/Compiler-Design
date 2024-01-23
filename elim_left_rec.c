//Write a C Program to Eliminate Left Recursion
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char prod[20],alpha[20],beta[20];
    int i,j;
    printf("Enter the production \n");
    scanf("%s",prod);

    if(prod[0]==prod[3])
    {
        printf("The production is left recursive.\n");
        i=4;
        j=0;

        while(prod[i]!='|')
        {
            alpha[j++]=prod[i++];
        }

        alpha[j]='\0';
        i=i+1;
        j=0;
        while(prod[i]!='\0')
        {
            beta[j++]=prod[i++];
        }

        beta[j]='\0';
        printf("Production after removing left recursion: \n");
        printf("%c->%s%c' \n",prod[0],beta,prod[0]);
        printf("%c'->%s%c'|E",prod[0],alpha,prod[0]);

    }
    else
        printf("The production is not left recursive");
    return 0;
}