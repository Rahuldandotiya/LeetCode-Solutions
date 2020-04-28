class FirstUnique {
public:
    //queue<int> q;
    queue<int> uq;
    unordered_map<int,int> m;
    FirstUnique(vector<int>& nums) {
          for(auto i:nums){
              //q.push(i);
              if(m[i]==0){
                  uq.push(i);
                  m[i]++;
              }
              else{
                  m[i]++;
                  if(i==uq.front()){
                      while(!uq.empty() and m[uq.front()]>1) uq.pop();
                  }
              }
          }
    }
    int showFirstUnique() {
       if(!uq.empty()) return uq.front();
        return -1;
    }
    
    void add(int value) {
        //q.push(value);
        if(m.find(value)==m.end()){
              uq.push(value);
              m[value]++;
          }
          else{
              m[value]++;
              if(value==uq.front()){
                  while(!uq.empty() and m[uq.front()]>1) uq.pop();
              }
          }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
