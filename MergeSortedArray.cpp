class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1=nums2;
            return;
        }
        if(n==0) return;
        int j=n-1;
        int k=m-1;
        int a;
        for(int i=m+n-1;i>=0;i--){
            if(nums1[k]<=nums2[j]){
                nums1[i]=nums2[j];
                j--;
            }
            else if(nums1[k]>nums2[j]){
                nums1[i]=nums1[k];
                k--;
            }
            if(j<0 or k<0){
                a=i;
                break;
            }
        }
        a--;
        while(j>=0){
            nums1[a]=nums2[j];
            j--;
            a--;
        }
    }
};
