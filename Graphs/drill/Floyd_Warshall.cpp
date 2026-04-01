

void Floyd_Warshall(){

    int n = martix.size();
    for(int k = 0; k < n; k++){ // intermediate vertex
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(martix[i][k] == INF || martix[k][j] == INF){
                    continue;
                }

                martix[i][j] = min(martix[i][j], martix[i][k] + martix[k][j]);
            }
        }
    }
}


/**
    If any diagonal element is negative, then there is a negative cycle in the graph.
*/

