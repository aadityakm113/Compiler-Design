// YACC Program to evaluate arithmetic expression
%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex();
    void yyerror(const char *);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%left '%'
%left '(' ')'

%%

s: expr { printf("\nResult: %d\n", $1); return 0; }

expr: expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { $$ = $1 / $3; }
    | expr '%' expr { $$ = $1 % $3; }
    | '-' NUMBER     { $$ = -$2; }
    | '(' expr ')'  { $$ = $2; }
    | NUMBER         { $$ = $1; }
    ;

%%

int main() {
    printf("Enter the expression: \n");
    yyparse();
    printf("\nExpression is valid\n");
    return 0;
}

void yyerror(const char *s) {
    printf("\nExpression is invalid\n");
    exit(1);
}