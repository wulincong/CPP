CC = gcc -I ../绪论 

all:SeqBinaryTree_main.exe SeqBinaryTree.o

SeqBinaryTree_main.exe: SeqBinaryTree_main.cpp SeqBinaryTree.o ../绪论/Scanf.o 
	$(CC) SeqBinaryTree_main.cpp SeqBinaryTree.o ../绪论/Scanf.o -o SeqBinaryTree_main.exe

SeqBinaryTree.o: SeqBinaryTree.cpp
	$(CC) SeqBinaryTree.cpp -c -o SeqBinaryTree.o 
