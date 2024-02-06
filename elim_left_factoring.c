#include <stdio.h>
#include<string.h>
#include<stdlib.h>  

void main(){
    char grammer[20],part1[20],part2[20],modifiedGrammer[20],tempGrammer[20],newGrammer[20];
    int i,j=0,k=0,l=0,pos;
    printf("Enter Production: ");
    scanf("%s",grammer);
    for(i=0;grammer[i]='|';i++,j++){
        part1[j]=grammer[i];
    }
    part1[j]='\0';
    for(j=++i,i=0;grammer[j]!='\0';j++,i++){
        part2[i]=grammer[j];
    }
    part2[i]='\0';
    for ( i = 0; i < strlen(part1)||i<strlen(part2); i++)
    {
        if (part1[i]==part2[i]){
            modifiedGrammer[k]=part1[i];
            k++;
            pos=i+1;
        }
    }
    for ( i = pos,j=0; part1[i] !='\0'; i++,j++)
    {
        newGrammer[j++]='|';
        for(i=pos;part2[i]!='\0';i++,j++){
            newGrammer[j]=part2[i];
        }
        modifiedGrammer[k]='X';
        modifiedGrammer[++k]='\0' ;
        newGrammer[j]="\0";
        printf("\n A->%s" ,modifiedGrammer) ;
        printf("\n X->%s\n", newGrammer) ;
    }
    
    

}