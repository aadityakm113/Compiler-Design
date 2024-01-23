%{
#include <stdio.h>

int keywordCount = 0;
int identifierCount = 0;
%}

%option noyywrap

%%
"if"|"else"|"while"|"for"|"int"|"float"|"char"|"double"|"return" {
    printf("Keyword: %s\n", yytext);
    keywordCount++;
}
[a-zA-Z_][a-zA-Z0-9_]* {
    printf("Identifier: %s\n", yytext);
    identifierCount++;
}
[ \t\n]  ; // Ignore whitespaces and tabs
.|\n ; // Ignore any other characters

%%

int main() {
    printf("Enter a string:\n");
    
    yylex();
    printf("Number of Keywords: %d\n", keywordCount);
    printf("Number of Identifiers: %d\n", identifierCount);
    
    return 1;
}
