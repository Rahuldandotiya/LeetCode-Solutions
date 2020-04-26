class Solution {
public:
    /*
    // recursive solution
    int lcs(string s1,string s2,int m,int n){
        if(m<0 or n<0) return 0;
        if(s1[m]==s2[n]) return 1+lcs(s1,s2,m-1,n-1);
        else return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
    }*/
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        /*
        //TLE
        return lcs(text1,text2,m-1,n-1);
        */
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++) dp[i][0]=0;
        for(int i=0;i<=n;i++) dp[0][i]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
