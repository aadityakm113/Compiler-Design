%{
#include<stdio.h>
#include<stdlib.h>
%}

%token NUMBER ID 
%left '+' '-' 
%left '*' '/'
%%

expr: expr '+' expr  { printf("(%d + %d)", $1, $3); }
	| expr '-' expr  { printf("(%d - %d)", $1, $3); }
	| expr '*' expr  { printf("(%d * %d)", $1, $3); }
	| expr '/' expr  { printf("(%d / %d)", $1, $3); }
	| '-' NUMBER     { printf("(-%d)", $2); }
	| '-' ID         { printf("(-%s)", yytext); }
	| '(' expr ')'   { printf("(%d)", $2); }
	| NUMBER         { printf("%d", $1); }
	| ID             { printf("%s", yytext); }
	;

%%

int main()
{
    printf("Enter the expression:\n");
    yyparse();
    printf("\nExpression is valid\n");
    return 0;
}

int yyerror(char *s)
{
    printf("\nExpression is invalid\n");
    exit(0);
}
