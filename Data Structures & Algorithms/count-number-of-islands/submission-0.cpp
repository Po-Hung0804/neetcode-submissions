class Solution {
    int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        // use bfs without visited array 
        // just change the grid element from 1 to 0
        int rows=grid.size();
        int cols=grid[0].size();
        int land=0;
        for(int i=0;i<rows;i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j);
                    land++;
                }
            }
        }
        return land;
    }
    void bfs(vector<vector<char>>& grid, int r, int c){
        queue<pair<int,int>> q;
        grid[r][c]='0';
        q.push({r,c});
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int row=cur.first;
            int col=cur.second;
            for(int i=0;i<4;i++){
                int nr=row+direction[i][0];
                int nc=col+direction[i][1];
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]=='1'){
                    grid[nr][nc]='0';
                    q.push({nr,nc});
                }
            }
        }
    }
};
