class Solution {
public:
    int binnary(vector<int>& nums,int l,int h,int target){
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) h=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        if(nums.size()==0) return -1;
        int l=0,h=nums.size()-1;
        int mid=(l+h)/2;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]<=nums[h]){
                if(nums[mid]<=target and target<=nums[h]){
                    return binnary(nums,mid,h,target);
                }else{
                    h=mid-1;
                }
            }
            else{
                if(nums[mid]>=target and target>=nums[l]){
                    return binnary(nums,l,mid,target);
                }else{
                    l=mid+1;
                }
            }
        }
        return -1;
    }
};
