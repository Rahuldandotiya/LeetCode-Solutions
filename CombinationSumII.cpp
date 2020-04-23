class Solution {
public:
    vector<vector<int>> ans;
    void find(vector<int> &vi,set<vector<int>> &s,vector<int>& candidates,vector<int>& v, int target,int i=0){
        if(target==0){
            if(s.find(v)==s.end()){
                ans.push_back(v);
                s.insert(v);
            }
            return;
        }
        for(int j=i;j<candidates.size() and target>=candidates[j];j++){
            if(vi[j]==0){
                v.push_back(candidates[j]);
                vi[j]=1;
                find(vi,s,candidates,v,target-candidates[j],j);
                vi[j]=0;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        vector<int> vi(candidates.size());
        //for(int i=0;i<candidates.size();i++) vi.push_back(1);
        set<vector<int>> s;
        find(vi,s,candidates,v,target);
        return ans;
    }
};
