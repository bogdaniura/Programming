%option noyywrap

%%
^m.*\n    { printf("%s", yytext); }
. ;
%%

int main() {
    yylex();
    return 0;
}
