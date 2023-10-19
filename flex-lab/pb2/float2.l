%option main
digit [0-9]
sign [+-]
float val;
%%
{sign}?{digit}*(\.)?{digit}+ {sscanf(yytext, "%f", &val);
printf(">%f<", val);}