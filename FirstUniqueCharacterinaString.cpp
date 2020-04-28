class Solution {
public:
    int firstUniqChar(string s) {
        int i;
        unordered_map<char,int> m;
        for(i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(int j=0;j<s.length();j++){
            if(m[s[j]]==1) return j;
        }
        return -1;
    }
};
