#include <bits/stdc++.h>
using namespace std ;

#define INF 1000

//Dijkstra

//globals
//src as source vertex, cost is weight of each edge
int V , src , cost[100][100] ;
int dist[100] ;
bool visited[100] = {0} ;
//keeps track of visited with T/F, all default as unvisted

void basic(){
    for(int i = 0;i <V ; i++)
    dist[i] = INF ;
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
}

void dijalgo(){
    //run for V-1 number of times to hit every vertex (starting at src)
    for(int i =0 ; i < V-1 ; i++){
        int nearest = getnearest() ;
        visited[nearest] ;
    }
}

int main(){
    cin >> V ;
    for(int i = 0 ; i < V ; i++){
        for(int j = 0 ; j < V ; j++){
            cin >> cost[i][j] ;
        }
    }
    cin >> src ;
}