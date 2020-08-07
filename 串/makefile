target = SequenceString.o SequenceString_Main.exe KMP.o 
CC = gcc -I ../绪论/ 
all: $(target)

SequenceString_Main.exe: SequenceString_Main.cpp SequenceString.o KMP.o
	$(CC) SequenceString_Main.cpp SequenceString.o KMP.o -o SequenceString_Main.exe

KMP.o: KMP.cpp 
	$(CC) KMP.cpp -c -o KMP.o

SequenceString.o: SequenceString.cpp
	$(CC) SequenceString.cpp -c -o SequenceString.o 

clean:
	rm -f $(target)
