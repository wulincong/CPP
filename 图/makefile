INCLUDE = -I../绪论

CC = g++ -v

main: main.cpp MGraph.o
	$(CC) main.cpp MGraph.o $(INCLUDE) -o main

MGraph.o: MGraph.cpp
	$(CC) -Wall -c MGraph.cpp -o MGraph.o $(INCLUDE)

clean: 
	rm MGraph.o
