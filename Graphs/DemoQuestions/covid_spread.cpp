

bool valid(int i , int j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}   

void solve(){
    queue<pair<int,int>> q;

    //Step 1: Traverse all the matrix && push infected patients
    for(){ // traverse all the rows
        for(){ // traverse all the column for each Rows.
            if() // condition for infected one
                q.push({i,j})  // push the infected one
        }
    }

    //Step 2: Set Timer
    int timer = 0 ;
    while(!q.empty()){
        timer++;
        int curr_patitent = q.size(); // currently how many patient we have inside a queue.

        while(curr_patitent--){
            // explore all the 4 directions
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k = 0 ; k < 4 ; k++){
                int new_i = i + dx[k];
                int new_j = j + dy[k];

                if(
                    valid(new_i,new_j) &&
                    hospital[new_i][new_j] == 1s
                ) // check the boundary condition && check the healthy one
                    {
                        hospital[new_i][new_j] = 2; // make the healthy one infected
                        q.push({new_i,new_j}) // push the newly infected one
                    }
            }
        }
    }

    
}