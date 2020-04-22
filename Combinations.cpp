class Solution {
public:
    vector<vector<int>> ans;
    void find(int n,int k,vector<int> v,int l=1){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=l;i<=n;i++){
            if(v.size()==0 or v[v.size()-1]<i){
                v.push_back(i);
                find(n,k,v,l+1);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if(k==0 or k>n) return ans;
        vector<int> v;
        find(n,k,v);
        return ans;
    }
};
