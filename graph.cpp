#include "graph.h"

graph::~graph(){
    //destroy space taken by vmap
    for( map<int, vertex*>::iterator it = findVertex.begin() ; it != findVertex.end() ; ++it ){
        //it->second has allocated space for vertex*
        delete it->second;
    }
    for (int i = 0; i<edges.size(); i++){
        delete edges[i];
    }
    
}
bool graph::vertexExists(int v){
    vmap::iterator itr = findVertex.find(v);
    if (itr == findVertex.end()){
        return 0;
    }else return 1;
} 

bool graph::addvertex(int name)
{
    if (!vertexExists(name))
    {
        vertex *v;
        v = new vertex(name);
        findVertex[name] = v;
        
        /* increase the number of vertices in the graph by 1*/
        numberOfVertices++;
        
        return 1;
    }
    return 0;
}


bool graph::addedge(int v1, int  v2, double cost)
{
    if (vertexExists(v1) && vertexExists(v2)){
        //add the edge between them
        vertex *f = (findVertex.find(v1)->second); //get hold of the adjacency list
        vertex *t = (findVertex.find(v2)->second); 
        pair<double, vertex *> edgeT = make_pair(cost, t);
        pair<double, vertex *> edgeF = make_pair(cost, f);
        
        //add t to adjacency list of f
        f->adj.push_back(edgeT);
        t->adj.push_back(edgeF);
        
        /* increase the degree for the two vertices by 1 */
        f->degree++;
        t->degree++;
        
        /* increase the number of edges in the graph by 1 */
        numberOfEdges++;
        
        edge* e = new edge(f,t,numberOfEdges, cost);
        edges.push_back(e);
        
        return 1;
    } 
    else return 0;
}
