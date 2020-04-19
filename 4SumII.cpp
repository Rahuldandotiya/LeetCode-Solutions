class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count=0;
        if(A.size()==0) return count;
        unordered_map<int,int> m;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A.size();j++) m[A[i]+B[j]]++;
        }
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A.size();j++){
                if(m.find(-C[i]-D[j])!=m.end()) count+=m[-C[i]-D[j]];
            }
        }
        return count;
    }
};
