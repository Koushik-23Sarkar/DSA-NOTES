/**
        Bellman-Ford algorithm

        1. only works for directed graphs
        2. can detect negative weight cycles

--------------------------------------------------------------------------------------------
        1. (Relax all edges) * ( |V| - 1 times )
        2. Relax all edges once more to check for negative weight cycles (if any updation happens, then there is a negative weight cycle)

*/


/**
    Time complexity: O(V*E)
    Space complexity: O(V)
*/


vector<int> bellman_ford(){
    vector<int> dist(V, INT_MAX); 
    // vector<int> dist(V,1e8);
    
    dist[src] = 0;
    int e = edges.size(); // no. of edges
    
    for(int i=0;i<V-1;i++){ // V-1 times
        
        bool flag = 0; // to check if any updation happens in this iteration
        // relax all edges
        for(int j=0;j<e;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                flag = 1;
                dist[v] = dist[u] + wt;
            }
        }
        
        if(!flag()){
            return dist; // if no updation happens, then we can stop early
        }
    }
    
    
    // check for negative weight cycles
    for(int j=0;j<e;j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        
        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
            cout<<"Negative weight cycle detected!"<<endl;
            return {};
        }
    }
    return dist;
}


/**
    We can also apply in this algorithm into directed graph. But you should not do that.
*/

 // If we have undirected graph && we have -ve weight edges, then we can not apply Bellman-Ford && Dijkstra algorithms.
 
