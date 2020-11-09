flex lexical.l
Bison -d syntax.y
gcc lex.yy.c syntax.tab.c  -lfl -ly -o compil.exe
