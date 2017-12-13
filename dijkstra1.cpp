#include "algoheader.h"


/* Function takes in a graph, and two vertices: source, and destination. It calculates the maximum bandwidth path, and returns the value of the maximum bandwidth path */

double dijkstraWithoutHeap(graph* G, int source, int dest){
    vector<int> STATUS(G->numberOfVertices + 1, 0); //Initialized to UNSEEN
    vector<int> DAD(G->numberOfVertices + 1, 0); 
    vector<double> BANDWIDTH(G->numberOfVertices + 1); 
    STATUS[source] = 1; //IN-TREE
    BANDWIDTH[source] = DBL_MAX; //bandwidth infinite
    
    vertex* s = G->findVertex[source]; //source vertex
    
    int n = s->adj.size();
    
    /* Initialize the neighbours of source */
    for(int i = 0; i<n; i++){
        vertex* neighbour = s->adj[i].second;
        STATUS[neighbour->vNum] = 2; //FRINGE
        DAD[neighbour->vNum] = source; 
        BANDWIDTH[neighbour->vNum] = s->adj[i].first; //cost of (source,neighbour) edge 
    }
    
    while(STATUS[dest] != 1){ //till destination is not IN-TREE
        /* Pick a fringe with the largest bandwidth */
        int m = -DBL_MAX;
        int v = 0;
        for(int i = 1; i<= G->numberOfVertices ; i++){
            
            if(STATUS[i] == 2  && m < BANDWIDTH[i]){
                m = BANDWIDTH[i];
                v = i;
            }
        }
        
        /* v has the maximum bandwidth */
        vertex* vFringe = G->findVertex[v];
        STATUS[v] = 1;
        
        /* for each edge v,w */
        int vSize = vFringe->adj.size();
    
        for(int i = 0; i<vSize; i++){
            vertex* vNeighbour = vFringe->adj[i].second;
            
            double minB = (vFringe->adj[i].first < BANDWIDTH[v])? vFringe->adj[i].first : BANDWIDTH[v];  
            
            if (STATUS[vNeighbour->vNum] == 0) {
                STATUS[vNeighbour->vNum] = 2; //FRINGE
                DAD[vNeighbour->vNum] = v; 
                BANDWIDTH[vNeighbour->vNum] = minB;
            } else if(STATUS[vNeighbour->vNum] == 2 && BANDWIDTH[vNeighbour->vNum] < minB){
                BANDWIDTH[vNeighbour->vNum] = minB;
                DAD[vNeighbour->vNum] = v; 
            }  
        }

        
    }
    printPath(DAD, dest);
    return BANDWIDTH[dest];
}