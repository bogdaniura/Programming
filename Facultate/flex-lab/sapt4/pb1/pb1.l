%option noyywrap

%%
"username"   { printf("Username: %s\n", getlogin()); }
%%

int main() {
    yylex();
    return 0;
}
