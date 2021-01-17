lexer: ciraffe_lexer.c libs/structures.c
	gcc -o lexer ciraffe_lexer.c libs/structures.c -I.
check: ciraffe_lexer.c libs/structures.c
	gcc -o lexercheck ciraffe_lexer.c libs/structures -I
