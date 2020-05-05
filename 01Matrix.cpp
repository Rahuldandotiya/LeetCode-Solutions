class Solution {
public:
    bool issafe(vector<vector<int>>& matrix,int i,int j){
        if(i>=0 && j>=0 && i<matrix.size() && j<matrix[0].size()) return true;
        return false;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return {{}};
        vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    ans[i][j]=0;
                    q.push(make_pair(i,j));
                }
            }
        }
        int x[]={0,0,1,-1};
        int y[]={1,-1,0,0};
        pair<int,int> p;
        while(!q.empty()){
            p=q.front();
            q.pop();
            int m=p.first;
            int n=p.second;
            for(int i=0;i<4;i++){
                int idx=x[i]+m;
                int idy=y[i]+n;
                if(issafe(matrix,idx,idy)){
                    if(ans[idx][idy]>ans[m][n]+1){
                        ans[idx][idy]=ans[m][n]+1;
                        q.push(make_pair(idx,idy));
                    }
                }
            }
        }
        return ans;
    }
};
