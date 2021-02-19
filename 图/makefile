INCLUDE = 

CC = g++ 

main: main.cpp MGraph.o
	$(CC) main.cpp MGraph.o $(INCLUDE) -o main

MGraph.o: MGraph.cpp
	$(CC) -Wall -c MGraph.cpp -o MGraph.o $(INCLUDE)

clean: 
	rm MGraph.o
