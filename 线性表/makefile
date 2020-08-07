all: Union

Union: Union.cpp SqList.o
	g++ Union.cpp SqList.o -o Union -I ../绪论/
SqList.o: SqList.cpp
	gcc SqList.cpp -I ../绪论/ -c -o SqList.o
clean : 
	rm Union.exe SqList.o