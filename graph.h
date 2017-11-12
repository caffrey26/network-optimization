//https://stackoverflow.com/questions/5493474/graph-implementation-c
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct vertex {
    typedef pair<double, vertex*> ve;
    vector<ve> adj; //cost of edge, destination vertex
    int vNum;
    int degree;
    vertex(int s) : vNum(s), degree(0) {};
};

class graph
{
public:
    typedef map<int, vertex *> vmap;
    vmap findVertex;
    int numberOfVertices; 
    int numberOfEdges;
    bool vertexExists(int);
    bool addvertex(int);
    bool  addedge(int, int, double);
    graph(): numberOfVertices(0), numberOfEdges(0) {};
};

#endif
