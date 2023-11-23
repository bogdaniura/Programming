%option noyywrap

%{
int count=0;
%}
%%
.*com\n {count++;ECHO;}
. ;
%%
int main()
{
yylex();
printf("\nCount= %d\n",count);
return 0;
}