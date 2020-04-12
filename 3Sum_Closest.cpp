//brute force Solution
// Compexity O(N^3)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int diff=INT_MAX;
        int ans=0;
        if(nums.size()<3) return ans;
        int l=0;
        int h=nums.size()-1;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    int a=abs(nums[i]+nums[j]+nums[k]-t);
                    if(a<diff){
                        diff=a;
                        ans=nums[i]+nums[j]+nums[k];
                    }
                }
            }
        }
        return ans;
    }
};


//Optimized Solution
// Compexity O(N^2)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1;
            int h=nums.size()-1;
            while(l<h){
                int s=nums[i]+nums[l]+nums[h];
                if(s==t) return s;
                if(abs(s-t)<abs(ans-t)){
                    ans=s;
                }
                if(s<t) l++;
                else h--;
            }
        }
        return ans;
    }
};

