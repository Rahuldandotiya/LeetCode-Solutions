class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        int t=0;
        int l=0;
        int h=nums.size()-1;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0) break;
            if(i!=0 and nums[i]==nums[i-1]) continue;
            t=0-nums[i];
            l=i+1;
            h=nums.size()-1;
            while(l<h){
                if(nums[h]<0) break;
                if((nums[l]+nums[h])==t){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[h]);
                    ans.push_back(temp);
                    while(l<h && nums[l]==nums[l+1]) l++;
                    while(l<h && nums[h]==nums[h-1]) h--;
                    ++l;
                    --h;
                }
                else if((nums[l]+nums[h])<t) l++;
                else h--;
            }
        }
        return ans;
    }
};
