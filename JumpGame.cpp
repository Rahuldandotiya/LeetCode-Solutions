class Solution {
public:
    bool canJump(vector<int>& nums,int i=0) {
        /*
        //TLE
        if(i==nums.size()-1) return true;
        if(nums[i]==0) return false;
        bool f=false;
        for(int j=1;j<=nums[i];j++){
            if(j+i<=nums.size()-1) f=f || canJump(nums,j+i);
        }
        return f;
        
        */
        int maxx=0;
        for(int i=0;i<nums.size();i++){
            if(maxx<i) return false;
            maxx=max(maxx,i+nums[i]);
        }
        return true;
    }
};
