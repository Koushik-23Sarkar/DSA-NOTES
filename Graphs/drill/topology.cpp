

void topology (int node , vector<int> &vis , stack<int> &st , vector<vector<int>> &adj){
    vis[node]=1;

    // traverse all the neighbors of the node
    for(auto neigh : adj[node]){
        if(!vis[neigh])
            topology(neigh , vis , st , adj);

    }

    st.push(node);
}
// take nodes from the stack and print them



void bfsTopology(int n , vector<vector<int>> &adj){
    vector<int> indegree(n , 0);

    for(int i = 0 ; i < n ; i++){
        for(auto neigh : adj[i]){
            indegree[neigh]++;
        }
    }

    queue<int> q;

    for(int i = 0 ; i < n ; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(auto neigh : adj[node]){
            indegree[neigh]--;
            if(indegree[neigh] == 0)
                q.push(neigh);
        }
    }
}