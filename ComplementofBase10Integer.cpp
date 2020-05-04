class Solution {
public:
    int bitwiseComplement(int N) {
        int ans=0;
        long p=1;
        do{
            if(N%2==0) ans+=p;
            N=N>>1;
            p*=2;
        }while(N);
        return ans;
    }
};
