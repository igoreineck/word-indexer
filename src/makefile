all: compile_files

compile_files: LDE.o indexer.o main.o
	gcc -fno-stack-protector -Wall -o app LDE.o indexer.o main.o 

LDE.o: libs/LDE.c
	gcc -c libs/LDE.c

indexer.o: libs/indexer.c
	gcc -c libs/indexer.c

main.o: main.c
	gcc -c main.c

clear:
	rm -f .o