%{
#include <stdio.h>
#include <stdlib.h>

char temp = 't';
char genCode(char, char, char);
%}

%union {
    char dval;
}

%token <dval> NUM
%type <dval> E

%left '+' '-'
%left '*' '/'  

%%

Statement: E { printf("\n r=%c\n", $1); }

E: E '+' E { $$ = genCode($1, '+', $3); }
 | E '-' E { $$ = genCode($1, '-', $3); }
 | E '*' E { $$ = genCode($1, '*', $3); }
 | E '/' E { $$ = genCode($1, '/', $3); }
 | '(' E ')' { $$ = $2; }
 | NUM { $$ = $1; }
 ;

%%

void yyerror(char* str) {
    printf("\n%s\n", str);  
}

char genCode(char first, char op, char second) {
    printf("\n%c=%c %c %c\n", temp, first, op, second); 
    return temp++;
}

int main() { 
    printf("Enter arithmetic expression: ");
    yyparse();
    return 0;
}
