parser: lex.yy.c y.tab.c y.tab.h parser.c hash.h hash.c var.h
	gcc -o parser lex.yy.c y.tab.c parser.c hash.c -ll

lex:
	lex c-grammar.lex

yacc:
	yacc -d c-grammar.y
