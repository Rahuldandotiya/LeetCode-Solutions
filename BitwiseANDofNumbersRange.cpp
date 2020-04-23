class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long ans=m&n;
        if(m-n==0) return m&n;
        for(int i=m+1;i<n;i++){
            if(ans==0) return 0;
            ans&=i;
        }
        return ans;
    }
};
