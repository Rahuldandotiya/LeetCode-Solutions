class Solution {
public:
    int s;
    void generate(vector<string> &ans,int i,int n,int o,int c,string str){
        if(c==n){
            ans.push_back(str);
            return;
        }
        else{
            if(o>c){
                str[i]=')';
                generate(ans,i+1,n,o,c+1,str);
            }
            if(o<n){
                str[i]='(';
                generate(ans,i+1,n,o+1,c,str);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string str="";
        for(int i=0;i<2*n;i++) str+=' ';
        vector<string> ans;
        if(n==0){
            ans.push_back("");
            return ans;
        }
        generate(ans,0,n,0,0,str);
        return ans;
    }
};
