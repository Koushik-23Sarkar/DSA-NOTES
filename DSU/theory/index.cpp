

// Find function in DSU
int find(int i,vector<int>& parent){
    if(i == parent[i]){
        return i;
    }
    return find(parent[i],parent);
}

// Union function in DSU
void union(int i, int j){
    int parent_i = find(i,parent);
    int parent_j = find(j,parent);

    if(parent_i != parent_j)
        parent[parent_i]=parent_j;
}

//###############################################################################################

int find(int i, vector<int>& parent){
    if(i == parent[i])
        return i;

    return parent[i] = find(parent[i],parent)
}

void union(int i,int j){
    parent_i = find(i,parent);
    parent_j = find(j,parent);

    if(parent_i == parent_j)
        return;

    if(rank[parent_i] > rank[parent_j]){
        parent[parent_j] = parent_i;
    }else if(rank[parent_i] < rank[parent_j]){
        parent[parent_i] = parent_j;
    }else {
        parent[parent_i] = parent_j;
        rank[parent_j]++;
    }

}