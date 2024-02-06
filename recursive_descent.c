// Implementation of Recursive descent parser for the following grammar
// E->TE’
// E’->+TE’/$
// T->FT’
// T’->*FT’/$
// F->(E)/a
#include <stdio.h>
#include<string.h>
#include<stdlib.h>  
int i=0,t=1;
char str[20];
void E();
void EPrime();
void T();
void TPrime();
void F();
void error();
void main()
{
    printf("The given grammar is:\n");
    printf(" \n E->TE'");
    printf(" \n E'->+TE'/$");
    printf(" \n T->FT'");
    printf(" \n T'->*FT'/$'");
    printf(" \n F->(E)/a");
    printf(" \n enter the string to be parsed");
    scanf('%s',str);
    E();
    if(t!=1||str[i]!='\0'){
        printf("\n The given String is not accepted");
    }
    else{
        printf("\n The given String is  accepted");
    }
}

void E(){
    T();
    EPrime();
}

void EPrime(){
    if(str[i]=='+'){
        i++;
        T();
        EPrime();
    }
    else
    return;
}
void T(){
    F();
    TPrime();
}
void TPrime(){
    if(str[i]=='*'){
        i++;
        F();
        TPrime();
    }
    else
    return;
}

void F(){
    if(str[i]=='a')
        i++;
    else if(str[i]=='('){
        i++;
        E();
        if (str[i]==')')
            i++;
        
    }
    else
    error();
}
void error(){
    t=-1;
}
