#ifndef ALGO_H
#define ALGO_H

#include "graph.h"
#include "heap.h"
#include <time.h>
#include <float.h>
#include <queue>
#include <climits>


double dijkstraWithoutHeap(graph* G, int source, int dest);
double dijkstraWithHeap(graph* G, int source, int dest);
double kruskal(graph* G, int source, int dest);
void printPath(const vector<int>& DAD, int d);
double BFS (graph* G, int s, int d);
class setKruskal {
  public:
  vector<int> parent;
  vector<int> rank;
  
  void makeSet(int);
  int findRoot(int);
  void unionSet(int, int); 
  
  setKruskal(int n): parent(n+1,0), rank (n+1,0) {};
}; 

#endif