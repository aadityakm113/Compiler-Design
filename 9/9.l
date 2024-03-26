%{
#include "expr.tab.h"
#include <stdlib.h>
extern int yylval; // Corrected the declaration of yylval
%}

%%
[0-9]+      { yylval = atoi(yytext); return NUMBER; } // Match numbers and return the NUMBER token
[a-zA-Z]+   { return ID; } // Match letters and return the ID token
[\t]+       ; // Ignore tabs
\n          { return 0; } // Return 0 for end of input
.           { return yytext[0]; } // Return any other character
%%

int yywrap() {
    return 1;
}
