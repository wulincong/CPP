CC = g++ -I ../绪论

all: Scanf_main.exe 

Scanf_main.exe:../绪论/Scanf.o Scanf_main.o
	$(CC) Scanf_main.o ../绪论/Scanf.o -o Scanf_main.exe 

Scanf_main.o:Scanf_main.cpp
	$(CC) Scanf_main.cpp -c -o Scanf_main.o

