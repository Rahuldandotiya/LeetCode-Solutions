class Solution {
public:
    void Lshift(string &s,int n){
        if(n==0) return;
        else{
            char c=s[0];
            s.erase(s.begin()+0);
            s+=c;
            Lshift(s,n-1);
        }
    }
    void Rshift(string &s,int n){
        if(n==0) return;
        else{
            char c=s[s.size()-1];
            int si=s.size()-1;
            s.erase(s.begin()+si);
            s=c+s;
            Rshift(s,n-1);
        }
    }
    string stringShift(string s, vector<vector<int>>& shift) {
        if(s.size()==0) return s;
        if(shift.size()==0) return s;
        /* brute force
        for(int i=0;i<shift.size();i++){
            if(shift[i][0]==0) Lshift(s,shift[i][1]);
            else Rshift(s,shift[i][1]);
        }
        */
        // optimized
        int tl=0,tr=0;
        for(int i=0;i<shift.size();i++){
            if(shift[i][0]==0) tl+=shift[i][1];
            else tr+=shift[i][1];
        }
        if(tr-tl>0){
            int ts=tr-tl;
            if(ts>s.size()){
                int nts=ts-s.size();
                Rshift(s,nts);
            }
            else Rshift(s,ts);
        }
        else{
            int ts=abs(tr-tl);
            if(ts>s.size()){
                int nts=ts-s.size();
                Lshift(s,nts);
            }
            else Lshift(s,ts);
        }
        return s;
    }
};
