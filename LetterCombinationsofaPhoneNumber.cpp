class Solution {
public:
    string two(){ return "abc";}
    string three(){ return "def";}
    string four(){ return "ghi";}
    string five(){ return "jkl";}
    string six(){ return "mno";}
    string seven(){ return "pqrs";}
    string eight(){ return "tuv";}
    string nine(){ return "wxyz";}
    void find(vector<string> &ans,vector<string> &v,int idx,string s){
        if(idx==v.size()){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<v[idx].length();i++){
            s+=v[idx][i];
            find(ans,v,idx+1,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string d) {
        vector<string> v;
        if(d.size()==0) return v;
        for(int i=0;i<d.size();i++){
            if(d[i]-'0'==2) v.push_back(two());
            else if(d[i]-'0'==3) v.push_back(three());
            else if(d[i]-'0'==4) v.push_back(four());
            else if(d[i]-'0'==5) v.push_back(five());
            else if(d[i]-'0'==6) v.push_back(six());
            else if(d[i]-'0'==7) v.push_back(seven());
            else if(d[i]-'0'==8) v.push_back(eight());
            else if(d[i]-'0'==9) v.push_back(nine());
        }
        vector<string> ans;
        find(ans,v,0,"");
        return ans;
    }
};
