class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int z=0;
        int o=0;
        int maxsub=0;
        map<int,int> m;
        m[0]=-1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) count+=-1;
            else count+=1;
            if(m.find(count)!=m.end()){
                maxsub=max(maxsub,i-m[count]);
            }
            else m[count]=i;
        }
        return maxsub;
    }
};
