
%{
int keywordCount = 0;
int identifierCount = 0;
int constantCount = 0;
int opCount = 0;
int charCount = 0;
int stringCount = 0;
char input_file[20];
%}

%%

\"([^\"\\]|\\.)*\"                                                 { stringCount++; printf("String: %s\n", yytext); }
"if"|"else"|"while"|"for"|"int"|"float"|"char"|"double"|"return"   { keywordCount++;}
[a-zA-Z_][a-zA-Z0-9_]*                                             { identifierCount++;}
[+-]?[0-9]+(.[0-9]+)?(E[+-]?[0-9]+)?                               { constantCount++; }
[!@#$^&*(){}.,;\[\]]*                                              { charCount++; }
"+"|"_"|"="|"<="|">="|"*"|"%"|">"|"<"|"<>"                         { opCount++; }
[ \t\n]  ; // Ignore whitespaces and tabs
.|\n ; // Ignore any other characters

%%
int yywrap()
{
    return 1;
}
int main() {
    printf("Enter input file name: ");
    scanf("%s", input_file);
    yyin=fopen(input_file,"r");
    yylex();
    fclose(yyin);

    printf("Number of Keywords: %d\n", keywordCount);
    printf("Number of Identifiers: %d\n", identifierCount);
    printf("Number of Constants: %d\n", constantCount);
    printf("Number of Special Characters: %d\n", charCount);
    printf("Number of Operators: %d\n", opCount);
    printf("Number of String Constants: %d\n", stringCount);

   
    return 1;
}

