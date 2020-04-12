class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0 or nums.size()==1) return false;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
            }
            else return true;
        }
        return false;
    }
};
