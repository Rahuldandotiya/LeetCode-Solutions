class Solution {
public:
    vector<vector<int>> ans;
    void find(vector<int>& candidates,vector<int>& v, int target,int i=0){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int j=i;j<candidates.size() and target>=candidates[j];j++){
            v.push_back(candidates[j]);
            find(candidates,v,target-candidates[j],j);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates,int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        find(candidates,v,target);
        return ans;
    }
};
