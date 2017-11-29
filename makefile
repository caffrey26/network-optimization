main: main.o graph.o dijkstra1.o dijkstraWithHeap.o heap.o algoheader.o kruskal.o
	g++ -std=c++11 main.o graph.o dijkstra1.o dijkstraWithHeap.o -o main
	
main.o: main.cpp graph.h algoheader.h heap.h
	g++ -std=c++11 -c main.cpp
	
graph.o: graph.cpp graph.h
	g++ -std=c++11 -c graph.cpp

dijkstra1.o: dijkstra1.cpp algoheader.h graph.h heap.h
	g++ -std=c++11 -c dijkstra1.cpp

dijkstraWithHeap.o: dijkstraWithHeap.cpp algoheader.h graph.h heap.h
	g++ -std=c++11 -c dijkstraWithHeap.cpp

heap.o: heap.cpp heap.h graph.h
	g++ -std=c++11 -c heap.cpp

algoheader.o: algoheader.cpp algoheader.h graph.h heap.h
	g++ -std=c++11 -c algoheader.cpp

kruskal.o: kruskal.cpp algoheader.h graph.h heap.h
	g++ -std=c++11 -c kruskal.cpp
	
debug: main.o graph.o dijkstra1_debug.o
	g++ -std=c++11 -g main.o graph.o dijkstra1.o -o main
	
dijkstra1_debug.o: dijkstra1.cpp algoheader.h
	g++ -std=c++11 -g -c dijkstra1.cpp

clean:
	\rm *.o *~ a.out