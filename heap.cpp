#include "heap.h"

 
void maxHeap::insertHeap(int v, double data){
    //insert in position lastPos+1
    lastPos++;
    heapPos[lastPos] = v; 
    heapData[v] = data; 
    mapHeap[v] = lastPos;
    heapify(lastPos);
}
bool maxHeap::isEmpty(){
    return lastPos == 0?1:0;
}
void maxHeap::deleteHeap(int i){
    if(isEmpty()){
        return;
    }
    swap(i, lastPos);
    lastPos--;
    heapify(i);
}

void maxHeap::swap(int i, int j){
    //swaps the position of the vertex at i, with the vertex at j
    int temp = heapPos[i];
    heapPos[i] = heapPos[j];
    heapPos[j] = temp;
    mapHeap[temp] = j ;
    mapHeap[heapPos[i]] = i ;
    
}
void maxHeap::heapify(int pos){
    if(pos <= lastPos) {
        if(pos > 1){ //There can be a parent
            int p = parent(pos);
            if(heapData[heapPos[p]]< heapData[heapPos[pos]] ){
                swap(p,pos);
                heapify(p);
                return;
            }
        }
        int l = leftChild(pos);
        int r = rightChild(pos);
        int larger = pos; //assume it is larger than it's children
        
        if (l <= lastPos && heapData[heapPos[l]] > heapData[heapPos[pos]]){
            larger = l;
        }
        if (r <= lastPos && heapData[heapPos[r] ]  > heapData[heapPos[larger]]){
            larger = r;
        }
        if( larger != pos){
            swap(pos, larger);
            heapify(larger);
        }
    }
    
}
int maxHeap::parent(int i){
    return i/2;
    
}
int maxHeap::leftChild(int i){
    return 2*i;
}
int maxHeap::rightChild(int i){
    return 2*i+1;
}


double maxHeap::maxVal(){
    int ret;
    if (lastPos > 0)
        ret = heapData[heapPos[1]];
    else return 0;
    // deleteHeap(1);
    return ret;
}

void maxHeap::printHeap(){
    for(int i = 1; i<= lastPos; i++){
        cout<<"("<<heapPos[i]<<", "<<heapData[heapPos[i]]<<")";
        if(i+1 <= lastPos) cout<<"--";
        else cout<<endl;
    }
}

int maxHeap::extractMax(){
    int ret;
    if (lastPos > 0)
        ret = heapPos[1];
    else return 0;
    deleteHeap(1);
    return ret;
}

// int main(){
//     maxHeap H(5);// create a max heap of 5 vertices
    
//     H.insertHeap(1,500);
//     H.insertHeap(2,100); 
//     H.insertHeap(5,50); 

//     //after this step we need the extractHeap to return 2
    
//     // cout<<H.extractMax()<<endl;
    
//     cout<< H.mapHeap[1]<<endl; 
//     H.deleteHeap(H.mapHeap[1]);
//     cout<<H.extractMax()<<endl;
//     H.insertHeap(1 , 5000);
//     cout<<H.extractMax()<<endl;

//     return 0;
// }