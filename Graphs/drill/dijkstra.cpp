// V times: (for each node)
//     1. Select the vertex(node) is not explored yet and It's dist is minimum among all the unexplored vertices(nodes).
//     2. Relax the edges: 
//         i. Look at your all the unexplored neighbours.
//         ii. if(dist[node]+weight < dist[neighbour]){
//                 dist[neighbour] = dist[node]+weight
//             }



/**
Dijkstra's Algorithm:
1. We can apply this Algo: "Directed/Undirected Graphs with non-negative weights"
*/


// Code:
vector<int> dijkstra1(){     //----> O(V^2) in worst case
    vector<bool> Explored(V,0); // To check which nodes are explored
    vector<int> dist(V,Int_MAX); // every nodes are in infinite dist.

    dist[S] = 0; // source node is in 0 dist.

    int count = V;

    while(count--){     //------> O(V)
        // Select a node which is not explored yet && it's dist value is min.
    int node = -1;
    int value = INT_MAX;
    for(int i=0;i<V;i++){ // V: no. of Nodes    //-----> O(V)
        if(!Explored[i] && value>dist[i]){
            node=i;
            value=dist[i];
        }
    }
    Explored[node]=1;

    // Relax the Edges
    for(int j=0;j<adj[node].size();j++){    //-----> O(V-1) in worst case
        int neighbour = adj[node][j][0];
        int weight = adj[node][j][1];

        if(
            !Explored[neighbour] &&
            (dist[node]+weight<dist[neighbour])
        ){
            dist[neighbour] = dist[node]+weight
        }
    }
    }

    
    return dist;

}


vector<int> dijkstra2(){     //----> O(ElogV) in worst case
    vector<bool> Explored(V,0); // To check which nodes are explored
    vector<int> dist(V,Int_MAX); // every nodes are in infinite dist.

    dist[S] = 0; // source node is in 0 dist.

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // min heap
    pq.push({0,S}); // {dist,node}

    while(!pq.empty()){     //------> O(V)
        int node = pq.top().second;
        pq.pop();

        if(Explored[node]==1) continue; // if the node is already explored, then we can ignore it.
        Explored[node]=1;

        for(int j=0;j<adj[node].size();j++){    //-----> O(V-1) in worst case
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];

            if(
                !Explored[neighbour] &&
                (dist[node]+weight<dist[neighbour])
            ){
                dist[neighbour] = dist[node]+weight;
                pq.push({dist[neighbour],neighbour});
            }
        }
    }

    
    return dist;

}
