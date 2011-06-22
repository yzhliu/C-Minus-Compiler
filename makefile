parser: lex.yy.c y.tab.c y.tab.h parser.c hash.h hash.c var.h command.h command.c
	gcc -o parser lex.yy.c y.tab.c parser.c hash.c command.c -ll

lex:
	lex c-grammar.lex

yacc:
	yacc -d c-grammar.y
