class Solution {
public:
    bool checkValidString(string s) {
        /* Space O(2*N);
        Time O(n);
        */
        /*
        stack<int> s1,s2;
        if(s.size()==0) return true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                s1.push(i);
            }
            else if(s[i]=='*'){
                s2.push(i);
            }
            else{
                if(!s1.empty()) s1.pop();
                else if(!s2.empty()) s2.pop();
                else return false;
            }
        }
        while(!s1.empty() and !s2.empty()){
            if(s1.top()>s2.top()) return false;
            s1.pop();
            s2.pop();
        }
        return s1.empty();
        */
        // Space O(1) solution
        int count1=0,count2=0;
        int n=s.size()-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*' || s[i]=='(') count1++;
            else count1--;
            if(s[n-i]=='*' || s[n-i]==')') count2++;
            else count2--;
            if(count1<0 || count2<0) return false;
        }
        return true;
    }
};
