#include "algoheader.h"

void printPath(const vector<int>& DAD, int d){
    int v = d;
    
    while(v != 0){
        cout<<v;
        // myfile<<v;
        v = DAD[v];
        if (v != 0){
            cout<<"-->";
            // myfile<<"-->";
        }
        else{
            cout<<endl;
            // myfile<<"\n";
        }
            
    }
}

// void setKruskal::makeSet(int n){
//     for(int i = 1; i<=n ;i++)
//         parent[i] = i;
// }

int setKruskal::findRoot(int v){
    int w = v;
    while(parent[w] != 0){
        w = parent[w];
    }
    return w;
}
void setKruskal::unionSet(int r1, int r2){
    if(rank[r1] < rank[r2]){
        parent[r1] = r2;
    }else if(rank[r2] < rank[r1]){
        parent[r2] = r1;
    }else if(rank[r2] == rank[r1]){
        parent[r1] = r2;
        rank[r2]++;
    }
}

double BFS (graph* G, int s, int d){
    int n = G->numberOfVertices;
    vector<int> DAD (n+1,INT_MAX);
    vector<bool> VISITED(n+1, 0); 
    vector<double> BANDWIDTH(n+1);
    
    VISITED[s] = 1;
    DAD[s] = 0;
    BANDWIDTH[s] = DBL_MAX;
    
    queue<int> q;
    
    q.push(s);
    
    while(!q.empty() && VISITED[d] == 0){
        int u = q.front();
        q.pop();
        vertex* v=  G->findVertex[u];
        
        
        int aSize = v->adj.size();
        
        for(int i = 0; i< aSize; i++){
            vertex* neighbour = v->adj[i].second;
            double minB = (v->adj[i].first < BANDWIDTH[u])? v->adj[i].first : BANDWIDTH[u];  

            if (VISITED[neighbour->vNum] == 0){
                VISITED[neighbour->vNum] = 1;
                DAD[neighbour->vNum] = u;
                BANDWIDTH[neighbour->vNum] = minB;
                q.push(neighbour->vNum);
            }
        }
    }
    
    G->~graph();
    printPath(DAD, d);
    return BANDWIDTH[d];
}
