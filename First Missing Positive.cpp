class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int minn=1;
        unordered_set<int> m;
        for(int i=0;i<nums.size();i++){
            m.insert(nums[i]);
            if(m.find(minn)!=m.end()) minn++;
        }
        while(true){
            if(m.find(minn)!=m.end()) minn++;
            else break;
        }
        return minn;
    }
};
