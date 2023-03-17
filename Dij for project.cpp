#include <bits/stdc++.h>
using namespace std ;

#define INF 1000
//defining infinity so it doesn't mess with calculations

//Dijkstra

//globals
//src as source vertex, cost is weight of each edge
int V , src , cost[100][100] ;
int dist[100] ;
bool visited[100] = {0} ;
//keeps track of visited with T/F, all default as unvisted
int parent[100] ;
//parent of a node is itself


void basic(){
    for(int i = 0;i <V ; i++){
    dist[i] = INF ;
    parent[i] = i;
    //parent of a vertex is itself
    }
    //distance from src to itself is 0
    dist[src] = 0 ;
}


int getnearest() {
    int minvalue = INF ;
    int minvertex = 0 ;
    for(int i = 0 ; i < V ; i++){
        if(!visited[i] and dist[i] < minvalue){
            minvalue = dist[i] ;
            //if the node is not visited and the distance is less than infinity it becomes the new lowest value
            minvertex = i ;
        }
    }
    return minvertex ;
    //if the conditions are met, return the minvertex
}

void dijalgo(){
    //run for V-1 number of times to hit every vertex (starting at src)
    for(int i = 0 ; i < V-1 ; i++){
        int nearest = getnearest() ;
        visited[nearest] = true ;
        //once we visit the nearest node we mark it as visited

        for(int adjacent = 0 ; adjacent < V ; adjacent++){
            if(cost[nearest][adjacent] != INF and dist[adjacent]>dist[nearest]+cost[nearest][adjacent]){
                dist[adjacent] = dist[nearest]+cost[nearest][adjacent] ;
                //if the an adjacent vertex is not infinity and it is less than the other options then you update the adjacent node as the new one
                parent[adjacent] = nearest ;
                //update the parent vertex when we move to the next one
            }
        }
    }
}

void display(){
    cout<<"Node:\t\t\tCost:  \t\t\tPath:\n"    ;
    //These act as the titles for each column, the slash t is a horizontal tab, spacing out the columns
    for(int i = 0; i < V; i++){
        cout<<i<<"\t\t\t"<<dist[i]<<"\t\t\t"<<" " ;
    //For node, it counts up from 0 adding one, stopping when i=V, the second column uses the shortests distance from the source node as the value for the cost
        cout << i <<" ";
        int parnode = parent[i];
        
        while(parnode != src){
            cout<<" <- " << parnode << " ";
            parnode = parent[parnode];
        }
        cout<<endl ;
        //endl inserts a new line and flushes the output buffer
    }
}

int main(void){
    cout << "Enter the number of vertices: " ;
    //Figured out C++ is zero indexing 
    cin >> V ;
    cout<<"Enter the cost matrix: \n";
    //this is the adjacency matrix (learned in discrete math)
    for(int i = 0 ; i < V ; i++){
        for(int j = 0 ; j < V ; j++){
            cin >> cost[i][j] ;
        }
    }
    cout<<"Enter source node : " ;
    cin >> src ;
    //algorithm calculates distance from source node to other nodes
    basic() ;
    dijalgo() ;
    display();
    //finally calling all of the functions
}