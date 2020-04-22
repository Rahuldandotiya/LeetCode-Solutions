class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int arr[26]={0};
        int maxx=0;
        int mf=0;
        for(char i:tasks){
            arr[i-'A']++;
            if(arr[i-'A']>maxx){
                maxx=arr[i-'A'];
                mf=1;
            }
            else if(arr[i-'A']==maxx) mf++;
        }
        int idl=(maxx-1)*n;
        idl=idl-(tasks.size()-maxx-(mf-1));
        return tasks.size()+max(0,idl);
    }
};
