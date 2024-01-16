%option noyywrap
alpha [AZaz]
digit [09]
%%
[\t \n] ;
int|float|void|char return TYPE;
return return RETURN;
{digit}+ return NUM;
{alpha}({alpha}|{digit})* return ID;
. return yytext[0];
%%