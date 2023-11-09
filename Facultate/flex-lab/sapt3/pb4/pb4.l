%option noyywrap

%{
int count=0;
%}
%%
[aeiouAEIOU] {count++;ECHO;}
%%
int main()
{
yylex();
printf("\nNumber of vowels= %d\n",count);
return 0;
}