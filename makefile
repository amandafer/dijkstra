all:Grafos Tp1
	gcc -g main.c graph.o tp1.o -o tp1

Grafos:
	gcc -g -c graph.c

Tp1:
	gcc -g -c tp1.c
