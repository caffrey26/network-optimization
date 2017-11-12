#include <cstdlib>
#include <ctime>
#include "graph.h"
#include "algoheader.h"

#define EDGE_MAX_WT 10000
/* returns a random number between, and including lowest, and highest. */
int random (int lowest, int highest){
    int range = (highest - lowest)+1;
    int ret = lowest + (int)range*(rand()/(RAND_MAX+1.0));
    if (ret > highest)
        cout<<"gotcha!";
        return ret;
}

graph* generateRandomGraphByDegrePc(int numV, int degPc){
    // cout <<deg<<endl;
    graph* G = new graph;
    for(int i = 1; i<= numV; i++)
        G->addvertex(i);
    
     /* array to check if we are not adding multiple edges */
    typedef pair<int,int> edge;
    map<edge,int> emap;

    // vector<vector<int>> emap(vNum+1);
    // for(int i = 1; i<= numV; i++){
    //     for(int j = 1; j <= numV; j++)
    //         emap[i][j] = -1;
    //  }
    
    srand((unsigned)time(0));
     int weight;
    /* Add deterministic cycle edges to ensure connectivity in the graph */
     /* check if the edge v1,v2 or v2,v1 exists */
    for(int i = 1; i < numV; i++){
            if ( emap.find(make_pair(i,i+1)) == emap.end() ) {
            weight = random (0, EDGE_MAX_WT); //considering integer weights for now
            G->addedge(i,i+1,weight);
            
            emap[make_pair(i,i+1)] = 1;
            emap[make_pair(i+1,i)] = 1;
        }
    }
    //add between the first and the last vertex as well.
    weight = random (0, EDGE_MAX_WT); //considering integer weights for now
    G->addedge(1,numV,weight);
            
    emap[make_pair(1,numV)] = 1;
    emap[make_pair(numV,1)] = 1;
    
    int loopCount = (numV-1)*numV/2;
    // cout<<loopCount<<endl;
    while(loopCount>=0){
        
        /* Generate two random vertices */
        int v1 = random(1,numV);
        // cout<<v1<<endl;
        int v2 = random(1,numV);
        /* check if the edge v1,v2 or v2,v1 exists */
        if ( v1!=v2 && emap.find(make_pair(v1,v2)) == emap.end() ) {
            
            /* Generate a random number between 1, and 100 */
            int dice = random(1,100);
            
            /* Only add the edge, if the dice has a number <= degPc */
            
            if (dice <= degPc){
                weight = random (0, EDGE_MAX_WT); //considering integer weights for now
                G->addedge(v1,v2,weight);
            
                emap[make_pair(v1,v2)] = 1;
                emap[make_pair(v2,v1)] = 1;

            }
        }
        
        loopCount--;
    }
    
    
    
    
    // cout<< (G->findVertex[1])->degree<<endl;
    /* for each vertex we ensure the degree to be equal to deg*/
    // for (int i = 1; i<= numV; i++){
    //     // cout<<(G->findVertex[i])->degree;
    //     while((G->findVertex[i])->degree < deg){
    //         int v1 = random(1,numV);
    //         if ( i != v1 && emap.find(make_pair(i,v1) ) == emap.end() && (G->findVertex[v1])->degree < deg) {
    //             weight = random (0, EDGE_MAX_WT); //considering integer weights for now
    //             G->addedge(i,v1,weight);
            
    //             emap[make_pair(i,v1)] = weight;
    //             emap[make_pair(v1,i)] = weight;
    //         }
            
    //     }
    //     // cout<<" "<<(G->findVertex[i])->degree<<endl;
    // }
    return G;
}
graph* generateRandomGraphByAvgDegree(int numV, int avgD){
    graph* G = new graph;
    
    int numE = avgD*numV/2;
    /* Add MAX_V number of vertices to graph */
    for(int i = 1; i<= numV; i++)
        G->addvertex(i);
    
    /* map to check if we are not adding multiple edges */
    typedef pair<int,int> edge;
    map<edge,int> emap;
    
    /* seed the rand function with the current time, to produce different output in different runs */
    srand((unsigned)time(0));
    
    int weight;
    /* Add deterministic cycle edges to ensure connectivity in the graph */
     /* check if the edge v1,v2 or v2,v1 exists */
    for(int i = 1; i < numV; i++){
            if ( emap.find(make_pair(i,i+1)) == emap.end() ) {
            weight = random (0, EDGE_MAX_WT); //considering integer weights for now
            G->addedge(i,i+1,weight);
            
            emap[make_pair(i,i+1)] = 1;
            emap[make_pair(i+1,i)] = 1;
        }
    }
    //add between the first and the last vertex as well.
    weight = random (0, EDGE_MAX_WT); //considering integer weights for now
    G->addedge(1,numV,weight);
            
    emap[make_pair(1,numV)] = 1;
    emap[make_pair(numV,1)] = 1;
    
    
    
    while(G->numberOfEdges != numE ){
        int v1 = random(1,numV);
        // cout<<v1<<endl;
        int v2 = random(1,numV);
        
        /* check if the edge v1,v2 or v2,v1 exists */
        if ( v1!=v2 && emap.find(make_pair(v1,v2)) == emap.end() ) {
            
            weight = random (0, EDGE_MAX_WT); //considering integer weights for now
            G->addedge(v1,v2,weight);
            
            emap[make_pair(v1,v2)] = 1;
            emap[make_pair(v2,v1)] = 1;
        }
    }
    
    
    return G;
}

int main(){
    
    graph* G1 = generateRandomGraphByAvgDegree(5000,8); // G1 is a graph with 5000 vertices, and average degree 8
    graph* G2 = generateRandomGraphByDegrePc(5000,20); //G2 is a graph with 5000 vertices, and each vertex is neighbours to about 20pc verices.
    
    int source = random (1, 5000);
    int dest = random (1,5000);
    
    cout<<"Source: "<<source<<" Destination: "<<dest<<endl;
    cout<< dijkstraWithoutHeap(G2, source, dest)<<endl;

    // cout<< dijkstraWithoutHeap(G1, source, dest)<<endl;
    // cout<<G2->findVertex[1]->degree<<endl;
    // cout << G1->numberOfVertices <<endl;
    // cout << G1->numberOfEdges <<endl;
    /* average degree */
    // int total = 0;
    // for(int i = 1; i <= G1->numberOfVertices; i++){
    //     total += (G1->findVertex[i])->degree;
    // }
    // cout<<total/(G1->numberOfVertices)<<endl; 
    /* Print adjacency list for first 10 vertices */
    // vertex* v;
     
    // for(int i = 1; i <= 10; i++){
    //     cout<<i<<": ";
    //     v = G1->findVertex[i];
    //     int n = (v->adj).size();
    //     for (int j = 0; j<n; j++){
    //         cout<<"C: "<<(v->adj)[j].first<<" V: "<<(v->adj)[j].second->vNum<<"/ ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
