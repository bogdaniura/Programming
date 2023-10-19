%option main
alphabetic [A-Za-z]
digit [0-9]
alphanumeric ({alphabetic}|{digit})
%%
{alphabetic}{alphanumeric}* printf("Pascal variable");
\, printf("Comma");
\{ printf("Left brace");
\:\= printf("Assignment");
%%