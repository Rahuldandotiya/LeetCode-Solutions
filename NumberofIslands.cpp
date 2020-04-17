class Solution {
public:
    void removeIslands(vector<vector<char>>& grid,int i,int j){
        grid[i][j]='0';
        if(i-1>=0 and grid[i-1][j]=='1') removeIslands(grid,i-1,j);
        if(i+1<grid.size() and grid[i+1][j]=='1') removeIslands(grid,i+1,j);
        if(j-1>=0 and grid[i][j-1]=='1') removeIslands(grid,i,j-1);
        if(j+1<grid[0].size() and grid[i][j+1]=='1') removeIslands(grid,i,j+1); 
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        if(grid.size()==0) return count;
        if(grid[0].size()==0) return count;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    removeIslands(grid,i,j);
                }
            }
        }
        return count;
    }
};
