main: main.o graph.o dijkstra1.o
	g++ -std=c++11 main.o graph.o dijkstra1.o -o main

debug: main.o graph.o dijkstra1_debug.o
	g++ -std=c++11 -g main.o graph.o dijkstra1.o -o main
main.o: main.cpp graph.h algoheader.h
	g++ -std=c++11 -c main.cpp
	
graph.o: graph.cpp graph.h
	g++ -std=c++11 -c graph.cpp
	
dijkstra1_debug.o: dijkstra1.cpp algoheader.h
	g++ -std=c++11 -g -c dijkstra1.cpp

dijkstra1.o: dijkstra1.cpp algoheader.h
	g++ -std=c++11 -c dijkstra1.cpp