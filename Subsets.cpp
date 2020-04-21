class Solution {
public:
    vector<vector<int>> ans;
    void find(vector<int>& nums,int i,vector<int> v){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        find(nums,i+1,v);
        v.push_back(nums[i]);
        find(nums,i+1,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        // brute force
        set<vector<int>> s;
        vector<vector<int>> ans;
        for(int i=0;i<(1<<nums.size());i++){
            vector<int> temp;
            for(int j=0;j<nums.size();j++){
                if((i&(1<<j))>0) temp.push_back(nums[j]);
            }
            if(s.find(temp)==s.end()){
                s.insert(temp);
                ans.push_back(temp);
            }
        }
        return ans;
        */
        // recursive
        vector<int> v;
        find(nums,0,v);
        return ans;
    }
};
