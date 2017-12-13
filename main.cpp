#include <cstdlib>
#include <ctime>
// #include "graph.h"
#include "algoheader.h"
#include <fstream>

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
    
    int addedEdges = G->numberOfEdges; 

    emap[make_pair(1,numV)] = 1;
    emap[make_pair(numV,1)] = 1;
    
    int loopCount = (numV-1)*numV/2 - addedEdges;
    // cout<<"loopCount: "<<loopCount<<endl;
    
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
    
    srand((unsigned)time(0));

    graph* G = new graph;
    
    int numE = avgD*numV/2;
    /* Add MAX_V number of vertices to graph */
    for(int i = 1; i<= numV; i++)
        G->addvertex(i);
    
    /* map to check if we are not adding multiple edges */
    typedef pair<int,int> edge;
    map<edge,int> emap;
    
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

graph* generateFixedGraph(){
    
        graph* G = new graph;
        
        int n = 9;  /* number of predefined vertices */
        /* Add 10 vertices */
        for(int i = 1; i<= n; i++){
            G->addvertex(i);
        }
    
        /* add edges */
        
        G->addedge(1,2,4);
        G->addedge(1,8,8);
        G->addedge(2,8,11);
        G->addedge(2,3,8);
        G->addedge(3,4,7);
        G->addedge(3,6,4);
        G->addedge(3,9,2);
        G->addedge(4,5,9);
        G->addedge(4,6,14);
        G->addedge(5,6,10);
        G->addedge(6,7,2);
        G->addedge(7,8,1);
        G->addedge(7,9,6);
        G->addedge(8,9,7);
        
        return G;
        
}   


int main(){
     /* seed the rand function with the current time, to produce different output in different runs */
    srand((unsigned)time(0));
    
    clock_t overall_start = clock();
    graph* G;
    int temp = 1;
    ofstream myfile;
    myfile.open ("output.txt");
    
    
    
    for(int i = 1; i<=10; i++){
        /* generate 5 pairs of random graphs */
        if(i==6) 
        {temp =2;}
        // cout<<"Generatiing graph "<<i<<": "<<endl;
        // int temp = random(1,2); /* randomly select which type of graph to generate, 1, or 2 */
        if (temp == 1){ //uncomment
        // if (temp == 10){ //comment
            cout<<"Graph "<<i<<"::5000 vertices, and average degree 8."<<endl;
            myfile<<"Graph "<<i<<"::5000 vertices, and average degree 8."<<"\n";

            G = generateRandomGraphByAvgDegree(5000,8); // G is a graph with 5000 vertices, and average degree 8
            // cout<<G->numberOfEdges<<endl;
        }else if (temp == 2){ //uncomment
        // }else if (temp == 1){ //comment
            cout<<"Graph "<<i<<":: 5000 vertices, and each vertex is adjacent to about 20pc vertices..."<<endl;
            myfile<<"Graph "<<i<<":: 5000 vertices, and each vertex is adjacent to about 20pc vertices..."<<"\n";

            G = generateRandomGraphByDegrePc(5000,20); //G is a graph with 5000 vertices, and each vertex is neighbours to about 20pc verices.
            // cout<<G->numberOfEdges<<endl;

        }
        
        for(int j =1; j<=5; j++){
            /* 5 pair of source, destination */
            int source = random (1, 5000);
            int dest = random (1,5000);
            cout<<"Iteration "<<j<<" of 5:"<<endl;
            myfile<<"Iteration "<<j<<" of 5:"<<"\n";

            cout<<"Source: "<<source<<" Destination: "<<dest<<endl;
            myfile<<"Source: "<<source<<" Destination: "<<dest<<"\n";
    
   
    
    cout<<"DijkstraWithoutHeap::Begins::"<<endl;
    myfile<<"DijkstraWithoutHeap::Begins::"<<"\n";

    clock_t start = clock();
    double b = dijkstraWithoutHeap(G, source, dest);
    clock_t stop = clock();

    cout<<"DijkstraWithoutHeap::Max Bandwidth::"<<  b<<endl;
    myfile<<"DijkstraWithoutHeap::Max Bandwidth::"<<  b<<"\n";
    // double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    // cout<<"DijkstraWithoutHeap: Time elapsed in ms: "<< elapsed<<endl;
    double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<"DijkstraWithoutHeap::Finished::Time elapsed in seconds: "<< elapsed<<endl;
    myfile<<"DijkstraWithoutHeap::Finished::Time elapsed in seconds: "<< elapsed<<"\n";
    
    cout<<"*-----------------------------------------------*"<<endl;
    myfile<<"*-----------------------------------------------*"<<"\n";

    cout<<"DijkstraWithHeap::Begins::"<<endl;
    myfile<<"DijkstraWithHeap::Begins::"<<"\n";

    start = clock();
    b = dijkstraWithHeap(G, source, dest);
    stop = clock();
    cout<<"DijkstraWithHeap::Max Bandwidth::"<<  b<<endl;
    myfile<<"DijkstraWithHeap::Max Bandwidth::"<<  b<<endl;

    elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<"DijkstraWithHeap::Finished::Time elapsed in seconds: "<< elapsed<<endl;
    myfile<<"DijkstraWithHeap Finished::Time elapsed in seconds: "<< elapsed<<"\n";
    
    cout<<"*-----------------------------------------------*"<<endl;
    myfile<<"*-----------------------------------------------*"<<"\n";

    
    cout<<"Kruskal::Begins::"<<endl;
    myfile<<"Kruskal::Begins::"<<"\n";
    start = clock();
    b=  kruskal(G, source, dest);
    stop = clock();
    cout<<"Kruskal::Max Bandwidth::"<<  b<<endl;
    myfile<<"Kruskal::Max Bandwidth::"<<  b<<"\n";

    elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    cout<<"Kruskal::Finished::Time elapsed in seconds: "<< elapsed<<endl;
    myfile<<"Kruskal Finished::Time elapsed in seconds: "<< elapsed<<"\n";
    
    cout<<"*-----------------------------------------------*"<<endl;
    myfile<<"*-----------------------------------------------*"<<"\n";
    
    
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
     
    // for(int i = 1; i <= 9; i++){
    //     cout<<i<<": ";
    //     v = G1->findVertex[i];
    //     int n = (v->adj).size();
    //     for (int j = 0; j<n; j++){
    //         cout<<"C: "<<(v->adj)[j].first<<" V: "<<(v->adj)[j].second->vNum<<"/ ";
    //     }
    //     cout<<endl;
    // }
            
        }
    cout<<"*==================================================*"<<endl;
    myfile<<"*==================================================*"<<"\n";
    G->~graph();
    }
    
    clock_t overall_stop = clock();
    double overall_elapsed = (double)((overall_stop - overall_start) / CLOCKS_PER_SEC)/60.0;
    cout<<"Total time taken by program: (in minutes)"<< overall_elapsed<<endl;
    myfile<<"Total time taken by program: (in minutes)"<< overall_elapsed<<"\n";
    myfile.close();
    
    return 0;
}
