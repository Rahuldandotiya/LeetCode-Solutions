class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int i=0;
        stack<char> st;
        while(i<s.length()){
            if(s[i]=='(') st.push(s[i]);
            else{
                if(!st.empty() and st.top()=='(') st.pop();
                else count++;
            }
            i++;
        }
        count+=st.size();
        return count;
    }
};
