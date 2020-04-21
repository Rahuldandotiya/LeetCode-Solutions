class Solution {
public:
    vector<vector<int>> v;
    vector<vector<int>> permute(vector<int>& nums,int l=0) {
        if(l==nums.size()-1) v.push_back(nums);
        for(int i=l;i<nums.size();i++){
            swap(nums[i],nums[l]);
            permute(nums,l+1);
            swap(nums[i],nums[l]);
        }
        /*
        int f=1;
        for(int i=1;i<=nums.size();i++) f*=i;
        while(f--){
            v.push_back(nums);
            next_permutation(nums.begin(),nums.end());
        }
        */
        return v;
    }
};
