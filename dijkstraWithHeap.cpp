#include "algoheader.h"



double dijkstraWithHeap(graph* G, int source, int dest){
    
    vector<int> STATUS(G->numberOfVertices + 1, 0); //Initialized to UNSEEN
    vector<int> DAD(G->numberOfVertices + 1, 0); 
    vector<double> BANDWIDTH(G->numberOfVertices + 1); 
    STATUS[source] = 1; //IN-TREE
    BANDWIDTH[source] = DBL_MAX;

    vertex* s = G->findVertex[source]; //get hold of the source vertex
    
    int n = s->adj.size(); //size of adjacency
    
    maxHeap H(G->numberOfVertices); //it expects the number of vertices
    
    /* Initialize the neighbours of source */
    for(int i = 0; i<n; i++){
        vertex* neighbour = s->adj[i].second;
        STATUS[neighbour->vNum] = 2; //FRINGE
        DAD[neighbour->vNum] = source; 
        BANDWIDTH[neighbour->vNum] = s->adj[i].first; //cost of (source,neighbour) edge 
        
        /* Insert all these fringes in max heap */
        H.insertHeap(neighbour->vNum, BANDWIDTH[neighbour->vNum]);
    }
    
    while(STATUS[dest] != 1){ //till destination is not IN-TREE
        /* Pick a fringe with the largest bandwidth */
        int v = H.extractMax(); 
        
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
                
                /* insert the new fringe */
                H.insertHeap(vNeighbour->vNum, BANDWIDTH[vNeighbour->vNum]);
                
            } else if(STATUS[vNeighbour->vNum] == 2 && BANDWIDTH[vNeighbour->vNum] < minB){
                BANDWIDTH[vNeighbour->vNum] = minB;
                DAD[vNeighbour->vNum] = v; 
                
                
                H.deleteHeap(H.mapHeap[vNeighbour->vNum]);
                H.insertHeap(vNeighbour->vNum, BANDWIDTH[vNeighbour->vNum]);
            }  
        }

        
    }
    printPath(DAD, dest);
    return BANDWIDTH[dest];
}
