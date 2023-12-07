//2.implement transition diagram for identifying an integer constant or real constant
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
        state=4;
    while(str[i]!='\0' && state!=4)
    {
        switch (state)
        {
        case 1: if(isdigit(str[i]))
                state=1;
            else if (str[i]=='.')
                state=2;
            else
                state=4;
            break;

        case 2:if(isdigit(str[i]))
                state=3;
            else   
                state=4; 
            break;
        case 3:if(isdigit(str[i]))
                state=3;
            else
                state=4;
            break;

        }
        i++;
        if (state==4)
            break;
    }
    printf("%s ",str);
    if(state==1)
        printf("is an Integer Constant");
    else if (state==3)
        printf("is a Real constant");
    else
        printf("is Invalid");
}
