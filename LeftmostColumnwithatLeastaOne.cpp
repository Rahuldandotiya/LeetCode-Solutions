/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> v=binaryMatrix.dimensions();
        /*
        // time- O(n*lon(n))
        int i=0;
        int ans=v[1];
        while(i<v[0]){
            int h=v[1]-1;
            int l=0;
            while(l<=h){
                int mid=(l+h)/2;
                if(binaryMatrix.get(i,mid)==1){
                    if(ans>mid) ans=mid;
                    h=mid-1;
                }
                else l=mid+1;
            }
            i++;
        }
        if(ans==v[1]) return -1;
        return ans;
        */
        // time O(log(n))
        int ans=v[1];
        int i=0,j=v[1]-1;
        while(i<v[0] and j>=0){
            if(binaryMatrix.get(i,j)==1){
                if(ans>j) ans=j;
                j--;
            }
            else i++;
        }
        if(ans==v[1]) return -1;
        return ans;
    }
};
