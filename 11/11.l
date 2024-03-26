%{
#include <stdio.h>
#include "11.tab.h"
%}

%%
[0-9]+      { yylval.dval = atoi(yytext); return NUM; }
\n          { return 0; }
.           { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
