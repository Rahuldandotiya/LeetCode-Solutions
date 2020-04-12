class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int i=0;
        int n=digits[0]+1;
        for(i=1;i<digits.size();i++){
            digits[i-1]=n%10;
            n/=10;
            n+=digits[i];
        }
        if(n>=10){
            digits[i-1]=n%10;
            digits.push_back(n/10);
        }
        else digits[i-1]=n;
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
