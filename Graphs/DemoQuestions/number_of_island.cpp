

int rows;
int cols;

int solve(){

    rows = grid.size();
    cols = grid[0].size();

    int count = 0;
    queue<pair<int,int>> q;


    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            if(grid[i][j]=='1'){
                count++;
                q.push({i,j});
                grid[i][j] = '0';

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int k = 0 ; k < 4 ; k++){
                        int new_x = x + dx[k];
                        int new_y = y + dy[k];

                        if(
                            valid(new_x,new_y) &&
                            grid[new_x][new_y] == '1'
                        ){
                            grid[new_x][new_y] = '0';
                            q.push({new_x,new_y});
                        }
                    }
                }
            }

        }
    }

    return count;
                
}