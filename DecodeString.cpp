class Solution {
public:
    string decodeString(string s) {
        string out="";
        stack<int> s1;
        stack<char> s2;
        string n="";
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                string ts="";
                while(s2.top()!='['){
                    ts+=s2.top();
                    s2.pop();
                }
                s2.pop();
                int i=s1.top();
                s1.pop();
                for(i;i>0;i--){
                    for(int j=ts.size()-1;j>=0;j--){
                        s2.push(ts[j]);
                    }
                }
            }
            else{
                if(isdigit(s[i])){
                    n+=s[i];
                }
                else{
                    s2.push(s[i]);
                    if(n!="") s1.push(stoi(n));
                    n.clear();
                }
            }
        }
        while(!s2.empty()){
            out=s2.top()+out;
            s2.pop();
        }
        return out;
    }
};
