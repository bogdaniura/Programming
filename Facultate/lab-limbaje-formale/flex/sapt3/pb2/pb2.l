%option noyywrap

%{
int count=0;
%}
DIGIT [0-9]
ALPHA [a-zA-Z]
%%
({ALPHA}|{DIGIT})*com {count++;}
%%
int main()
{
yylex();
printf("Count= %d\n",count);
return 0;
}