%option noyywrap


%{
int lnno=0,wordno=0,charno=0;
%}
word [.* .*\t]
eol [\n]
%%
{word} {wordno++; charno+=yyleng;}
{eol} {charno++;lnno++;wordno++;}
. {charno++;}
%%
int main()
{
yylex();
printf("Line number= %d\n",lnno);
printf("Word number= %d\n",wordno);
printf("Character number= %d\n",charno);
return 0;
}