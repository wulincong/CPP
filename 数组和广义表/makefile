cc = gcc -I ../绪论/Status.h 

all: SequenceArray.o SequenceArray_Main.exe 
SequenceArray_Main.exe: SequenceArray.o SequenceArray_Main.cpp 
	$(CC) SequenceArray_Main.cpp SequenceArray.o -o SequenceArray_Main.exe

SequenceArray.o : SequenceArray.cpp 
	$(CC) SequenceArray.cpp -c -o SequenceArray.o

TripleSparseMatrix.o : TripleSparseMatrix.cpp 
	$(CC) TripleSparseMatrix.cpp -c -o TripleSparseMatrix.o