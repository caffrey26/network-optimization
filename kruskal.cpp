#include "algoheader.h"

double kruskal(graph* G, int source, int dest){
     typedef pair<int,int> edge;
    //  map<edge,int> emapExist;
    //  map<int,edge> emap;
     
     int n = G->numberOfVertices; 
     maxHeap H(G->numberOfEdges); //the heap is based on number of edges
     
     /* insert each edge along with its weight into heap. Keep a note that you don't add the same edge twice */
    //  int edgeCount = 0;
     
     /* insert all edges in heap */
    //  for (int i = 1; i <= n; i++){ //vertice number start from 1 to n
    //     vertex* s = G->findVertex[i];
    //     int n1 = s->adj.size(); //size of adjacency list for this vertex
    //     for(int j = 0; j<n1; j++){
    //         vertex* neighbour = s->adj[j].second;
            
    //         /* the edge identified is [i,neighbour->vNum] with weight s->adj[j].first */
            
    //         /* add this edge to heap if it is not already accounted for */
    //         if ( emapExist.find(make_pair(i,neighbour->vNum)) == emapExist.end() ) { 
    //             /* add to heap */
    //             edgeCount++;
    //             /* we need to somehow number the edges so that we can effectively insert them in the heap */
    //             emapExist[make_pair(i,neighbour->vNum)] = edgeCount;
    //             emapExist[make_pair(neighbour->vNum,i)] = edgeCount;
    //             emap[edgeCount] = make_pair(i,neighbour->vNum);
                
    //             // cout<<"edgeCount "<<edgeCount<<": "<<i<<", "<<neighbour->vNum<<"  "<<s->adj[j].first<<endl; // comment
                
    //             H.insertHeap(edgeCount, s->adj[j].first);
    //         }
    //     }
    // }
    
    for(int i = 0; i < G->edges.size(); i++){
        // G->edge[i] //edge in G with respective cost, and edgeNumber
        H.insertHeap(G->edges[i]->edgeNumber, G->edges[i]->cost);
    }
    // G->edges //is a vector of edges in G with respective cost, and edgeNumber
    
    // if(edgeCount != G->numberOfEdges) cout<<"There is some problem";
    
    // H.printHeap(); //comment
    
    /* We use makeSet, Find, and Union routines */
    setKruskal S(n);
    
    /* take the edges in descending order */
    int addedEdges = 0; 
    graph* MST = new graph;
    for(int i = 1; i<= n; i++)
        MST->addvertex(i);
    
    // S.makeSet(); //Make each vertex it's own parent
    
    // clock_t stop =clock();
    
    // double    elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
        
    // cout<<"Kruskal till heap formation: Time elapsed in seconds: "<< elapsed<<endl;
    // // return 0;
    
    // start = clock();
    
    // for(int i = 1; i<= edgeCount; i++){ 
    while (addedEdges != n-1){ //uncomment
    // int lo = 1; while(lo++ < 2){ //comment        
         double cost = H.maxVal();
         int e = H.extractMax();  
        //e is the edge number, and it is [u,v]
        //  int u = emap[e].first;
        //  int v = emap[e].second;
         
        //  cout<<u<<" "<<v<<endl;
         int u = G->edges[e-1]->v1->vNum; //this is a pointer to an edge 
         int v = G->edges[e-1]->v2->vNum;
         int r1 = S.findRoot(u);
         int r2 = S.findRoot(v);
         
        //  cout<<r1<<" "<<r2<<endl;
         if(r1 != r2){
             /* no cycle, this edge will be added. */
             addedEdges++;
             S.unionSet(r1,r2);
             MST->addedge(u,v,cost);
            //  cout<<"Edge "<<addedEdges<<" "<<u<<","<<v<<" ("<<cost<<")"<<endl;
         }
        //  H.printHeap();
    }
    // stop =clock();
    // elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    // cout<<"Kruskal after adding edges to MST : Time elapsed in seconds: "<< elapsed<<endl;
    // return 0;
    /* Print the adjacency list of the MST (vertex number is hard=coded)*/
    //   for(int i = 1; i <= 9; i++){
    //     cout<<i<<": ";
    //     vertex* v = MST->findVertex[i];
    //     int n = (v->adj).size();
    //     for (int j = 0; j<n; j++){
    //         cout<<"C: "<<(v->adj)[j].first<<" V: "<<(v->adj)[j].second->vNum<<"/ ";
    //     }
    //     cout<<endl;
    // }
    /* We want to traverse the graph from source s, and get a path from t to s. so we use BFS */
    return BFS(MST,source,dest);
     
}