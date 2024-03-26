%{
#include <stdio.h>
%}

%token NUMBER ID
%left '+' '-'
%left '*' '/'

%%
expr: expr '+' expr
 |expr '*' expr
 |expr '-' expr
 |expr '/' expr
 |'-'NUMBER
 |'-'ID
 |'(' expr ')'
 |NUMBER
 |ID
 ;
%%

main()
{
printf("Enter the epression");
yyparse();
printf("\nExpression is valid");
exit(0);
}

int yyerror(char *s)
{
printf("\n Expression is invalid");
exit(0);
}