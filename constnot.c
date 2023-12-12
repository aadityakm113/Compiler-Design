//read a string and tell whether it is a constant or not
#include <stdio.h>
#include <ctype.h>

int main(){
    char str[20];
    int state,i=1;
    printf("Enter your string ");
    scanf("%s",str);
    if (isdigit(str[0]))
        state=1;
    else
        state=5;
    while(str[i]!='\0' && state!=5)
    {
        switch (state)
        {
        case 1: if(isdigit(str[i]))
                state=1;
            else if (str[i]=='.')
                state=3;
            else if (str[i]=='e')
                state=2;
            else
                state=5;
            break;

        case 2:if(isdigit(str[i]))
                state=2;
            else   
                state=5; 
            break;
        case 3:if(isdigit(str[i]))
                state=4;
            else
                state=5;
            break;
        case 4:if(isdigit(str[i]))
                state=4;
            else
                state=5;
            break;

        }
        i++;
        if (state==4)
            break;
    }
    printf("%s ",str);
    if(state==1)
        printf("is a Constant");
    else if (state==2)
        printf("is a constant");
    else if(state==4)
        printf("is a Constant");
    else
        printf("is not a Constant");
}
