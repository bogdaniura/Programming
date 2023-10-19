%option main
digit [0-9]
%%
[+-]?{digit}*(\.)?{digit}+ printf("FLOAT");
%%