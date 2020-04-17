class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(nums.size()<4) return ans;
        int n=nums.size();
        int l=0;
        int h=nums.size()-1;
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            if( nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > t ) break;
            if( nums[i] + nums[n-3] + nums[n-2] + nums[n-1 ] < t ) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if( j > i+1 && nums[j-1] == nums[j] ) continue;
                if( nums[i] + nums[j] + nums[j+1] + nums[j+2] > t ) break;
                if( nums[i] + nums[j] + nums[n-2] + nums[n-1] < t ) continue;
                l=j+1;
                h=nums.size()-1;
                while(l<h){
                    int sum = nums[i] + nums[j] + nums[l] + nums[h];
                    if(sum==t){
                        ans.push_back({ nums[i], nums[j], nums[l], nums[h] });
                        l++;
                        h--;
                        while(l<h and nums[l]==nums[l-1]) l++;
                        while(l<h and nums[h]==nums[h+1]) h--;
                    }
                    else if(sum>t) h--;
                    else l++;
                }
            }
        }
        return ans;
    }
};
