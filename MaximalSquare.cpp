class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size();
        if(n==0 or m==0) return 0;
        int v[n][m];
        for(int i=0;i<n;i++){
            if(matrix[i][0]=='0') v[i][0]=0;
            else v[i][0]=1;
        }
        for(int i=0;i<m;i++){
            if(matrix[0][i]=='0') v[0][i]=0;
            else v[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){
                    v[i][j]=min(v[i][j-1],min(v[i-1][j],v[i-1][j-1]))+1;
                }
                else v[i][j]=0;
            }
        }
        int maxx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) 
                if(maxx<v[i][j]) 
                    maxx=v[i][j];
        }
        if(maxx==1) return maxx;
        return maxx*maxx;
    }
};
