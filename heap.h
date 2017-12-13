#ifndef _heap
#define _heap
#include "graph.h"

class maxHeap{
    public:
    vector<int> heapPos;
    
    vector<double> heapData;
    int lastPos;
    map<int,int> mapHeap;
    maxHeap(int numV): lastPos(0), heapPos(numV+1), heapData(numV+1) {};
    void insertHeap(int, double);
    void deleteHeap(int);
    void heapify(int );
    int parent(int);
    int leftChild(int);
    int rightChild(int);
    int extractMax();
    bool isEmpty();
    void swap(int i, int j);
    double maxVal();
    void printHeap();
};
#endif